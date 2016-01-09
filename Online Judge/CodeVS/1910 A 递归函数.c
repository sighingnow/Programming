# include <stdio.h>
/*
题目描述 Description
对于一个递归函数w(a, b, c)。
如果a <= 0 or b <= 0 or c <= 0就返回值1。
如果a > 20 or b > 20 or c > 20就返回W(20,20,20)。
如果a < b并且b < c 就返回w(a, b, c − 1) + w(a, b − 1, c − 1) − w(a, b − 1, c)，
其它别的情况就返回w(a − 1, b, c) + w(a − 1, b − 1, c) + w(a − 1, b, c − 1) − w(a −1, b - 1, c - 1)
这是个简单的递归函数，但实现起来可能会有些问题。
*/
int flag[21][21][21], s[21][21][21];
int func(int a, int b, int c)
{
	if(a <= 0 || b <= 0 || c <= 0)
		return 1;
	else
	{
		if(a < b && b < c)
		{
			if(flag[a][b][c-1] == 0)
			{
				s[a][b][c-1] = func(a, b, c-1);
				flag[a][b][c-1] = 1;
			}
			if(flag[a][b-1][c-1] == 0)
			{
				s[a][b-1][c-1] = func(a, b-1, c-1);
				flag[a][b-1][c-1] = 1;
			}
			if(flag[a][b-1][c] == 0)
			{
				s[a][b-1][c] = func(a, b-1, c);
				flag[a][b-1][c] = 1;
			}
			return s[a][b][c-1] + s[a][b-1][c-1] - s[a][b-1][c];
		}
		else
		{
			if(flag[a-1][b][c] == 0)
			{
				s[a-1][b][c] = func(a-1, b, c);
				flag[a-1][b][c] = 1;
			}
			if(flag[a-1][b-1][c] == 0)
			{
				s[a-1][b-1][c] = func(a-1, b-1, c);
				flag[a-1][b-1][c] = 1;
			}
			if(flag[a-1][b][c-1] == 0)
			{
				s[a-1][b][c-1] = func(a-1, b, c-1);
				flag[a-1][b][c-1] = 1;
			}
			if(flag[a-1][b-1][c-1] == 0)
			{
				s[a-1][b-1][c-1] = func(a-1, b-1, c-1);
				flag[a-1][b-1][c-1] = 1;
			}
			return s[a-1][b][c] + s[a-1][b-1][c] + s[a-1][b][c-1] - s[a-1][b-1][c-1];
		}
	}
}

int main()
{
	int x, y, z, a, b, c;
	while(1)
	{
		scanf("%d %d %d", &x, & y, &z);
		if(x == -1)
			break;
		else
		{
			if(x > 20 || y > 20 || z > 20)
				a = 20, b = 20, c = 20;
			else
				a = x, b = y, c = z;
			printf("w(%d, %d, %d) = %d\n", x, y, z, func(a, b, c));
		}
	}
	
	return 0;
}

/*
输入描述 Input Description
会有若干行.每行三个数，表示a, b, c。并以−1, −1, −1结束
输出描述 Output Description
输出若干行，注意各种中的空格。
样例输入 Sample Input
1 1 1
2 2 2
-1 -1 -1
样例输出 Sample Output
w(1, 1, 1) = 2
w(2, 2, 2) = 4
数据范围及提示 Data Size & Hint
a, b, c < 30, Task < 11
*/
