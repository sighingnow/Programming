# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description
一天Smart出去玩耍，看见街上的地板是由很多小的正方形组成，顿时心里突发奇想想要总结一下到底有多少正方形……
于是，他狠下心来数了数，终于知道了正方形的总边长为N，你的任务是找出在可以组成的每个至少边长为1的正方形的个数。
*/
int main()
{
	long long int n, sum = 0, i;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
	{
		sum += i * i;
	}
	printf("%lld", sum);
	return 0;
}

/*
输入描述 Input Description
一个自然数N。
输出描述 Output Description
一个整数，即正方形的总数。
样例输入 Sample Input
2
样例输出 Sample Output
5
数据范围及提示 Data Size & Hint
（0≤N≤32767)
*/
