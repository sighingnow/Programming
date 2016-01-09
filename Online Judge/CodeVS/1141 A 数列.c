# include <stdio.h>
/*
题目描述 Description  1141 数列
给定一个正整数k(3≤k≤15),把所有k的方幂及所有有限个互不相等的k的方幂之和构成一个递增的序列，例如，当k=3时，这个序列是：
1，3，4，9，10，12，13，…
（该序列实际上就是：3^0，3^1，3^0+3^1，3^2，3^0+3^2，3^1+3^2，3^0+3^1+3^2，…）
请你求出这个序列的第N项的值（用10进制数表示）。
例如，对于k=3，N=100，正确答案应该是981。
*/
void swap(long long int *a, long long int *b)
{
	long long int c;
	c = *a, *a = *b, *b = c;
}
void HeapBuild(long long int *heap, long long int i, long long int len)
{
	long long int j = 2 * i + 1;
	while(j <= len)
	{
		if(j < len && heap[j] > heap[j+1])
			++j;
		if(heap[i] <= heap[j])
			break;
		swap(heap+i, heap+j);
		i = j;
		j = (i << 1) + 1;
	}
}
int main()
{
	long long int k, n, buf[11] = {1}, i, j, heap[1200], len, temp, flag;
	scanf("%lld %lld", &k, &n);
	for(i = 1; i <= 10; ++i)
		buf[i] = buf[i-1] * k;
	for(len = 0; len <= 10; ++len)
		*(heap+len) = *(buf+len);
	flag = 1;
	while(n)
	{
		flag = *heap;
		--n;
		for(i = 1; i <= 10; ++i)
		{
			if(*heap < buf[i])
				break;
		}
		if(i <= 10)
			*heap += *(buf+i);
		HeapBuild(heap, 0, len-1);
		for(i = i + 1;; ++i)
		{
			if(i > 10)
				break;
			if(flag < buf[i])
			{
				temp = flag + buf[i];
				j = len++;
				while(j > 0 && temp < heap[(j-1)/2])
				{
					heap[j] = heap[(j-1)/2];
					j = (j - 1) >> 1;
				}
				heap[j] = temp;
			}
		}
	}
	printf("%lld\n",flag);

	return 0;
}

/*
输入描述 Input Description
只有1行，为2个正整数，用一个空格隔开：
k N（k、N的含义与上述的问题描述一致，且3≤k≤15，10≤N≤1000）
输出描述 Output Description
为计算结果，是一个正整数(可能较大你懂的)。（整数前不要有空格和其他符号）
样例输入 Sample Input
3 100
样例输出 Sample Output
981
数据范围及提示 Data Size & Hint
*/
