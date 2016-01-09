#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define PI 3.14159265359
using namespace std;
/*
题目描述 Description
给出两个正整数A和B，计算A*B的值。保证A和B的位数不超过100000位。
*/
class complex
{
	public:
		double x, y;
	complex()
	{
		this->x = 0;
		this->y = 0;
	}
	complex(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	complex operator + (const complex &t)
	{
		return complex(x + t.x, y + t.y);
	}
	complex operator - (const complex &t)
	{
		return complex(x - t.x, y - t.y);
	}
	complex operator * (const complex &t)
	{
		return complex(x * t.x - y * t.y, x * t.y + y * t.x);
	}
};

/*
 * 进行FFT和IFFT前的反转变换。
 * 位置i和 （i二进制反转后位置）互换
 * len必须去2的幂
 */
void change(complex t[], int len)
{
	int i, j, k;
	for(i = 1, j = len / 2; i < len - 1; ++i)
	{
		if(i < j)
			swap(t[i], t[j]);
		//交换互为小标反转的元素，i<j保证交换一次
        //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的

		k = len / 2;
		while(j >= k)
		{
			j -= k;
			k /= 2;
		}
		if(j < k)
			j += k;
	}
}

/*
 * 做FFT
 * len必须为2^k形式，
 * on==1时是DFT，on==-1时是IDFT
 */
void fft(complex t[], int len, int on)
{
	change(t, len);
	for(int h = 2; h <= len; h <<= 1)
	{
		complex m(cos(-on * 2 * PI / h), sin(-on * 2 * PI / h));
		for(int j = 0; j < len; j += h)
		{
			complex n(1, 0);
			for(int k = j; k < j + h / 2; ++k)
			{
				complex u = t[k];
				complex v = n * t[k + h / 2];
				t[k] = u + v;
				t[k + h / 2] = u - v;
				n = n * m;
			}
		}
	}
	if(on == -1)
	{
		for(int i = 0; i < len; ++i)
			t[i].x /= len;
	}
}

const int MAXN = 400020;
complex t[MAXN], s[MAXN];
char str1[MAXN/2], str2[MAXN/2];
int sum[MAXN];

int main()
{
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len = 1;
	while(len < len1 * 2 || len < len2 * 2)
		len <<= 1;
	for(int i = 0; i < len1; ++i)
		t[i] = complex(str1[len1-1-i] - '0', 0);
	for(int i = len1; i < len; ++i)
		t[i] = complex(0, 0);
	for(int i = 0; i < len2; ++i)
		s[i] = complex(str2[len2-i-1] - '0', 0);
	for(int i = len2; i < len; ++i)
		s[i] = complex(0, 0);
	
	//DFT
	fft(t, len, 1);
	fft(s, len, 1);
	for(int i = 0; i < len; ++i)
		t[i] = t[i] * s[i];
	fft(t, len, -1);//IDFT
	for(int i = 0; i < len; ++i)
		sum[i] = (int)(t[i].x + 0.5);

	for(int i = 0; i < len; ++i)
	{
		sum[i+1] += sum[i] / 10;
		sum[i] %= 10;
	}
	len = len1 + len2 - 1;
	while(sum[len] <= 0 && len > 0)
		--len;

	for(int i = len; i >= 0; --i)
		printf("%d", sum[i]);

	return 0;
}
/*
输入描述 Input Description
读入两个用空格隔开的正整数
输出描述 Output Description
输出A*B的值
样例输入 Sample Input
4 9
样例输出 Sample Output
36
数据范围及提示 Data Size & Hint
两个正整数的位数不超过100000位
*/
