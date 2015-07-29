#include <iostream>
using namespace std;
/*
题目描述 Description
将整数n分成k份，且每份不能为空，任意两种划分方案不能相同(不考虑顺序)。
例如：n=7，k=3，下面三种划分方案被认为是相同的。
1 1 5
1 5 1
5 1 1
问有多少种不同的分法。
*/
int main(int argc, char **argv)
{
	int n, k;
	int dp[205][10] = {1};
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= k; ++j)
		{
			if(i >= j)
				dp[i][j] = dp[i-j][j] + dp[i-1][j-1];
		}
	}
	cout << dp[n][k];
	return 0;
}
/*
输入描述 Input Description
输入：n，k (6<n<=200，2<=k<=6)
输出描述 Output Description
输出：一个整数，即不同的分法。
样例输入 Sample Input
7 3
样例输出 Sample Output
4
数据范围及提示 Data Size & Hint
 {四种分法为：1，1，5;1，2，4;1，3，3;2，2，3;}
*/
