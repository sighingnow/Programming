# include <iostream>
# include <cstdio>
using namespace std;
/*
题目描述 Description   1497 取余运算
输入b，p，k的值，编程计算b^p mod k的值。其中的b，p，k*k为长整型数(2^31范围内）。
题解： (a*b) mod p=(a mod p) *(b mod p) mod p
把指数转成2进制，如100变为1100100，从第一位到最后
若为0 f[i]:=(f[i-1]*f[i-1]) mod k
若为1 f[i]:=(((f[i-1]*f[i-1]) mod k)*(b mod k))mod k；递推一下就好了
*/
long long int b, p, k;
long long int QuickPow(long long int x, long long int y)
{
	long long int ret = x, pow = 1;
	while(y)
	{
		if(y & 1)
		{
			pow = (pow % k) * (ret % k) % k;
		}
		ret = (ret % k) * (ret % k) % k;
		y >>= 1;
	}
	return pow % k;
}
int main()
{
	cin >> b >> p >> k;
	cout << b << "^" << p << " mod " << k << "=" << QuickPow(b, p); 

	return 0;
}

/*
输入描述 Input Description
b p k 
输出描述 Output Description
输出b^p mod k=?
=左右没有空格
样例输入 Sample Input
2  10  9
样例输出 Sample Output
2^10 mod 9=7
数据范围及提示 Data Size & Hint
*/
