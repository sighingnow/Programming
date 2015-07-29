//filename:
# include <stdio.h>
# include <string.h>
/*
题目描述 Description
给出两个正整数A和B，计算A-B的值。保证A和B的位数不超过500位。
*/
int comp(char *a, char *b)
{
	int len1, len2, i;
	len1 = strlen(a), len2 = strlen(b);
	if(len1 > len2)
		return 1;
	if(len1 < len2)
		return 0;
	for(i = 0; i < len1; i++)
	{
		if(a[i] != b[i])
			break;
	}
	if(i == len1)
		return 1;     //若两个数相等，视为第一个大
	else
	{
		if(a[i] > b[i])
			return 1;
		else
			return 0;
	}
}

int main(void)
{
	int i, s, t, max, temp, len1, len2, x[500] = {0}, y[500] = {0}, z[500] = {0};
	char a[501], b[501], c[501];
	scanf("%s %s", a, b);
	int flag = 1;
	if(comp(a, b) == 0)
	{
		flag = 0;
		strcpy(temp, a), strcpy(a, b), strcpy(b, temp);
	}
	len1 = strlen(a) - 1, len2 = strlen(b) - 1;
	max = len1 >= len2 ? len1 : len2;
 	for(i = 0; i <= len1; i++)
	{
		x[len1 - i] = a[i] - '0';
	}
	for(i = 0; i <= len2; i++)
	{
		y[len2 - i] = b[i] - '0';
	}
	for(i = 0; i <= max; i++)
	{
		if(x[i] > y[i])
			z[i] = x[i] - y[i];
		else
		{
			z[i] = x[i] + 10 - y[i];
			x[i+1] --;
		}
	}
	if(flag == 0)
		printf("-");
	for(i = max;i >= 0; i--)
	{
		if(z[i] != 0)
			break;
	}
	if(i < 0)
	{
		printf("0");
	}
	else
	{
		for(; i>=0; i--)
		{
			printf("%d", z[i]);
		}
	}
	
	return 0;
}

/*
输入描述 Input Description
读入两个用空格隔开的正整数
输出描述 Output Description
输出A-B的值
样例输入 Sample Input
3 12
样例输出 Sample Output
-9
数据范围及提示 Data Size & Hint
两个正整数的位数不超过500位
*/
