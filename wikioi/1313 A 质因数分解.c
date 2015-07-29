//filename:
# include <stdio.h>

/*
题目描述 Description
已知正整数 n是两个不同的质数的乘积，试求出较大的那个质数 。
输入描述 Input Description
输入只有一行，包含一个正整数 n。
输出描述 Output Description
输出只有一行，包含一个正整数p，即较大的那个质数。
*/

int main()
{
	int i, n;
	scanf("%d", &n);
	for(i = 2; i < n; i++)
	{
		if(n % i == 0)
		{
			printf("%d", n / i);
			break;
		}
	}
	
	return 0;
}

/*
样例输入 Sample Input
21
样例输出 Sample Output
7
数据范围及提示 Data Size & Hint
【数据范围】
对于60%的数据，6≤n≤1000。
对于100%的数据，6≤n≤2*109。
*/
