# include <stdio.h>
# include <string.h>
# include <stdlib.h>
/*
题目描述 Description
给定n(1<=n<=100)个数,从中找出尽可能多的数使得他们能够组成一个等差数列.求最长的等差数列的长度.
*/
int s[100];
int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()                      //算法：枚举
{
	int n, i, j, delta, t, p, max = 0, k;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
	}
	qsort(s, n, sizeof(int), comp);
	if(n == 1)
	{
		printf("1\n");
		return 0;
	}
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			delta = s[j] - s[i], t = 2, p = j + 1, k = s[j];
			if(delta == 0)         //公差为零时特判
			{
				while(p++ < n && s[p-1] == s[i])
					t++;
			}
			else
			{
				while(p++ < n)
				{
					if(s[p-1] - k == delta)          //注意等差数列的判断
					{
						k = s[p-1];
						t ++;
					}
				}
			}
			max = max >= t ? max : t;
		}
	}
	printf("%d\n", max);

	return 0;
}

/*
输入描述 Input Description
第一行是一个整数n,接下来一行包括了n个数,每个数的绝对值不超过10000000.
输出描述 Output Description
对于每个输入数据,输出你所找出的最长等差数列的长度
样例输入 Sample Input
7
3
8
4
5
6
2
2
样例输出 Sample Output
5
数据范围及提示 Data Size & Hint
*/
