#include <iostream>
#include <cstdio>
using namespace std;
/*
题目描述 Description
给你6个数，m, a, c, x0, n, g
Xn+1 = ( aXn + c ) mod m，求Xn
m, a, c, x0, n, g<=10^18
*/
long long int m, a, c, x0, g;

long long int _int64_multi(long long int x, long long int y) //倍增乘法
{
	long long ans = 0;
	x %= m;
	while(y)
	{
		if(y & 1)
			ans = (ans + x) % m;
		x = (x << 1) % m;
		y >>= 1;
	}
	return ans;
}

void qpow(long long int n, long long int mt[][2], long long int tem[][2])
{
	long long int ret[2][2] = {{mt[0][0], mt[0][1]}, {mt[1][0], mt[1][1]}};
	long long int tmp[2][2];
	tem[0][0] = tem[1][1] = 1;
	tem[0][1] = tem[1][0] = 0;
	while(n)
	{
		if(n & 1)
		{
			tmp[0][0] = _int64_multi(tem[0][0], ret[0][0]) + _int64_multi(tem[0][1], ret[1][0]);
			tmp[0][1] = _int64_multi(tem[0][0], ret[0][1]) + _int64_multi(tem[0][1], ret[1][1]);
			tmp[1][0] = _int64_multi(tem[1][0], ret[0][0]) + _int64_multi(tem[1][1], ret[1][0]); 
			tmp[1][1] = _int64_multi(tem[1][0], ret[0][1]) + _int64_multi(tem[1][1], ret[1][1]);
			tem[0][0] = tmp[0][0] % m;
			tem[0][1] = tmp[0][1] % m;
			tem[1][0] = tmp[1][0] % m;
			tem[1][1] = tmp[1][1] % m;
		}
		tmp[0][0] = _int64_multi(ret[0][0], ret[0][0]) + _int64_multi(ret[0][1], ret[1][0]);
		tmp[0][1] = _int64_multi(ret[0][0], ret[0][1]) + _int64_multi(ret[0][1], ret[1][1]);
		tmp[1][0] = _int64_multi(ret[1][0], ret[0][0]) + _int64_multi(ret[1][1], ret[1][0]); 
		tmp[1][1] = _int64_multi(ret[1][0], ret[0][1]) + _int64_multi(ret[1][1], ret[1][1]);
		ret[0][0] = tmp[0][0] % m;
		ret[0][1] = tmp[0][1] % m;
		ret[1][0] = tmp[1][0] % m;
		ret[1][1] = tmp[1][1] % m;
		n >>= 1;
	}
}

int main(int argc, char **argv)
{
	long long int n;
	cin >> m >> a >> c >> x0 >> n >> g;
	long long ans[2][2];
	long long matrix[2][2];
	matrix[0][0] = a;
	matrix[0][1] = matrix[1][1] = 1;
	matrix[1][0] = 0;
	qpow(n, matrix, ans);
	printf("%I64d\n", (_int64_multi(ans[0][0], x0) + _int64_multi(ans[0][1], c)) % m % g);
	return 0;
}

/*
输入描述 Input Description
一行六个数 m, a, c, x0, n, g
输出描述 Output Description
输出一个数 Xn mod g
样例输入 Sample Input
11 8 7 1 5 3
样例输出 Sample Output
2
数据范围及提示 Data Size & Hint
int64按位相乘可以不要用高精度。
*/
