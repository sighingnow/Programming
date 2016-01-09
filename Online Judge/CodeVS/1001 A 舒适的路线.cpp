#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
/*
题目描述 Description
Z小镇是一个景色宜人的地方，吸引来自各地的观光客来此旅游观光。
Z小镇附近共有N(1<N≤500)个景点（编号为1,2,3,…,N），这些景点被M（0<M≤5000）条道路连接着，所有道路都是双向的，两个景点之间可能有多条道
路。也许是为了保护该地的旅游资源，Z小镇有个奇怪的规定，就是对于一条给定的公路Ri，任何在该公路上行驶的车辆速度必须为Vi。频繁的改变
速度使得游客们很不舒服，因此大家从一个景点前往另一个景点的时候，都希望选择行使过程中最大速度和最小速度的比尽可能小的路线，
也就是所谓最舒适的路线。
*/
int find(int x, int *uset)
{
	if(x != uset[x])
		uset[x] = find(uset[x], uset);
	return uset[x];
}

void usetUnion(int x, int y, int *uset, int *rank)
{
	if((x = find(x, uset)) == (y = find(y, uset)))
		return;
	if(rank[x] > rank[y])
		uset[y] = x;
	else
		uset[x] = y;
	if(rank[x] == rank[y])
		rank[y]++;
}

struct Map
{
	int u, v;
	int len;
} arc[5005];

int cmp(const void *a, const void *b)
{
	return ((struct Map *)a)->len - ((struct Map *)b)->len;
}

void initUset(int *uset, int n, int *rank)
{
	memset(rank, 0, sizeof(rank));
	for(int i = 1; i <= n; ++i)
		uset[i] = i;
}

int gcd(int s, int t)
{
	if(s % t==0)
		return t;
	else
		return gcd(t, s % t);
}

int main(int argc, char **argv)
{
	int n, m, s, t;
	int uset[505], rank[505];
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
		scanf("%d %d %d", &arc[i].u, &arc[i].v, &arc[i].len);
	cin >> s >> t;

	qsort(arc + 1, m, sizeof(arc[0]), cmp);
	
	int min = 0, max = 0, x, y;
	bool islink = false;
	for(int k = 1; k <= m; ++k)
	{
		int i;
		initUset(uset, n, rank);
		for(i = k; i <= m; ++i)
		{
			x = arc[i].u, y = arc[i].v;
			if((x = find(x, uset)) != (y = find(y, uset)))
				usetUnion(x, y, uset, rank);
			if(find(s, uset) == find(t, uset))
			{
				islink = true;
				break;
			}
		}
		if(find(s, uset) == find(t, uset))
		{
			if(min == 0 || ((float)arc[i].len / arc[k].len < (float)max / min))
				min = arc[k].len, max = arc[i].len;
		}
		else
			break;
	}
	if(!islink)
		printf("IMPOSSIBLE");
	else
	{
		int Gcd = gcd(max, min);
		max /= Gcd;
		min /= Gcd;
		if(min == 1)
			cout << max;
		else
			printf("%d/%d", max, min);
	}
	
	return 0;
}
/*
输入描述 Input Description
第一行包含两个正整数，N和M。
接下来的M行每行包含三个正整数：x，y和v（1≤x,y≤N，0 最后一行包含两个正整数s，t，表示想知道从景点s到景点t最大最小速度比最小的路径。s和t不可能相同。
输出描述 Output Description
如果景点s到景点t没有路径，输出“IMPOSSIBLE”。否则输出一个数，表示最小的速度比。如果需要，输出一个既约分数。
样例输入 Sample Input
样例1
4 2
1 2 1
3 4 2
1 4

样例2
3 3
1 2 10
1 2 5
2 3 8
1 3

样例3
3 2
1 2 2
2 3 4
1 3
样例输出 Sample Output
样例1
IMPOSSIBLE
样例2
5/4
样例3
2
数据范围及提示 Data Size & Hint
N(1<N≤500)
M（0<M≤5000）
Vi在int范围内
*/
