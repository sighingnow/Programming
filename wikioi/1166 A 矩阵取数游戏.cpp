#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
/*
题目描述 Description
【问题描述】
帅帅经常跟同学玩一个矩阵取数游戏：对于一个给定的n*m 的矩阵，矩阵中的每个元素aij均
为非负整数。游戏规则如下：
1. 每次取数时须从每行各取走一个元素，共n个。m次后取完矩阵所有元素；
2. 每次取走的各个元素只能是该元素所在行的行首或行尾；
3. 每次取数都有一个得分值，为每行取数的得分之和，每行取数的得分= 被取走的元素值*2i，
其中i 表示第i 次取数（从1 开始编号）；
4. 游戏结束总得分为m次取数得分之和。
帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。
*/
int * work(int *ans, int *num, int number);
int * cmp(int *x, int *y);
int * numcpy(int *x, int *y);

int main(int argc, char **argv)
{
	int n, m;
	int num[85];
	int dp[85][85][25];
	int tmp1[30], tmp2[30];
	int ans[30] = {0};
	cin >> n >> m;
	while(n--)
	{
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= m; ++i)
		{
			scanf("%d", &num[i]);
			dp[i][i][1] = num[i] * 2;
			for(int j = 1; j <= m; ++j)
				dp[i][j][0] = 1;
		}
		for(int i = 2; i <= m; ++i)
		{
			for(int j = i - 1; j >= 1; --j)
			{
				numcpy(dp[j][i], cmp(work(tmp1, dp[j][i-1], num[i]), work(tmp2, dp[j+1][i], num[j])));
			}
		}
		int len = max(ans[0], dp[1][m][0]);
		int tmp = 0;
		for(int i = 1; i <= len; ++i)
		{
			ans[i] += (dp[1][m][i] + tmp);
			tmp = ans[i] / 10000;
			ans[i] %= 10000;
		}
		while(tmp)
		{
			ans[++len] = tmp % 10000;
			tmp /= 10000;
		}
		
		ans[0] = len;
	}
	printf("%d", ans[ans[0]--]);
	while(ans[0])
	{
		printf("%04d", ans[ans[0]--]);
	}
	
	return 0;
}

int * work(int *ans, int *num, int number)
{
	ans[0] = num[0];
	number *= 2;
	for(int i = 1; i <= ans[0]; ++i)
	{
		ans[i] = num[i] * 2 + number;
		number = ans[i] / 10000;
		ans[i] %= 10000;
	}
	while(number)
	{
		ans[++ans[0]] = number % 10000;
		number /= 10000;
	}
	return ans;
}

int * cmp(int *x, int *y)
{
	if(x[0] > y[0])
		return x;
	if(x[0] < y[0])
		return y;
	int i;
	for(i = x[0]; i > 1; --i)
	{
		if(x[i] != y[i])
			break;
	}
	if(x[i] >= y[i])
		return x;
	else
		return y;
}

int * numcpy(int *x, int *y)
{
	for(int i = 0; i <= y[0]; ++i)
		x[i] = y[i];
	return x;
}

/*附：此题的低精度版本
# include <stdio.h>
# include <string.h>
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n, m, i, j, ans = 0;
	scanf("%d %d", &n, &m);
	int num[m+1], dp[m+1][m+1];
	while(n--)                     //一行一行地处理
	{
		memset(dp, 0, sizeof(dp));
		for(i = 1; i <= m; ++i)
		{
			scanf("%d", num+i);
			dp[i][i] = num[i] * 2;
		}
		//dp[i][j]表示 num[i]至num[j]合并后的结果
		for(i = m - 1; i >= 1; --i)
		{
			for(j = i + 1; j <= m; ++j)
				dp[i][j] = max(dp[i+1][j] * 2 + num[i] * 2, dp[i][j-1] * 2 + num[j] * 2);
			//num[i]或num[j]表示新取的数
		}
		ans += dp[1][m];
	}
	printf("%d", ans);

	return 0;
}
*/
/*
输入描述 Input Description
第1行为两个用空格隔开的整数n和m。
第2~n+1 行为n*m矩阵，其中每行有m个用单个空格隔开的非负整数。
输出描述 Output Description
输出 仅包含1 行，为一个整数，即输入矩阵取数后的最大得分。
样例输入 Sample Input
2 3
1 2 3
3 4 2
样例2
2 10
96 56 54 46 86 12 23 88 80 43
16 95 18 29 30 53 88 83 64 67
样例输出 Sample Output
82
样例2
316994
数据范围及提示 Data Size & Hint
样例解释
第 1 次：第1 行取行首元素，第2 行取行尾元素，本次得分为1*2^1+2*2^1=6
第2 次：两行均取行首元素，本次得分为2*2^2+3*2^2=20
第3 次：得分为3*2^3+4*2^3=56。总得分为6+20+56=82
【限制】
60%的数据满足：1<=n, m<=30, 答案不超过10^16
100%的数据满足：1<=n, m<=80, 0<=aij<=1000
*/
