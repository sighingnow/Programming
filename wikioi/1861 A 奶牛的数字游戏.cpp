#include <stdio.h>
#define MAX 1000000
/*
题目描述 Description
3n+1问题是一个简单有趣而又没有解决的数学问题。这个问题是由L. Collatz在1937年提出的。克拉兹问题（Collatz problem）也被叫做
hailstone问题、3n+1问题、Hasse算法问题、Kakutani算法问题、Thwaites猜想或者Ulam问题。
问题如下：
（1）输入一个正整数n；
（2）如果n=1则结束；
（3）如果n是奇数，则n变为3n+1，否则n变为n/2；
（4）转入第（2）步。
克拉兹问题的特殊之处在于：尽管很容易将这个问题讲清楚，但直到今天仍不能保证这个问题的算法对所有可能的输入都有效——即至今
没有人证明对所有的正整数该过程都终止。
*/
long long int ans[MAX] = {0, 0, 1};
bool flag[MAX] = {true, true, true};

long long int Collatz(long long int n)
{
	if(n < MAX)
	{
		if(!flag[n])
		{
			ans[n] = n & 1 ? (Collatz(3 * n + 1) + 1) : (Collatz(n >> 1) + 1);
			flag[n] = true;
		}
		return ans[n];
	}
	else
	{
		if(n & 1)
			return Collatz(3 * n + 1) + 1;
		else
			return Collatz(n >> 1) + 1;
	}
}
int main()
{
	int t, n;
	long long num;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		if(n < MAX)
		{
			if(!flag[n])
			{
				ans[n] = Collatz(n);
				flag[n] = true;
			}
			num = ans[n];
		}
		else
			num = Collatz(n);
		printf("%I64d\n", num);
	}

	return 0;
}
/*
题目和3038原题一样，不过数据有所加强。
输入描述 Input Description
第一行是一个整数T.表示输入数据的组数.
第二行是T个正整数n.
输出描述 Output Description
对于每个正整数n，每行输出一个数s，表示n通过多少步变换会变成1，如果n无法变成1，则输出-1.
样例输入 Sample Input
3
1 2 3
样例输出 Sample Output
0
1
7
数据范围及提示 Data Size & Hint
1 <= T <= 300000
1 <= n <= 1000000000
*/
