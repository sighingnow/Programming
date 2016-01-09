# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description
Ganggang 年纪大了，记性不好，保险箱的密码记不住了，他只记得密码是一个数的阶乘各个位的数相加的和，最后还有个T或F，代表这个数是否为素数，
正好，你到他家去了，他请你帮他这个忙，并答应事成之后给你100000000 MOD 10 RMB。输入一个整数n（1000>=n>=0）
*/
int s[1000] = {1};
int ispri(int n)
{
	int i, k;
	k = sqrt(n);
	if(n == 1 || n == 0)
		return 0;
	for(i = 2; i <= k; i++)
	{
		if(n % i == 0)
			break;
	}
	if(i > k)
		return 1;
	else
		return 0;
}
void fact(int n)      //求一个数的阶乘，每次乘上一个数。
{
	int i, k=0;

	for(i = 0; i < 1000; i++)
	{
		*(s+i) = *(s+i) * n + k;
		k = *(s + i) / 10000;                   //以 10000 为进位制
		*(s+i) %= 10000;
	}
}
int main()
{
	int n, sum = 0, i;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		fact(i);
	for(i = 0; i < 1000; i++)
	{
		while(s[i] > 0)
		{
			sum += s[i] % 10;
			s[i] /= 10;
		}
	}
	printf("%d", sum);
	if(ispri(sum) == 1)
		printf("T\n");
	else
		printf("F\n");
	
	return  0;
}

/*
输出n的阶乘各个位的数相加的和y，最后再输出T或F，
代表y是否为素数。
输入描述 Input Description
输入一个整数n（1000>=n>=0）
输出描述 Output Description
输出n的阶乘各个位的数相加的和y，最后再输出对y是否为素数的判断，
是为T否为F。
样例输入 Sample Input
10
样例输出 Sample Output
27F
数据范围及提示 Data Size & Hint
本体转自vijosP1200
由于n较大，所以计算阶乘时推荐使用高精度算法。
*/
