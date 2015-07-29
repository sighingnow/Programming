#include <iostream>
using namespace std;
/*
题目描述 Description
如图所示的数字三角形，从顶部出发，在每一结点可以选择向左走或得向右走，一直走到底层，要求找出一条路径，使路径上的值
最大。
*/
int main(int argc, char **argv)
{
	int n;
	cin >> n;
	int num[105][105];
	int dp[105][105];
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= i; ++j)
			cin >> num[i][j];
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= i; ++j)
		{
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + num[i][j];
		}
	}
	int ans = -0x3fffffff;
	for(int i = 1; i <= n; ++i)
	{
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
	return 0;
}

/*
输入描述 Input Description
第一行是数塔层数N(1<=N<=100)。
第二行起，按数塔图形，有一个或多个的整数，表示该层节点的值，共有N行。
输出描述 Output Description
输出最大值。
样例输入 Sample Input
5
13
11 8
12 7 26
6 14 15 8
12 7 13 24 11
样例输出 Sample Output
86
数据范围及提示 Data Size & Hint
 数字三角形
*/
