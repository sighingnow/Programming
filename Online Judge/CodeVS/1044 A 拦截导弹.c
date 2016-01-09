# include <stdio.h>
# include <string.h>
/*
题目描述 Description
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，
但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此
有可能不能拦截所有的导弹。
*/
int mis[20];

int dp1(int n)         //第一个问题等价于：求最长不上升子序列
{
	int i, j, f[n], max;
	memset(f, 0, sizeof(f));
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(mis[i] <= mis[j])
			{
				f[i] = f[i] > (f[j] + 1) ? f[i] : (f[j] + 1);
			}
		}
	}
	max = 0;
	for(i = 1; i < n; i++)
	{
		max = max > f[i] ? max : f[i]; 
	}
	return max+1;
}

int dp2(int n)         //第二个问题等价于：求最长上升子序列
{
	int i, j, f[n], max;
	memset(f, 0, sizeof(f));
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(mis[i] > mis[j])
			{
				f[i] = f[i] > (f[j] + 1) ? f[i] : (f[j] + 1);
			}
		}
	}
	max = 0;
	for(i = 1; i < n; i++)
	{
		max = max > f[i] ? max : f[i]; 
	}
	return max+1;
}

int main()                                   //优化：把两个动态规划放在一个函数中解决
{
	int n = 0;
	while(scanf("%d", &mis[n++]) != EOF)
		;
	n--;
	printf("%d\n%d\n", dp1(n), dp2(n));

	return 0;
}

/*
输入描述 Input Description
输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数）
输出描述 Output Description
输出这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。
样例输入 Sample Input
389 207 155 300 299 170 158 65 
样例输出 Sample Output
6
2
数据范围及提示 Data Size & Hint
导弹的高度<=30000，导弹个数<=20
*/
