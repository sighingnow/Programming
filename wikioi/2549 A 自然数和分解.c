# include <stdio.h>
# include <string.h>
/*
题目描述 Description
把自然数Ｎ分解为若干个自然数之和，输出方案数。
*/
int main()  //DP
{
	int n, i, j, ans = 0;
	scanf("%d", &n);
	int dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			if(i >= j)
				dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
	for(i = 1; i <= n; ++i)
		ans += dp[n][i];
	printf("%d", ans);

	return 0;
}
/*
输入描述 Input Description
N,（1≤n≤50）
输出描述 Output Description
方案数
样例输入 Sample Input
5
样例输出 Sample Output
7
数据范围及提示 Data Size & Hint
5 可分为
1 1 1 1 1
1 1 1 2
1 1 3
1 2 2
1 4
2 3
5 
*/
