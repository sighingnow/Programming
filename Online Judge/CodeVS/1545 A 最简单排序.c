# include <stdio.h>
# include <stdlib.h>
/*
题目描述 Description
实现从小到大排序。
*/

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int num[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	qsort(num, n, sizeof(int), cmp);
	for(i = 0; i < n; i++)
	{
		printf("%d\n", num[i]);
	}

	return 0;
}

/*
输入描述 Input Description
第一行一个整数n
第二行：n个整数，每个用空隔隔开。
输出描述 Output Description
从小到大依次数据，每行一个，共n行。
样例输入 Sample Input
6
1
2
5
4
3
2
样例输出 Sample Output
1
2
2
3
4
5
数据范围及提示 Data Size & Hint
最简单的排序，供初学者练习，不要想太复杂。
n <= 12
*/
