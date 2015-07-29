#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
题目描述 Description
若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。 
规定：x和y是亲戚，y和z是亲戚，那么x和z也是亲戚。如果x,y是亲戚，那么x的亲戚都是y的亲戚，y的亲戚也都是x的亲戚。
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
	int n, m, p;
	cin >> n >> m >> p;
	int uset[5001], rank[5001];
	for(int i = 0; i <= 5000; ++i)
	{
		uset[i] = i;
		rank[i] = 0;
	}

	int u, v;

	while(m--)
	{
		scanf("%d %d", &u, &v);
		unionSet(u, v, uset, rank);
	}
	
	while(p--)
	{
		scanf("%d %d", &u, &v);
		if((u = find(u, uset)) == (v = find(v, uset)))
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}
/*
输入描述 Input Description
第一行：三个整数n,m,p，（n<=5000,m<=5000,p<=5000），分别表示有n个人，m个亲戚关系，询问p对亲戚关系。 以下m行：每行两个数Mi，Mj，1<=Mi，
Mj<=N，表示Ai和Bi具有亲戚关系。 接下来p行：每行两个数Pi，Pj，询问Pi和Pj是否具有亲戚关系。
输出描述 Output Description
P行，每行一个’Yes’或’No’。表示第i个询问的答案为“具有”或“不具有”亲戚关系。
样例输入 Sample Input
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6
样例输出 Sample Output
Yes
Yes
No
数据范围及提示 Data Size & Hint
n<=5000,m<=5000,p<=5000
*/