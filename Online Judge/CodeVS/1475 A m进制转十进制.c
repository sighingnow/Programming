# include <stdio.h>
# include <math.h>
# include <string.h>
/*
题目描述 Description
将m进制数n转化成一个十进制数 m<=16
题目保证转换后的十进制数<=100
*/
int main()
{
	char s[100];
	int i, n, m, len;
	scanf("%s %d", s, &m);
	n = 0;
	len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			n += (s[i] - '0') * pow(m, (len - 1 - i));
		}
		else
		{
			n += (10 + s[i] - 'A') * pow(m, (len - 1 - i));
		}
	}
	printf("%d\n", n);

	return 0;
}

/*
输入描述 Input Description
共一行
n和m
输出描述 Output Description
共一个数
表示m进制的n化成十进制的数
样例输入 Sample Input
1010 2
样例输出 Sample Output
10
数据范围及提示 Data Size & Hint
*/
