#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

/*
题目描述 Description
定义 n 个数的乘积平均数为这 n 个数的乘积开 n 次方。
给定 n 个正整数，求它们的乘积平均数。
*/
int main()   //算法：用对数计算
{
	int n, tmp;
	double multi = 1.0;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> tmp;
		multi *= pow(tmp, (double)1.0000/n);
	}
	printf("%.2lf", multi);
	
	return 0;
}
/*
输入描述 Input Description
第一行，一个数 n
接下来一行 n 个数，表示给定的 n 个数
输出描述 Output Description
一个实数，表示给定数的乘积平均数，保留2 位小数输出
样例输入 Sample Input
2
2 8
样例输出 Sample Output
4.00
数据范围及提示 Data Size & Hint
对于 100%的数据，n ≤ 100000，每个数均为正整数且不超过 10
*/
