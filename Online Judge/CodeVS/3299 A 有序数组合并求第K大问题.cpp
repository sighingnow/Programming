#include <iostream>
#include <cstdio>
#include <algorithm>
#define read(x) {char ch; x = 0;\
	while((ch = getchar()) < '0' || ch > '9');\
	x = ch - '0';\
	while((ch = getchar()) >= '0' && ch <= '9')\
	x = x * 10 + ch - '0';\
	}
using namespace std;
/*
给出两个有序数组A和B（从小到大有序），合并两个有序数组后新数组c也有序，询问c数组中第k大的数
假设不计入输入输出复杂度，你能否给出一个O(logN)的方法？
*/
int a[1000001], b[1000001];
int main(int argc, char **argv)
{
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i)
		read(a[i]);
	for(int i = 1; i <= m; ++i)
		read(b[i]);
	sort(a, a + n);
	sort(b, b + m);
	int u = 1, v = 1, i = 1;
	for(; i < k && u <= n && v <= m; ++i)
	{
		if(a[u] <= b[v])
			u++;
		else
			v++;
	}
	if(i < k)
	{
		if(u <= n)
		{
			for(; i < k; ++i)
				u++;
			cout << a[u];
		}
		else
		{
			for(; i < k; ++i)
				v++;
			cout << b[v];
		}
	}
	else
		cout << min(a[u], b[v]);
	return 0;
}
/*
输入描述 Input Description
第一行输入三个整数n、m和k
第二行输入n个用空格隔开的整数表示数组A
第三行输入m个用空格隔开的整数表示数组B
输入保证A和B数组非递减
输出描述 Output Description
合并两个数组之后的第k大的数
样例输入 Sample Input
2 3 4
1 2
1 1 5
样例输出 Sample Output
2
数据范围及提示 Data Size & Hint
1<=n,m<=1000000
1<=k <=n+m
*/
