#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
题目描述 Description		1231 最优布线问题
学校需要将n台计算机连接起来，不同的2台计算机之间的连接费用可能是不同的。为了节省费用，我们考虑采用间接数据传输结束，就是一
台计算机可以间接地通过其他计算机实现和另外一台计算机连接。为了使得任意两台计算机之间都是连通的（不管是直接还是间接的），需
要在若干台计算机之间用网线直接连接，现在想使得总的连接费用最省，让你编程计算这个最小的费用。
*/
struct map//存边
{
	int len;
	int v, u;
};
int cmp(const void *a, const void *b)//用于qsort函数对边排序
{
	return ((struct map *)a)->len - ((struct map *)b)->len;
}

int findSet(int x, int *uset)//非递归版本的并查集findSet函数
{
	int p = x, t;
	while(p != uset[p])
	{
		p = uset[p];
	}
	while(x != p)
	{
		t = uset[x];
		uset[x] = p;
		x = t;
	}
	return x;
}
/*findSet()的递归版本
int findSet(int x, int *uset)
{
	if(x != uset[x])
		uset[x] = findSet(uset[x], uset);
	return uset[x];
}*/

void unionSet(int x, int y, int *uset, int *rank)//并查集合并函数
{
	if((x = findSet(x, uset)) == (y = findSet(y, uset)))
		return;
	if(rank[x] > rank[y])
		uset[y] = x;
	else
		uset[x] = y;
	if(rank[x] == rank[y])
		++rank[y];
}

int main()		//Kruskal 算法 + 并查集
{
	int uset[100001], rank[100001] = {0};
	int n, m;
	struct map arc[100001];
	cin >> n >> m;
	for(int i = 0; i <= n; ++i)
	{
		uset[i] = i;
	}
	memset(arc, 0, sizeof(arc));
	int tmp1, tmp2;
	for(int i = 1; i <= m; ++i)
	{
		scanf("%d %d %d", &tmp1, &tmp2, &arc[i].len);//由于kruskal算法的特点，不用考虑重边的影响
		arc[i].v = tmp1, arc[i].u = tmp2;
	}
	qsort(arc+1, m, sizeof(arc[0]), cmp);

	long long ans = 0;
	for(int i = 1; i <= m; ++i)
	{
		if(findSet(arc[i].v, uset) != findSet(arc[i].u, uset))
		{
			ans += arc[i].len;
			unionSet(arc[i].v, arc[i].u, uset, rank);
		}
	}
	cout << ans;

	return 0;
}
/*
输入描述 Input Description
输入第一行为两个整数n,m（2<=n<=100000，2<=m<=100000），表示计算机总数，和可以互相建立连接的连接个数。接下来m行，每行三个整数
a,b,c 表示在机器a和机器b之间建立连接的话费是c。(题目保证一定存在可行的连通方案, 数据中可能存在权值不一样的重边，但是保证
没有自环)
输出描述 Output Description
输出只有一行一个整数，表示最省的总连接费用。
样例输入 Sample Input
3 3
1 2 1
1 3 2
2 3 1
样例输出 Sample Output
2
数据范围及提示 Data Size & Hint
最终答案需要用long long类型来保存
*/
