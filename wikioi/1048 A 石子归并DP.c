# include <stdio.h>
# include <string.h>
/*
题目描述 Description
有n堆石子排成一列，每堆石子有一个重量w[i], 每次合并可以合并相邻的两堆石子，一次合并的代价为两堆石子的重量和w[i]+w[i+1]。
问安排怎样的合并顺序，能够使得总合并代价达到最小。
*/
int main()   //DP
{
	int n, i, j, k, len;
	scanf("%d", &n);
	int sum[n+1], stone[n+1], dp[n+1][n+1], min, tmp;
	*sum = 0;
	memset(dp, 0, sizeof(dp));
	for(i = 1; i <= n; ++i)
	{
		scanf("%d", &stone[i]);
		sum[i] = sum[i-1] + stone[i];
	}
	for(len = 2; len <= n; ++len)   //len是已经归并的石子数量
	{
		for(i = 1; i <= n - len + 1; ++i)
		{
			j = i + len - 1, min = 0x7fffffff;
			for(k = i; k < j; ++k)
			{
				tmp = dp[i][k] + dp[k+1][j] + (sum[j] - sum[i-1]);
				min = min < tmp ? min : tmp;
			}
			dp[i][j] = min;
		}
	}
	printf("%d\n", dp[1][n]);

	return 0;
}

/*
输入描述 Input Description
第一行一个整数n（n<=100）
第二行n个整数w1,w2...wn  (wi <= 100)
输出描述 Output Description
一个整数表示最小合并代价
样例输入 Sample Input
4
4 1 1 4
样例输出 Sample Output
18
数据范围及提示 Data Size & Hint
*/
