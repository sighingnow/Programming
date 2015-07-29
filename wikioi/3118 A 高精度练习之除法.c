# include <stdio.h>
# include <string.h>
# include <malloc.h>
/*
题目描述 Description
给出两个正整数A和B，计算A/B整数部分的值。保证A和B的位数不超过500位。
*/
int comp(int *x, int *y, int len)  //通过比较判断是否可以相减, 能相减则返回 1
{
	int i;
	for(i = 0; i < len; ++i)
	{
		if(x[i] != y[i])
			break;
	}
	if(i > len || x[i] > y[i])
		return 1;
	else
		return 0;
}

void Sub(int *x, int *y, int len, int flag)        //相减
{
	int i, j;
	for(i = flag, j = len; j >= 1; --i, --j)
	{
		if(x[i] >= y[j])
			x[i] -= y[j];
		else
		{
			x[i] = x[i] + 10 - y[j];
			x[i-1] --;
		}
	}
}
int main()
{
	int x[1001] = {0}, y[501] = {0}, ans[501] = {0}; //index = 0 的位置用其来存长度
	int i, xPosi = 1, xTail;  

	char s[501];
	scanf("%s", s);
	x[0] = strlen(s);
	for(i = 0; i < x[0]; ++i)
		x[i+1] = s[i] - '0';
	scanf("%s", s);
	xTail = y[0] = strlen(s);
	for(i = 0; i < y[0]; ++i)
		y[i+1] = s[i] - '0';

	while(xTail <= x[0])
	{
		if(!comp(x+xPosi, y+1, y[0]))
		{
			xTail ++;
			xPosi ++;
		}
		while((xPosi > 1 && x[xPosi-1]) || comp(x+xPosi, y+1, y[0]))
		{
			Sub(x, y, y[0], xTail);
			++ans[xTail];
		}
	}
	for(i = 1; i < x[0]; ++i)              //输出结果
		if(ans[i])
			break;
	for(; i <= x[0]; ++i)
		printf("%d", ans[i]);

	return 0;
}
/*
输入描述 Input Description
读入两个用空格隔开的正整数
输出描述 Output Description
输出A/B整数部分的值
样例输入 Sample Input
15 4
样例输出 Sample Output
3
数据范围及提示 Data Size & Hint
两个正整数的位数不超过500位
*/
