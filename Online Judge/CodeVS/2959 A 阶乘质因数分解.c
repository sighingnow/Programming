# include <stdio.h>
# include <math.h>
# include <string.h>
/*
题目描述 Description
n!(n≤10000)是一个很大的数，对n!进行质因数分解后形式为：2p1*3p2*…kpk，其中k为某个质数，pi为对应质数的方幂。
*/
int t[10001];

int main()       //对n!分解质因数，等价于对1...n分解质因数再对应相加，这样就避免了高精度运算。
{
	int n, i, j, m;
	scanf("%d", &n);
	if(n == 1)
	{
		printf("0");
		return 0;
	}
	for(i = 2; i <= n; i++)
	{
		j = 2, m = i;
		while(m != 1)
		{
			while(m % j == 0)
			{
				t[j] ++;
				m /= j;
			}
			j ++;
		}
	}
	for(i = 2; i <= n; i++)
	{
		if(t[i] != 0)
			printf("%d ", t[i]);
	}

	return 0;
}

/*
输入描述 Input Description
一个正整数n
输出描述 Output Description
仅一行，由若干个以空格隔开的正整数组成，表示n!的质因数分解形式，每个整数表达质数按从小到大的顺序排列后对应的方幂pi(意义见上)。
样例输入 Sample Input
15
样例输出 Sample Output
11 6 3 2 1 1
数据范围及提示 Data Size & Hint
(n≤10000)
*/
