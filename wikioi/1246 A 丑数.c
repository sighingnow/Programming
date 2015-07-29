#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
题目描述 Description
对于一给定的素数集合 S = {p1, p2, ..., pK}, 
来考虑那些质因数全部属于S 的数的集合。这个集合包括，p1, p1p2, p1p1, 和 p1p2p3 (还有其它)。这是个对于一个输入的S的丑数集合。
注意：我们不认为1 是一个丑数。
你的工作是对于输入的集合S去寻找集合中的第N个丑数。longint(signed 32-bit)对于程序是足够的。
*/
long long int heap[100000000];

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void HeapBuild(int i, int len)
{
	int j = 2 * i + 1;
	while(j <= len)
	{
		if(j < len && heap[j] > heap[j+1])
			++j;
		if(heap[i] <= heap[j])
			break;
		swap(heap[i], heap[j]);
		i = j, j = 2 * i + 1;
	}
}
int main()
{
	int k, n, i, j, len;
	long long int temp, flag = 0;
	int prime[120];

	cin >> k >> n;
	for(i = 0; i < k; ++i)
		cin >> prime[i];
	qsort(prime, k, sizeof(int), cmp);

	len = k;

	for(i = 0; i < k; ++i)
		heap[i] = prime[i];
	
	flag = 1;

	if(k == 1)
	{
		for(i = 1; i <= n; ++i)
			flag *= heap[0];
		cout << flag << endl;
		return 0;
	}

	while(n)
	{
		if(heap[0] != flag)   //注意去重
		{
			
			flag = heap[0];
			n--;

			heap[0] *= prime[0];
			HeapBuild(0, len-1);

			for(i = 1; i < k; ++i)
			{
				temp = flag * prime[i];
				j = len++;
				while(j > 0 && temp < heap[(j-1)/2])
				{
					heap[j] = heap[(j-1)/2];
					j = (j - 1) >> 1;
				}
				heap[j] = temp;
			}
		}
		else
		{
			heap[0] = heap[--len];
			HeapBuild(0, len-1);
		}
	}
	cout << flag << endl;

	return 0;
}

/*
输入描述 Input Description
第 1 行: 二个被空间分开的整数:K 和 N ， 1<= K<=100 ， 1<= N<=100,000. 
第 2 行: K 个被空间分开的整数:集合S的元素
输出描述 Output Description
单独的一行，写上对于输入的S的第N个丑数。
样例输入 Sample Input
4 19
2 3 5 7
样例输出 Sample Output
27
数据范围及提示 Data Size & Hint
*/
