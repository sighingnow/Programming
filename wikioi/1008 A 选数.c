# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description
已知 n 个整数 x1,x2,…,xn，以及一个整数 k（k＜n）。从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。例如当 n=4，k＝3，4 个整数分别
为 3，7，12，19 时，可得全部的组合与它们的和为：
3＋7＋12=22　　3＋7＋19＝29　　7＋12＋19＝38　　3＋12＋19＝34。
现在，要求你计算出和为素数共有多少种。
例如上例，只有一种的和为素数：3＋7＋19＝29）。
*/
int num[20], buf[20], flag[20], n, k, x, total;
int ispri(int n)
{
	int i, k;
	k = sqrt(n);
	if(n == 1)
		return 0;
	if(n == 2)
		return 1;
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
void func(int t, int m)
{
	int i;
	if(m == k)
	{
		x = 0;
		for(i = 0; i < k; i++)
			x += buf[i];
		if(ispri(x) == 1)
			total ++;
	}
	else
	{
		for(i = t; i < n; i++)
		{
			buf[m] = num[i];
			if(flag[i] == 0)
			{
				flag[i] = 1;
				func(i, m+1);
				flag[i] = 0;
			}
		}
	}
}
int main()
{
	int i;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
		scanf("%d", &num[i]);
	func(0, 0);
	printf("%d\n", total);
	return 0;
}

/*
输入描述 Input Description
键盘输入，格式为：
n , k （1<=n<=20，k＜n）
x1,x2，…,xn （1<=xi<=5000000）
输出描述 Output Description
屏幕输出，格式为：
一个整数（满足条件的种数）。
样例输入 Sample Input
4 3
3 7 12 19
样例输出 Sample Output
1
数据范围及提示 Data Size & Hint
*/
