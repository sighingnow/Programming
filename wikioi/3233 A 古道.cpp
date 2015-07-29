# include <iostream>
# include <cstdio>
# include <cmath>
# include <cstring>
using namespace std;
/*
题目描述 Description
小陈坐车3个小时，终于到达了风光旖旎的云水谣古道。
从它的入口开始，有N种风景，例如千年的大榕树、河上的瀑布，河边的沙滩。。。。。。
每种每隔ai米有一个，所有风景交汇在一点的地方是"最美风光“。
求小陈走到”最美风光“处至少要走多少米？
*/
long long gcd(long long int x, long long int y)
{
	long long int z = y;
	while(x % y)
	{
		z = x % y, x = y, y = z;
	}
	return z;
}
int main()
{
	long long int n, i, distance[11] = {1}, Gcd;
	cin >> n;
	for(i = 1; i <= n; ++i)
	{
		cin >> distance[i];
	}
	*distance = distance[1];
	if(n != 1)
	{
		for(i = 2; i <= n; ++i)
		{
			Gcd = gcd(*distance, *(distance+i));
			*distance = *distance * *(distance+i) / Gcd;
		}
	}
	cout << *distance;
	
	return 0;
}

/*
输入描述 Input Description
N
N个正整数，ai
输出描述 Output Description
最少距离
样例输入 Sample Input
3
2 4 5
样例输出 Sample Output
20
数据范围及提示 Data Size & Hint
N<=10，ai<=100.
*/
