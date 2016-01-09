# include <iostream>

using namespace std;
/*
题目描述 Description
键盘输入一个正整数n，编程判断该数是奇数还是偶数，如是奇数则输出信息“odd”，如是偶数则输出“even”。
*/


int main(void)
{
	int n;
	cin >> n;
	if(n % 2 == 0)
		cout << "even" << endl;
	else
		cout << "odd" << endl;

	return 0;
}

/*
输入描述 Input Description
一行一个整数n
输出描述 Output Description
一行一个字符串，如是奇数则输出信息“odd”，如是偶是则输出“even”。
样例输入 Sample Input
9
样例输出 Sample Output
odd
数据范围及提示 Data Size & Hint
1<=n<=10000
*/
