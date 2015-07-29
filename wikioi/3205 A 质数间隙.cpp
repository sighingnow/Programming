#include <iostream>
#include <cstdio>
using namespace std;
/*
题目描述 Description
两个连续质数p和q的差d，称为一个长度为d的质数间隙。例如23到29之间的质数间隙长度为6。输入正整数n，编程计算包含n的质数间隙长度。
注意，当n为质数时，计算结果为0。
*/
int prime[80000], top;
bool isPrime[1000201];

void init()
{
	for(int i = 2; i <= 500100; ++i)
	{
		if(!isPrime[i])
			for(int k = i + i; k <= 1000200; k += i)
				isPrime[k] = true;
	}
	for(int i = 2; i <= 1000200; ++i)
		if(!isPrime[i])
			prime[top++] = i;
}

int search(int n)
{
	int high = top - 1, low = 0;
	while(high - low > 1)
	{
		if(prime[(low + high) / 2] >= n)
			high = (low + high) / 2;
		else
			low = (low + high) / 2;
	}
	return high;
}

int main(int argc, char *argv[])
{
	init();
	int n, t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int ans = search(n);
		if(n < 2 || n == prime[ans] || n == prime[ans-1])
			printf("0\n");
		else
			printf("%d\n", prime[ans] - prime[ans - 1]);
	}
	return 0; 
}
/*
输入描述 Input Description
第一行是正整数t(≤1000)，表示数据组数；接下来的t行，每行一个正整数n(≤106)。
输出描述 Output Description
对于每个n，输出包含n的质数间隙长度。
样例输入 Sample Input
3
11
27
492170
样例输出 Sample Output
0
6
114
数据范围及提示 Data Size & Hint
没有！
*/
