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
题目描述 Description
合并两个有序数组A和B，使得结果依然有序。
进阶：合并两个有序数组A和B，假设A有n个数，B有m个数，A数组后面还有m个空余空间，需要将结果保存在A中。
请使用O(n)的算法完成
*/
int a[1000001], b[1000001];
int main(int argc, char **argv)
{
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		read(a[i]);
	for(int i = 1; i <= m; ++i)
		read(b[i]);
	sort(a, a + n);
	sort(b, b + m);
	int u = 1, v = 1;
	while(u <= n && v <= m)
	{
		if(a[u] < b[v])
			printf("%d ", a[u++]);
		else
			printf("%d ", b[v++]);
	}
	while(u <= n)
		printf("%d ", a[u++]);
	while(v <= m)
		printf("%d ", b[v++]);

	return 0;
}
/*
输入描述 Input Description
第一行输入两个整数n和m
第二行输入n个用空格隔开的整数表示数组A
第三行输入m个用空格隔开的整数表示数组B
输入保证A和B数组非递减
输出描述 Output Description
输出一行一共n+m个空格隔开的整数，即合并后的结果
样例输入 Sample Input
2 3 
1 2
1 1 5
样例输出 Sample Output
1 1 1 2 5
数据范围及提示 Data Size & Hint
1<=n,m<=1000000
*/
