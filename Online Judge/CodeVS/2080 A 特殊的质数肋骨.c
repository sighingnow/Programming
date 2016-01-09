# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description
农民约翰的母牛总是产生最好的肋骨。 你能通过农民约翰和美国农业部标记在每根肋骨上的数字认出它们。 农民约翰确定他卖给买方的
是真正的质数肋骨,是因为从右边开始切下肋骨,每次还剩下的肋骨上的数字都组成一个质数,举例来说: 7 3 3 1 全部肋骨上的数字 
7331是质数;三根肋骨 733是质数;二根肋骨 73 是质数;当然,最后一根肋骨 7 也是质数。 7331 被叫做长度 4 的特殊质数。 写一个程
序对给定的肋骨的数目 N(1<=N<=8),求出所有的特殊质数。 数字1不被看作一个质数。
*/
int prime[6000000] = {2, 3, 5, 7, 11}, top = 5;
char flag[100000000];

void ispri()              //预处理100000000内所有的质数
{
	int i, j, k;
	for(i = 13; i < 100000000; i += 2)
	{
		if(i % 5 != 0)
		{
			k = sqrt(i);
			for(j = 1; j <= k; j++)
			{
				if(i % prime[j] == 0)
					break;
			}
			if(j > k)
				prime[top++] = i;
		}
	}
	for(i = 0; i < top; i++)
		flag[prime[i]] = 1;
}
int mypow(int n)
{
	int i, k = 1;
	for(i = 1; i <= n; i++)
		k *= 10;
	return k;
}
int main()
{
	ispri();
	int n, i, k, k1, k2;
	scanf("%d", &n);
	k1 = mypow(n-1);
	k2 = k1 * 10;
	for(i = 2 * k1 + 1; i < k2; i += 2)
	{
		k = i;
		while(k != 0)
		{
			if(flag[k] != 1)
				break;
			k /= 10;
		}
		if(k == 0)
			printf("%d\n", i);
	}
	return 0;
}

/*
输入描述 Input Description
单独的一行包含N。
输出描述 Output Description
按顺序输出长度为 N 的特殊质数,每行一个。
样例输入 Sample Input
4
样例输出 Sample Output
2333
2339
2393
2399
2939
3119
3137
3733
3739
3793
3797
5939
7193
7331
7333
7393
数据范围及提示 Data Size & Hint
见描述
*/
