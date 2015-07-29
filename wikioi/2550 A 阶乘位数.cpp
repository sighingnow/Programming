# include <iostream>
# include <cstdio>
# include <cmath>
using namespace std;
/*
题目描述 Description
在很多软件中需要用到较大的整数。比如一些软件将大数用于数据安全传送的密匙或者密码编译等等。在这个问题中，你要根据给你的
整数，算出这个数的阶乘的位数。 
*/
int main()
{
	long long int n, m;
	double sum;
	cin >> n;
	while(n--)
	{
		sum = 0;
		scanf("%I64d", &m);
		while(m--)
			sum += log10(m+1);
		printf("%I64d\n", (long long int)sum + 1);
	}
}
/*
输入描述 Input Description
输入文件包含若干行整数。第一行为n，表示有n组数据，接下来是n行，每行一个整数m. 
输出描述 Output Description
输出这些数的阶乘的位数。
样例输入 Sample Input
2
10
20
样例输出 Sample Output
7
19
数据范围及提示 Data Size & Hint
1≤m≤10^7.
*/
