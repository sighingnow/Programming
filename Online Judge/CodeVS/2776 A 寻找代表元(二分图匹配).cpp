#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
/*
题目描述 Description
广州二中苏元实验学校一共有n个社团，分别用1到n编号。
广州二中苏元实验学校一共有m个人，分别用1到m编号。每个人可以参加一个或多个社团，也可以不参加任何社团。
每个社团都需要选一个代表。谦哥希望更多的人能够成为代表。
*/
bool dfs(int t, int m, bool *isVisit, int *link, bool map[][201])//dfs算法寻找增广路径
{
	for(int i = 1; i <= m; ++i)
	{
		if(!isVisit[i] && map[t][i])
		{
			isVisit[i] = true;
			if(link[i] == -1 || dfs(link[i], m, isVisit, link, map))
			{
				link[i] = t;
				return true;
			}
		}
	}
	return false;
}
int Hungarian(int n, int m, bool map[][201])
{
	bool isVisit[m+1];
	int link[m+1], ans = 0;
	memset(link, 0xff, sizeof(link));
	for(int i = 1; i <= n; ++i)
	{
		memset(isVisit, 0, sizeof(isVisit));//注意!易遗漏（这道题是从 X 到 Y 的匹配）
		if(dfs(i, m, isVisit, link, map))
			++ans;
	}
	return ans;
}
int main()//Hungarian算法，max_match
{
	bool map[201][201] = {{false}};
	int n, m, ans;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	{
		int tmp;
		while(1)
		{
			scanf("%d", &tmp);
			if(tmp == 0)
				break;
			map[i][tmp] = true;
		}
	}
	ans = Hungarian(n, m, map);
	cout << ans << endl;

	return 0;
}

/*
输入描述 Input Description
第一行输入两个数n和m。
以下n行每行若干个数，这些数都是不超过m的正整数。其中第i行的数表示社团i的全部成员。每行用一个0结束。
输出描述 Output Description
输出最多的能够成为代表的人数。
样例输入 Sample Input
4 4
1 2 0
1 2 0
1 2 0
1 2 3 4 0
样例输出 Sample Output
3
数据范围及提示 Data Size & Hint
各个测试点1s
数据范围
n,m<=200
*/
