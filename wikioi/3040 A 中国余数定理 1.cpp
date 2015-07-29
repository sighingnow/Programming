# include <iostream>
# include <cstdio>
# include <cmath>
# include <cstring>
using namespace std;
/*
题目描述 Description
摘自算法导论。。。。。。
找出第k个被3，5，7除的时候，余数为2，3，2的数；
*/
int main()
{
	long long int n, sum = 23;
	cin >> n;
	n--;
	while(n--)
		sum += 105;
	cout << sum;
	
	return 0;
}

/*
输入描述 Input Description
一个数k。
输出描述 Output Description
求出第k个符合条件的数。
样例输入 Sample Input
1
样例输出 Sample Output
23
数据范围及提示 Data Size & Hint
k>=1;
答案不超过long long所能存储的范围。
典型的数论题。
*/
