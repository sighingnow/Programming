# include <iostream>
# include <cstdio>
# include <cmath>
# include <cstring>
using namespace std;
/*
题目描述 Description   矩阵乘法加快速幂
定义：f0=f1=1, fn=fn-1+fn-2(n>=2)。{fi}称为Fibonacci数列。
输入n，求fn mod q。其中1<=q<=30000。
*/
int q;
class matrix
{
	public:
		int a, b, c, d;
		friend matrix operator * (matrix, matrix);
		matrix()	{	};
		matrix(int a, int b, int c, int d)
		{
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
		}
};
matrix operator * (matrix x, matrix y)      //操作符重载
{
	matrix tmp;
	tmp.a = (x.a * y.a + x.b * y.c) % q;
	tmp.b = (x.a * y.b + x.b * y.d) % q;
	tmp.c = (x.c * y.a + x.d * y.c) % q;
	tmp.d = (x.c * y.b + x.d * y.d) % q;
	return tmp;
}
matrix QuickPow(matrix x, int k)
{
	matrix ret = x;
	matrix pow(1, 0, 0, 1);
	while(k > 0)
	{
		if(k & 1)
			pow = pow * ret;
		ret = ret * ret;
		k >>= 1;
	}
	return pow;
}
int main()
{
	matrix m(0, 1, 1, 1);
	matrix ans;
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n >> q;
		if(n <= 1)
		{
			cout << 1 << endl;
		}
		else
		{
			ans = QuickPow(m, n-1);
			cout << (ans.c + ans.d) % q << endl;
		}
	}
		
	return 0;
}
/*

输入描述 Input Description
第一行一个数T(1<=T<=10000)。
以下T行，每行两个数，n，q(n<=109, 1<=q<=30000)
输出描述 Output Description
文件包含T行，每行对应一个答案。
样例输入 Sample Input
3
6 2
7 3
7 11
样例输出 Sample Output
1
0
10
数据范围及提示 Data Size & Hint
1<=T<=10000
n<=10^9, 1<=q<=30000
*/
