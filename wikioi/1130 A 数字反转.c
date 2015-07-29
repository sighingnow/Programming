# include <stdio.h>
# include <string.h>

/*
题目描述 Description
给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形
式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零.
*/

int main()
{
	char ch[12];
	int len,i,j,k,t;
	scanf("%s",ch);
	len = strlen(ch);
	if(ch[0] == '-')
	{
		printf("-");
		i = len - 1;
		while(ch[i] == '0')
			i--;
		if(i == 0)
			printf("0");
		else
		{
			for(;i > 0; i--)
			printf("%c",ch[i]);
		}
	}
	else
	{
		i = len - 1;
		while(ch[i] == '0' && i>=0)
			i--;
		if(i == 0)
			printf("%c",ch[i]);
		else
		{
			for(;i >= 0; i--)
			printf("%c",ch[i]);
		}
	}
	
	return 0;
}

/*
输入描述 Input Description
输入共 1 行，一个整数N
输出描述 Output Description
输出共 1 行，一个整数，表示反转后的新数。
样例输入 Sample Input
-380
样例输出 Sample Output
-83
数据范围及提示 Data Size & Hint
数据范围
-1,000,000,000 ≤ N≤ 1,000,000,000。
*/
