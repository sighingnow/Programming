# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include <string.h>
/*
题目描述 Description
有两个长度为 N 的序列 A 和 B，在 A 和 B 中各任取一个数可以得到 N^2 个和，求这N^2 个和中最小的 N个。
*/
/*题解
读入A，B两组中的所有数后，我们可以建立这样一个有序表：
A1+B1<A2+B1<A3+B1<...<AN+B1
A1+B2<A2+B2<A3+B2<...<AN+B2
...
A1+BN<A2+BN<A3+BN<...<AN+AN
我们将这个有序表的每一行的第一个数字（记作s）连同A,B的下标0推入优先队列，这样我们每一次取出队列中的队首，显然这个元素的s是
最小的，输出。与此同时，我们需要延续这个有序表。在取出的结构体中，令其标号a加1，b的标号不变，那么，s=B[b]+A[a]。
*/
int x[100001], y[100001];
struct Heap
{
	int sum, s, t;
} heap[150000], tmp;
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void HeapBuild(int i, int n)
{
	int k = i, j = 2 * i + 1;
	while(j <= n)
	{
		if(j < n && heap[j].sum > heap[j+1].sum)
			++j;
		if(heap[j].sum >= heap[k].sum)
			break;
		tmp = heap[j], heap[j] = heap[k], heap[k] = tmp;
		k = j, j = j * 2 + 1;
	}
}
int main()
{
	int i, len = 0;
	scanf("%d", &len);
	for(i = 0; i < len; ++i)
	{
		scanf("%d", &x[i]);
	}
	for(i = 0; i < len; i++)
	{
		scanf("%d", &y[i]);
	}
	qsort(x, len, sizeof(x[0]), cmp);
	qsort(y, len, sizeof(y[0]), cmp);
	for(i = 0; i < len; i++)
	{
		heap[i].sum = x[0] + y[i];
		heap[i].s = 0;
		heap[i].t = i;
	}
	i = len;
	while(i--)
	{
		printf("%d ", heap[0].sum);
		heap[0].s = heap[0].s + 1, heap[0].sum = x[heap[0].s] + y[heap[0].t];
		HeapBuild(0, len-1);
	}

	return 0;
}

/*
输入描述 Input Description
第一行输入一个正整数N；第二行N个整数Ai 且Ai≤10^9；第三行N个整数Bi，
且Bi≤10^9
输出描述 Output Description
输出仅一行，包含 n 个整数，从小到大输出这 N个最小的和，相邻数字之间用
空格隔开。
样例输入 Sample Input
5
1 3 2 4 5 
6 3 4 1 7
样例输出 Sample Output
2 3 4 4 5
数据范围及提示 Data Size & Hint
【数据规模】 对于 100%的数据，满足 1≤N≤100000。
*/
