# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>
# include <string.h>
/*
题目描述 Description
在一个果园里，多多已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。多多决定把所有的果子合成一堆。
每一次合并，多多可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。可以看出，所有的果子经过n-1次合并之后，就只
剩下一堆了。多多在合并果子时总共消耗的体力等于每次合并所耗体力之和。因为还要花大力气把这些果子搬回家，所以多多在合并果
子时要尽可能地节省体力。假定每个果子重量都为1，并且已知果子的种类数和每种果子的数目，你的任务是设计出合并的次序方案，使
多多耗费的体力最少，并输出这个最小的体力耗费值。例如有3种果子，数目依次为1，2，9。可以先将1、2堆合并，新堆数目为3，耗费体力
为3。接着，将新堆与原先的第三堆合并，又得到新的堆，数目为12，耗费体力为12。所以多多总共耗费体力=3+12=15。可以证明15为最小的
体力耗费值。
*/
int heap[100001];
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void swap(int *a, int *b)
{
	int c;
	c = *a, *a = *b, *b = c;
}
void HeapBuild(int i, int n)
{
	int j = 2 * i + 1;
	while(j <= n)
	{
		if(j < n && heap[j] > heap[j+1])
			++j;
		if(heap[j] >= heap[i])
			break;
		swap(&heap[i], &heap[j]);
		i = j, j = j * 2 + 1;
	}
}
int main()
{
	int i, len = 0, s, t, sum;
	scanf("%d", &len);
	for(i = 0; i < len; ++i)
	{
		scanf("%d", &heap[i]);
	}
	qsort(heap, len, sizeof(heap[0]), cmp);
	i = len-1, sum = 0;
	while(i--)
	{
		s = heap[0], heap[0] = heap[--len];
		HeapBuild(0, len-1);
		t = heap[0], heap[0] = s + t;
		HeapBuild(0, len-1);
		sum += (s + t);
	}
	printf("%d", sum);

	return 0;
}

/*
输入描述 Input Description
输入包括两行，第一行是一个整数n(1<＝n<=10000)，表示果子的种类数。第二行包含n个整数，用空格分隔，第i个整数ai(1<＝ai<=20000)
是第i种果子的数目。
输出描述 Output Description
输出包括一行，这一行只包含一个整数，也就是最小的体力耗费值。输入数据保证这个值小于231。
样例输入 Sample Input
3
1 2 9
样例输出 Sample Output
15
数据范围及提示 Data Size & Hint
对于30％的数据，保证有n<=1000： 
对于50％的数据，保证有n<=5000； 
对于全部的数据，保证有n<=10000。
*/
