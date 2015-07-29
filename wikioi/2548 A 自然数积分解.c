# include <stdio.h>
# include <math.h>
/*
题目描述 Description
把自然数Ｎ分解为若干个自然数之积，输出方案数。
*/
int ans;
void dfs(int n, int m)
{
	++ans;
	int k = sqrt(n);
	int i;
	for(i = m; i <= k; ++i)
	{
		if(n % i == 0)
		{
			dfs(n/i, i);
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	dfs(n, 2);
	printf("%d", ans);

	return 0;
}
/*
输入描述 Input Description
自然数N,（1≤n≤2000000000）
输出描述 Output Description
方案数
样例输入 Sample Input
20
样例输出 Sample Output
4
数据范围及提示 Data Size & Hint
20 可分为
20 
4 5
2 10
2 2 5
*/
