# include <stdio.h>
# include <string.h>
/*
题目描述 Description
编写一个把整数N分解为质因数乘积的程序。
*/
int main()
{
	long long int n, i = 2, flag = 0;
	scanf("%I64d", &n);
	printf("%I64d=", n);
	while(n != 1)
	{
		while(n % i == 0)
		{
			if(flag != 0)
				printf("*");
			else
			{
				flag = 1;
			}
			printf("%I64d", i);
			n /= i;
		}
		i ++;
	}
	printf("\n");
	return 0;
}

/*
输入描述 Input Description
输入一个整数 N
输出描述 Output Description
输出 分解质因数 。拆成几个质数相乘的形式，质数必须从小到大相乘
样例输入 Sample Input
756
样例输出 Sample Output
756=2*2*3*3*3*7
数据范围及提示 Data Size & Hint
范围在longint内。不是高精度。
*/
