#include <stdio.h>
/*
题目描述 Description
在“1250 Fibonacci数列”中，我们求出了第n个Fibonacci数列的值。但是1250中，n<=10^9。现在，你的任务仍然是求出第n个Fibonacci数列的值，
但是注意：n为整数，且1 <= n <= 100000000000000
*/
void multi(long long int n, long long int m[][2], long long int tem[][2])
{
	long long int ret[2][2] = {{m[0][0], m[0][1]}, {m[1][0], m[1][1]}};
	long long int tmp[2][2];
	tem[0][0] = tem[1][1] = 1;
	tem[0][1] = tem[1][0] = 0;
	while(n)
	{
		if(n & 1)
		{
			tmp[0][0] = tem[0][0] * ret[0][0] + tem[0][1] * ret[1][0];
			tmp[0][1] = tem[0][0] * ret[0][1] + tem[0][1] * ret[1][1];
			tmp[1][0] = tem[1][0] * ret[0][0] + tem[1][1] * ret[1][0]; 
			tmp[1][1] = tem[1][0] * ret[0][1] + tem[1][1] * ret[1][1];
			tem[0][0] = tmp[0][0] % 1000000007;
			tem[0][1] = tmp[0][1] % 1000000007;
			tem[1][0] = tmp[1][0] % 1000000007;
			tem[1][1] = tmp[1][1] % 1000000007;
		}
		tmp[0][0] = ret[0][0] * ret[0][0] + ret[0][1] * ret[1][0];
		tmp[0][1] = ret[0][0] * ret[0][1] + ret[0][1] * ret[1][1];
		tmp[1][0] = ret[1][0] * ret[0][0] + ret[1][1] * ret[1][0]; 
		tmp[1][1] = ret[1][0] * ret[0][1] + ret[1][1] * ret[1][1];
		ret[0][0] = tmp[0][0] % 1000000007;
		ret[0][1] = tmp[0][1] % 1000000007;
		ret[1][0] = tmp[1][0] % 1000000007;
		ret[1][1] = tmp[1][1] % 1000000007;
		n >>= 1;
	}
}

int main(int argc, char **argv)
{
	long long int n;
	long long ans[2][2];
	long long matrix[2][2];
	while(scanf("%lld", &n) == 1)
	{
		matrix[0][0] = 0;
		matrix[0][1] = matrix[1][0] = matrix[1][1] = 1;
		multi(n, matrix, ans);
		printf("%lld\n", ans[0][1] % 1000000007);
	}

	return 0;
}

/*
输入描述 Input Description
输入有多组数据，每组数据占一行，为一个整数n(1 <= n <= 100000000000000)
输出描述 Output Description
输出若干行。每行输出第（对应的输入的）n个Fibonacci数（考虑到数会很大，mod 10 0000 0007）
样例输入 Sample Input
3
4
5
样例输出 Sample Output
2
3
5
数据范围及提示 Data Size & Hint
1 <= n <= 100000000000000
*/
