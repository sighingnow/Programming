# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
/*
题目描述 Description
给定一个长度为N(0<n<=10000)的序列，保证每一个序列中的数字a[i]是小于maxlongint的非负整数 ，编程要求求出整个序列中第k大的数字减去
第k小的数字的值m，并判断m是否为质数。(0<k<=n)
*/
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int ispri(int a)
{
	int k, i;
	if(a == 1 || a ==0)
		return 0;
	k = sqrt(a);
	for(i = 2; i <= k; i++)
	{
		if(i * i == a)
			break;
	}
	if(i <= k)
		return 0;
	else
		return 1;
}
int main()
{
	int n, k, i;
	scanf("%d %d", &n, &k);
	int f[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d", &f[i]);
	}
	qsort(f, n, sizeof(f[0]), cmp);
	if(k > n / 2)          //这种情况下二者差为负数
	{
		printf("NO\n");
		printf("%d\n", f[n-k] - f[k-1]);
		return 0;
	}
	if(ispri(f[n-k] - f[k-1]) == 1)
		printf("YES\n");
	else
		printf("NO\n");
	printf("%d\n", f[n-k] - f[k-1]);

	return 0;
}

/*
输入描述 Input Description
第一行为2个数n，k（含义如上题）
第二行为n个数，表示这个序列
输出描述 Output Description
如果m为质数则
第一行为'YES'(没有引号）
第二行为这个数m
否则 
第一行为'NO'
第二行为这个数m
样例输入 Sample Input
5 2
1 2 3 4 5
样例输出 Sample Output
YES
2
数据范围及提示 Data Size & Hint
20%数据满足0<n<=10
50%数据满足0<n<=5000
100%数据满足0<n<=10000
*/
