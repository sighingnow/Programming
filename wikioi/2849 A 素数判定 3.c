/***************************************************
*Copyright (C):  2014  HeTao  All Rights Reserved.
*Filename:
*Author: ht
*Version:
*Created on:
****************************************************/
/*
题目描述 Description
输入一个正整数x（3<=x<=100000），判断x是否是质数，如果是质数则输出信息“prime”，否则输出“composite”。
*/
# include <stdio.h>
int ispri(int n)
{
	int i, k;
	k = sqrt(n);
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
int main(int argc, char **argv)
{
	int n;
	scanf("%d", &n);
	if(ispri(n) == 1)
		printf("prime");
	else
		printf("composite");

	return 0;
}
/*
一行一个正整数
输出描述 Output Description
输出prime或者composite
样例输入 Sample Input
13
样例输出 Sample Output
prime
数据范围及提示 Data Size & Hint
大于2并且小于100000
*/
