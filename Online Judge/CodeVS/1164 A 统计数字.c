# include <stdio.h>
# include <stdlib.h>
/*
题目描述 Description
【问题描述】
某次科研调查时得到了n个自然数，每个数均不超过1500000000（1.5*109）。已知不相同的数
不超过10000 个，现在需要统计这些自然数各自出现的次数，并按照自然数从小到大的顺序输出统
计结果。
*/
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	int n, i, j;
	scanf("%d", &n);
	int num[200001];
	for(i = 0; i < n; ++i)
		scanf("%d", &num[i]);
	qsort(num, n, sizeof(int), cmp);
	for(i = 0; i < n; ++i)
	{
		j = 1;
		while(num[i+j] == num[i+j-1])
			++j;
		printf("%d %d\n", num[i], j);
		i = i + j - 1;
	}

	return 0;
}
/*
输入描述 Input Description
第1行是整数n，表示自然数的个数。
第2~n+1 行每行一个自然数。
输出描述 Output Description
输出包含m行（m为n个自然数中不相同数的个数），按照自然数从小到大
的顺序输出。每行输出两个整数，分别是自然数和该数出现的次数，其间用一个空格隔开。
样例输入 Sample Input
8
2
4
2
4
5
100
2
100
样例输出 Sample Output
2 3
4 2
5 1
100 2
数据范围及提示 Data Size & Hint
【限制】
40%的数据满足：1<=n<=1000
80%的数据满足：1<=n<=50000
100%的数据满足：1<=n<=200000，每个数均不超过1 500 000 000（1.5*10^9）
*/
