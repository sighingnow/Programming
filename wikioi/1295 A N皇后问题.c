# include <stdio.h>
# include <string.h>
/*
题目描述 Description
在n×n格的棋盘上放置彼此不受攻击的n个皇后。按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。n皇
后问题等价于在n×n的棋盘上放置n个皇后，任何2个皇后不妨在同一行或同一列或同一斜线上。
*/
int buf[15], flag[15], sum[15], mark1, mark2, mark;
int n, t;
void queen(int m)
{
	int i, j;
	if(m > n)
	{
		t++;
	}
	else
	{
		for(i = 1; i <= n; i++)
		{
			buf[m] = i;
			if(flag[i] == 0)
			{
				mark1 = buf[m] - m, mark2 = buf[m] + m;
				for(j = 1; j < m; j++)
				{
					if(m != 1)
					{
						if(buf[j] - j == mark1 || buf[j] + j == mark2)
							break;
					}
				}
				if(j >= m)
				{
					flag[i] = 1;
					queen(m+1);
					flag[i] = 0;
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	queen(1);
	printf("%d\n", t);

	return 0;
}

/*
输入描述 Input Description 给定棋盘的大小n (n ≤ 13)
输出描述 Output Description
输出整数表示有多少种放置方法。 样例输入 Sample Input
8
样例输出 Sample Output
92
数据范围及提示 Data Size & Hint
n<=13
（时限提高了，不用打表了）
*/
