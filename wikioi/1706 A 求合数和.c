# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description
用户输入一个数，然后输出从1开始一直到这个数为止（包括这个数）中所有的合数的和。
*/
int ispri(int n)
{
	int i, k;
	k = sqrt(n);
	for(i = 2; i <= k; i++)
	{
		if(n % i == 0)
			break;
	}
	if(i > k)
		return 1;
	else
		return 0;
}
int main()
{
	int n, i, sum = 0;
	scanf("%d", &n);
	if(n == 1)
		printf("0\n");
	else
	{
		for(i = 3; i <= n; i++)
			if(ispri(i) == 0)
			sum += i;
		printf("%d\n", sum);
	}

	return 0;
}

/*
输入描述 Input Description
一个整数N，0<N<=1000
输出描述 Output Description
一行，一个整数，即从1到N中所有合数的和
样例输入 Sample Input
样例一：100
样例二：9
样例输出 Sample Output
样例一：3989
样例二：27
数据范围及提示 Data Size & Hint
先找出素数，然后把不是素数的和相加。
*/
