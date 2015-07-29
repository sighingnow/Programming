#include <iostream>
#include <cstdio>
using namespace std;
/*
题目描述 Description
试计算在区间1到n的所有整数中，数字x（0≤x≤9）共出现了多少次？例如，在1到11中，即在1、2、3、4、5、6、7、8、9、10、11中，数字1出现了4次。
*/
int main(int argc, char **argv)
{
	int n, x;
	int count[10] = {0}; 
	cin >> n >> x;
	for(int i = 1; i <= n; ++i)
	{
		int j = i;
		while(j)
		{
			count[j % 10] ++;
			j /= 10;
		}
	}
	cout << count[x];
	return 0;
}
/*
输入描述 Input Description
输入共1行，包含2个整数n、x，之间用一个空格隔开。
输出描述 Output Description
输出共1行，包含一个整数，表示x出现的次数。
样例输入 Sample Input
11 1
样例输出 Sample Output
4
数据范围及提示 Data Size & Hint
对于100%的数据，1≤n≤1,000,000，0≤x≤9。
*/
