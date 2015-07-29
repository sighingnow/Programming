# include <stdio.h>
/*
题目描述 Description
求两个数A和B的最大公约数。 1<=A,B<=2^31-1
*/
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	if(a > b)
	{
		c = b;
	}
	else
	{
		c = a;
		a = b;
	}
	while(a % c != 0)
	{
		b = c;
		c = a % b;
		a = b;
	}
	printf("%d\n", c);

	return 0;
}

/*
输入描述 Input Description
两个整数A和B
输出描述 Output Description
最大公约数gcd(A,B)
样例输入 Sample Input
8 12
样例输出 Sample Output
4
*/
