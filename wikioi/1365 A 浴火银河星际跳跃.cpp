#include <iostream>
#include <cstdio>
#define read(x) {char ch;\
	            x=0;\
                while((ch=getchar())>'9'||ch<'0');\
                x=ch-'0';\
	            while((ch= getchar())<='9'&&ch>='0')\
					x=x*10+ch-'0';\
	            }

using namespace std;
/*
题目描述 Description
小 K 又在玩浴火银河了。。。不过这次他的目的不是跑运输赚钱，而
是做任务赚钱。
他想知道关于一个任务的两个星系是否可以连通。
*/

int find(int x, int *uset)
{
	if(x != uset[x])
		uset[x] = find(uset[x], uset);
	return uset[x];
}

void unionSet(int x, int y, int *uset, int *rank)
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

int main(int argc, char **argv)
{
	int x, n, m;
	cin >> x >> n >> m;
	int uset[20000], rank[20000] = {0};

	for(int i = 0; i < 20000; ++i)
		uset[i] = i;
	
	int s, t;
	while(n--)
	{
		read(s); read(t);
		unionSet(s, t, uset, rank);
	}
	while(m--)
	{
		read(s); read(t);
		if(find(s, uset) == find(t, uset))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

/*
输入描述 Input Description
第一行，三个数，X,N,M
X 表示出现的星系代号的最大值；
N 表示有 N 个星际跳跃门;
M 表示有 M 个任务。
接下来的 N 行描述每个星际跳跃门：每行为两个数字（星系代号），
星际跳跃门连通这两个星系（星际跳跃门是可以双向通行的）；
接下来的 M 行表示每个任务需要到达的星系，每个任务需要到达两
个星系。
输出描述 Output Description
共 M 行。
第 i 行表示第 i 个任务是否能完成：即两个星系是否能连通。（能→
Yes；不能→No）
样例输入 Sample Input
5 2 1
3 5
4 5
3 4
样例输出 Sample Output
Yes
数据范围及提示 Data Size & Hint
最大数据第一行：19999 17542 1664
*/