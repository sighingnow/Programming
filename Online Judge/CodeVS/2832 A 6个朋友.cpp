#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
题目描述 Description
有这么一种说法：认识6个人，你就认识全世界的人。
Aiden现在有一张关系图，上面记载了N个人之间相互认识的情况。Aiden想知道，他能否只认识6个人就能间接认识这N个人呢？
*/
struct Relation
{
	int rank;
	int root;
	int count;
}uset[100001];

int find(int x)
{
	if(x != uset[x].root)
		uset[x].root = find(uset[x].root);
	return uset[x].root;
}

void unionSet(int x, int y)
{
	if((x = find(x)) == (y = find(y)))
		return;
	if(uset[x].rank > uset[y].rank)
	{
		uset[y].root = x;
		uset[x].count += uset[y].count;
	}
	else
	{
		uset[x].root = y;
		uset[y].count += uset[x].count;
	}
	if(uset[x].rank == uset[y].rank)
		uset[y].rank++;
}

int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main(int argc, char **argv)
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i <= 100000; ++i)
	{
		uset[i].root = i;
		uset[i].rank = 0;
		uset[i].count = 1;
	}
	int u, v;
	while(m--)
	{
		scanf("%d %d", &u, &v);
		unionSet(u, v);
	}
	
	int ans[100001], top = 1, sum = 0;
	for(int i = 1; i <= n; ++i)
	{
		if(uset[i].root == i)
			ans[top++] = uset[i].count;
	}
	if(top <= 7)
		cout << "^_^";
	else
	{
		qsort(ans + 1, n, sizeof(ans[0]), cmp);
		for(int i = 1; i <= 6; ++i)
			sum += ans[i];
		cout << "T_T" << endl << sum;
	}
	
	return 0;
}
/*
输入描述 Input Description
第一行，两个数N，M，表示有N个人，M对认识关系。
接下来的M行，每行两个数ai，bi，表示ai与bi相互认识。
不保证认识关系不出现重复，保证ai≠bi。
N个人的编号为1...N。
输出描述 Output Description
若只认识6个人就能间接认识这N个人，则输出“^_^”。
若不行，则第一行输出“T_T”，第二行输出认识6个人最多能间接认识的人的个数。
输出不包括引号。
样例输入 Sample Input
6 7
1 2
1 3
2 4
3 5
4 6
5 6
3 2
样例输出 Sample Output
^_^
数据范围及提示 Data Size & Hint
对于30%的数据，保证0＜n≤1000。
对于50%的数据，保证0＜n≤5000。
对于100%的数据，保证0＜n≤10000，m≤10*n。
*/