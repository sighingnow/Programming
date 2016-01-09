# include <stdio.h>
/*
题目描述 Description
给定N(N≤500,000)和N个整数(较有序)，将其排序后输出。
*/
void swap(int *a, int *b)
{
	int c;
	c = *a, *a = *b, *b = c;
}
void BuildHeap(int heap[], int i, int n)
{
	int j = 2 * i + 1;
	while(j <= n)
	{
		if(j < n && heap[j] < heap[j+1])
			++j;
		if(heap[i] > heap[j])
			break;
		swap(heap+i, heap+j);
		i = j, j = (j << 1) + 1;
		
	}
}
int main()
{
	int n, i;
	scanf("%d", &n);
	int heap[n];
	for(i = 0; i < n; ++i)
		scanf("%d", &heap[i]);
	for(i = (n - 1) >> 1; i >= 0; --i)
		BuildHeap(heap, i, n-1);
	for(i = 0; i < n; ++i)
	{
		swap(heap, heap+(n-1-i));
		BuildHeap(heap, 0, n-2-i);
	}
	for(i = 0; i < n; ++i)
		printf("%d ", heap[i]);

	return 0;
}
/*
输入描述 Input Description
N和N个整数
输出描述 Output Description
N个整数(升序)
样例输入 Sample Input
5
12 11 10 8 9
样例输出 Sample Output
8 9 10 11 12
数据范围及提示 Data Size & Hint
对于33%的数据 N≤10000
对于另外33%的数据 N≤100,000  0≤每个数≤1000
对于100%的数据 N≤500,000  0≤每个数≤2*10^9
*/
