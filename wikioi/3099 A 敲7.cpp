#include <iostream>
using namespace std;
/*
题目描述 Description
给定正整数N(≤100,000)，求数列{An}的前N项。数列{An}包含正整数集中所有能被7整除的数；还包含正整数集中所有
个位上含7的数，如17,27,177。
*/
int main(int argc, char **argv)
{
	int n;
	cin >> n;
	int tmp = n / 16;
	int num = n - tmp * 16;
	int m = tmp * 70;
	for(int i = 1; i <= num; )
	{
		++m;
		if(m % 10 == 7 || m % 7 == 0)
			++i;
	}
	cout << m;

	return 0;
}
/*
输入描述 Input Description
输入仅包括一个正整数N(≤100,000) 
输出描述 Output Description
只输出一个数，数列{An}按从小到大顺序的第N项。
样例输入 Sample Input
3
样例输出 Sample Output
17
数据范围及提示 Data Size & Hint
N(≤100,000) 
*/
