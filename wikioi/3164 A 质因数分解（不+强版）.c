# include <stdio.h>
# include <string.h>
/*
题目描述 Description
时间我拉到了10s,空间我拉到了最大。。。。。。看你们怎么算。
（多数据）给出t个数，求出它的质因子个数。
数据没坑，难度降低。
*/
int main()
{
	long long t, n, ts, i;
	scanf("%I64d", &t);
	while(t--)
	{
		scanf("%I64d", &n);
		ts = 0;
		for(i = 2; i <= n; i ++)
		{
			if(n % i == 0)
				while(n % i == 0)
					n = n / i, ts ++;
		}
		printf("%I64d\n", ts);
	}

	return 0;
}

/*
输入描述 Input Description
第一行 t
之后t行 数据
输出描述 Output Description
t行 分解后结果（质因子个数）
样例输入 Sample Input
2
11
6
样例输出 Sample Output
1
2
数据范围及提示 Data Size & Hint
(样例解释)11自己本身是一个质数，所以计入其中。
顺便提示：t<=100000。每个数小于long long unsigned 呵呵
*/
