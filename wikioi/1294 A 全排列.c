# include <stdio.h>
/*
题目描述 Description
给出一个n, 请输出n的所有全排列
输入描述 Input Description
读入仅一个整数n   (1<=n<=10)
输出描述 Output Description
一共n!行，每行n个用空格隔开的数，表示n的一个全排列。并且按全排列的字典序输出。
*/
int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int buf[10];

int pai(int m, int n)             //当作模板背下来
{
	int i, j;
	if(m == n)
	{
		for(i = 0; i < m; i++)
			printf("%d ", buf[i]);
		printf("\n");
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			buf[m] = a[i];
			for(j = 0; j < m; j++)
			{
				if(buf[j] == buf[m])
					break;
			}
			if(j == m)
				pai(m + 1, n);
		}
	}
}

int main(void)
{
	int n;
	scanf("%d", &n);
	pai(0, n);
	
	return 0;
}

/*
样例输入 Sample Input
3
样例输出 Sample Output
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
数据范围及提示 Data Size & Hint
*/
