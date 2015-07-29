# include <stdio.h>
/*
题目描述 Description
小明玩一个数字游戏，取个n行n列数字矩阵（其中n为不超过100的奇数），数字的填补方法为：在矩阵中心从1开始以逆时针方向绕行，
逐圈扩大，直到n行n列填满数字，请输出该n行n列正方形矩阵以及其的对角线数字之和.
*/
int main()
{
	int n;
	scanf("%d", &n);
	int f[n][n];
	int i, t, max, sum;
	max = n * n;
	t = 0;
	while(max > 0)
	{
		for(i = n - 1 - t; i >= t; i--)
		{
			f[n-1-t][i] = max --;
		}
		for(i = n - 1 - t - 1; i >= t; i--)
		{
			f[i][t] = max --;
		}
		for(i = t + 1; i <= n - 1 - t; i++)
		{
			f[t][i] = max --;
		}
		for(i = t + 1; i < n - t - 1; i++)
		{
			f[i][n - t - 1] = max --;
		}
		t ++;
	}
	sum = 0;
	for(i = 0; i < n; i++)    //求和时有两条对角线，并且要减去正中间的元素
	{
		sum += f[i][i];
	}
	for(i = 0; i < n; i++)
	{
		sum += f[i][n-1-i];
	}
	sum -= f[(i+1) / 2 - 1][(i+1) / 2 - 1];
	for(i = 0; i < n; i++)
	{
		for(t = 0; t < n; t++)
		{
			printf("%d ", f[i][t]);
		}
		printf("\n");
	}
	printf("%d\n", sum);

	return 0;
}


/*
输入描述 Input Description
n（即n行n列）
输出描述 Output Description
n+1行，n行为组成的矩阵，最后一行为对角线数字之和
样例输入 Sample Input
3
样例输出 Sample Output
5 4 3
6 1 2
7 8 9
25
*/
