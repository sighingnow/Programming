#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
/*
题目描述 Description
小明是一名天文爱好者，他喜欢晚上看星星。这天，他从淘宝上买下来了一个高级望远镜。他十分开心，于是他晚上去操场上看星星。
不同的星星发出不同的光，他的望远镜可以计算出观测到的星星发出的光的数值W。小明当然想尽可能地多看到星星，于是他每看到一颗
星星，就要看看他之前有没有看过这颗星星。但是他看的星星太多了，他根本数不过来，于是他让你帮忙。
*/
int main()
{
	map<int, int>star;
	int n, tmp;
	cin >> n;
	while(n--)
	{
		scanf("%d", &tmp);
		if(star.find(tmp) == star.end())
		{
			putchar('0');
			star.insert(map<int, int>::value_type(tmp, n));
		}
		else
		{
			putchar('1');
		}
	}
	return 0;
}

/*
输入描述 Input Description
共有两行，第一行只有一个整数，为小明观测到的星星的数量n。第二行有n个整数，每两个整数由一个空格隔开，分别为小明观测到每颗
星星的光的数值W[1]-W[n]。
输出描述 Output Description
只有一行，这一行共有n个数字0或1。0表示对应的星星之前没有观测到，1表示对应的星星之前已经看过了。注意：数字之间没有空格！
样例输入 Sample Input
5
1 5 5 4 1
样例输出 Sample Output
00101
数据范围及提示 Data Size & Hint
样例是往往是骗人的，本题中
30%的数据，0<n≤5000。
20%的数据，-20000≤W≤20000。
60%的数据，0<n≤50000。
100%的数据，0<n≤500000；-2000000000≤W≤2000000000。
*/
