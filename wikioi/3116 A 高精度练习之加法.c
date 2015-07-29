# include <stdio.h>
# include <string.h>
/*
题目描述 Description
给出两个正整数A和B，计算A+B的值。保证A和B的位数不超过500位。
*/
int main()
{
	int x[500] = {0}, y[500] = {0}, z[501] = {0};
	char a[500], b[500];
	int len1, len2, i, s, t, max;
	scanf("%s %s", a, b);
	len1 = strlen(a) - 1, len2 = strlen(b) - 1;
	for(i = 0; i <= len1; i++)
	{
		x[len1 - i] = a[i] - '0';
	}
	for(i = 0; i <= len2; i++)
	{
		y[len2 - i] = b[i] - '0';
	}
	max = len1 >= len2 ? len1 : len2;
	t = 0;
	for(i = 0; i <= max + 1; i++)
	{
		s = x[i] + y[i] + t;
		z[i] = s % 10;
		t = s / 10;
	}
	for(i = 500;; i--)
	{
		if(z[i] != 0)
			break;
	}
	for(; i >= 0; i--)
	{
		printf("%d", z[i]);
	}

	return 0;
}

/*
输入描述 Input Description
读入两个用空格隔开的正整数
输出描述 Output Description
输出A+B的值
样例输入 Sample Input
3 12
样例输出 Sample Output
15
数据范围及提示 Data Size & Hint
两个正整数的位数不超过500位
*/
