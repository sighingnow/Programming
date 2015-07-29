# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description         1462 素数和 
给定2个整数a,b 求出它们之间（不含a，b）所有质数的和。
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
	int a, b, temp, sum = 0;
	scanf("%d %d", &a, &b);
	if(a > b)
		temp = a, a = b, b = temp;
	if(a < b - 1)
	{
		for(temp = a+1; temp < b; temp ++)
			if(ispri(temp) == 1)
				sum += temp;
		printf("%d\n", sum);
	}
	else
		printf("0\n");

	return 0;
}

/*
输入描述 Input Description
一行，a b(0<=a,b<=65536)
输出描述 Output Description
一行，a,b之间（不含a，b）所有素数的和。
样例输入 Sample Input
39 1224
样例输出 Sample Output
111390
数据范围及提示 Data Size & Hint
注意没有要求a<b
*/
