#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
/*
题目描述 Description
考虑以下定义在非负整数n上的递归关系
f(n) = f0 (if n = 0)
     = f1 (if n = 1)
     = a*f(n-1)+b*f(n-2)  otherwise
其中a,b是满足以下两个条件的常数：
(1) a2+4b>0
(2) |a-sqrt(a2+4b)| <= 2   // sqrt是根号的意思
给定f0,f1, a, b和n，请你写一个程序计算fn，可以假定fn是绝对值不超过10^9的整数(四舍五入)。
*/
double qpow(double x, int n)
{
	double ret = x, tem = 1.0;
	while(n)
	{
		if(n & 1)
			tem *= ret;
		ret *= ret;
		n >>= 1;
	}
	return tem;
}

int main(int argc, char **argv)//数列的特征方程解法
{
	double f0, f1, a, b, c, d;
	int n;
	cin >> f0 >> f1 >> a >> b;
	if(f0 == 0.0 && f1 == 0.0)
		printf("0");
	else
	{
		double root = sqrt(a * a + 4.0 * b);
		double x1, x2;
		x1 = (a + root) / 2.0;
		x2 = (a - root) / 2.0;
		c = (f1 - f0 * x2) / (x1 - x2);
		d = (f1 - f0 * x1) / (x2 - x1);
		scanf("%d", &n);
		printf("%.0f", c * qpow(x1, n) + d * qpow(x2, n));
	}
	return 0;
}
/*
输入描述 Input Description
输入文件一行依次给出5个数，f0, f1, a, b和n, f0,f1是绝对值不超过10^9，n是非负整数，不超过10^9。另外，a、b是满足上述条件的实数，
且|a|,|b|<=10^6。
输出描述 Output Description
输出f(n)
样例输入 Sample Input
【样例输入1】
0 1 1 1 20
【样例输入2】
0 1 -1 0 1000000000
【样例输入3】
-1 1 4 -3 18
样例输出 Sample Output
【样例输出1】
6765
【样例输出2】
-1
【样例输出3】
387420487
数据范围及提示 Data Size & Hint
见输入描述
*/
