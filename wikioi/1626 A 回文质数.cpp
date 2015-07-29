#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
/*
题目描述 Description
因为 151 既是一个质数又是一个回文数(从左到右和从右到左是看一样的),所以 151 是回文质数.
写一个程序来找出范围[a,b](5<=a<b<=100,000,000)间的所有回文质数;
因为 151 既是一个质数又是一个回文数(从左到右和从右到左是看一样的),所以 151 是回文质数.写一个程序来找出范围[a,b]
(5<=a<b<=100,000,000)间的所有回文质数;
*/
int prime[800], top;

bool isPrime(int n)
{
	int i, root = (int)sqrt(n);
	for(i = 2; i <= root; ++i)
	{
		if(n % i == 0)
			break;
	}
	if(i <= root)
		return false;
	else
		return true;
}

int num[9];

void dfs(int m, int n)
{
	if(m > (n >> 1) + 1)
	{
		int ans = 0;
		for(int i = 1; i <= n; ++i)
			ans = ans * 10 + num[i];
		if(isPrime(ans) && ans > prime[top-1])
			prime[top++] = ans;
	}
	else
	{
		for(int i = 0; i <= 9; i ++)
		{
			if(!(i % 2) && m == 1)
				continue;
			num[n + 1 - m] = num[m] = i;
			dfs(m+1, n);
		}
	}
}

int main(int argc, char *argv[])
{
	int a, b, i;
	cin >> a >> b;
	for(int i = 1; i < 9; ++i)
		dfs(1, i);
	i = 0;
	while(prime[i] < a)
		++i;
	while(i < top && prime[i] <= b)
	{
		printf("%d\n", prime[i]);
		++i;
	}

	return 0;
}
/*
输入描述 Input Description
*Line 1: a,b
输出描述 Output Description
a与b之间（含）的所有回文质数
一行一个
样例输入 Sample Input
5 500
样例输出 Sample Output
5
7
11
101
131
151
181
191
313
353
373
383
数据范围及提示 Data Size & Hint
*/