# include <iostream>
# include <cstdio>
# include <cmath>
# include <cstring>
using namespace std;
/*
题目描述 Description
一个自然数是素数，且它的数字位置经过任意对换后仍为素数，则称为绝对素数，例如13。请找出所有x位的绝对素数的数量。
*/
int num[5] = {0, 1, 3, 7, 9}, buf[7], n, sum, tmp[7], flag[7], fact, mark;
bool prime[1000001] = {1, 1, 0, 0};   //质数为 0
void isprime(void)    //筛选法求出质数表
{
	int i, j;
	for(i = 1; i <= 500000; ++i)
	{
		if(!prime[i])
			for(j = i + i; j <= 1000000; j += i)
				prime[j] = 1;
	}
}
int trans(int tmp[])
{
	int i, k = 0;
	for(i = 1; i <= n; ++i)
		k = k * 10 + tmp[i];
	return k;
}
void judge(int m)
{
	int i;
	if(m > n)
	{
		if(prime[trans(tmp)])
			return;
		else
			++mark;
	}
	else
	{
		for(i = 1; i <= n; ++i)
		{
			if(!flag[i])
			{
				flag[i] = 1;
				tmp[m] = buf[i];
				judge(m+1);
				flag[i] = 0;
			}
		}
	}
}
void zuhe(int m)
{
	int i;
	if(m > n)
	{
		mark = 0;
		judge(1);
		if(mark == fact)
			++sum;
	}
	else
	{
		for(i = 1; i <= 4; ++i)
		{
			buf[m] = num[i];
			zuhe(m+1);
		}
	}
}
int main()
{
	isprime();
	int i;
	cin >> n;
	fact = 1;
	for(i = 1; i <= n; ++i)
		fact *= i;
	if(n == 1)
	{
		cout << "4";
		return 0;
	}
	else
	{
		zuhe(1);
		cout << sum;
	}
	
	return 0;
}

/*
输入描述 Input Description
输入正整数x
输出描述 Output Description
x位的绝对素数的数量
样例输入 Sample Input
1
样例输出 Sample Output
4
数据范围及提示 Data Size & Hint
x（x<=6)
*/
