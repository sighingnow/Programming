# include <stdio.h>
# include <string.h>
# include <stdlib.h>
/*
题目描述 Description
有这样的一个集合，集合中的元素个数由给定的N决定，集合的元素为N个不同的正整数，一旦集合中的两个数x,y满足y = P*x，那么就认为x,y这两个数
是互斥的，现在想知道给定的一个集合的最大子集满足两两之间不互斥。
*/
/************************************************************************************
*先把读入的数组ai排序 计数器初值为n
*然后从第一个往后扫，发现ai*p也在集合（二分查找）中就删掉它（打个标记），计数器减一
*最后输出~~
*可以证明这是最优的
*************************************************************************************/
int s[100000];
int comp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main(void)
{
	int i, temp, n, p, posi, t;
	scanf("%d %d", &n, &p);
	for(i = 0; i < n; i++)
		scanf("%d", &s[i]);
	qsort(s, n, sizeof(s[0]), comp);
	t = n;
	for(i= 0; i < n; i++)
	{
		if(s[i] > 0)
		{
			temp = s[i] * p;
			posi = (int *)bsearch(&temp, s, n, sizeof(s[0]), comp) - s;
			if(posi > 0)
			{
				s[posi] = 0;
				t--;
			}
		}
	}
	printf("%d\n", t);

	return 0;
}

/*
输入描述 Input Description
输入有多组数据，每组第一行给定两个数N和P（1<=N<=10^5, 1<=P<=10^9）。接下来一行包含N个不同正整数ai（1<=ai<=10^9）。
输出描述 Output Description
输出一行表示最大的满足要求的子集的元素个数。
样例输入 Sample Input
4 2
1 2 3 4
样例输出 Sample Output
3
数据范围及提示 Data Size & Hint
*/
