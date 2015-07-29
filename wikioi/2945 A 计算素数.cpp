# include <iostream>
# include <cmath>
using namespace std;
/*
题目描述 Description
计算[A,B]（区间包括A和B，2<=A<=B<=18000000)之间，一共有多少素数？
*/
bool flag[18000001];
int main()
{
	int a, b, i, j, k, sum = 0;
	cin >> a >> b;
	k = sqrt(b) + 1;
	for(i = 2; i <= k; ++i)
		if(!flag[i])
			for(j = i << 1; j <= b; j += i)
			{
				flag[j] = 1;
			}
	for(i = a; i <= b; ++i)
		sum += !flag[i];
	cout << sum << endl;

	return 0;
}
/*
输入描述 Input Description
一行两个数A和B
输出描述 Output Description
一个数，表示素数的个数
样例输入 Sample Input
3 10
样例输出 Sample Output
3
数据范围及提示 Data Size & Hint
2<=A<=B<=18000000
*/
