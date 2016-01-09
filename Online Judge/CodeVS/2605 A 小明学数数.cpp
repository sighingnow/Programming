# include <iostream>
# include <cstdio>
using namespace std;
/*
题目描述 Description
小明才会学数数，妈妈就开始难为他了。告诉他N(N<=1000000)个数字，问他哪一个数字出现的次数为奇数（保证N为奇数，数据中每个
数字出现的次数只有一个为奇数次，每个数字为int范围内）
*/
/*
可以利用异或运算的性质：
a ^ a = 0
a ^ 0 = a
*/
int main()
{
	int n, i = 0, j;
	for(scanf("%d", &n); n--; i^=j)
	{
		scanf("%d", &j);
	}
	cout << i;

	return 0;
}

/*
输入描述 Input Description
第一行一个N；第i+1行为第i个数字
输出描述 Output Description
输出仅仅一行，为出现奇数次的那个数字
样例输入 Sample Input
5
3
6
7
6
3
样例输出 Sample Output
7
数据范围及提示 Data Size & Hint
题目已经给出，注意数字大小。
*/
