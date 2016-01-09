#include <iostream>
#include <cstdio>

using namespace std;
/*
题目描述 Description
给出一个整数 n（n<10^30) 和 k 个变换规则（k<=15）。
规则：
一位数可变换成另一个一位数：
规则的右部不能为零。
例如：n=234。有规则（k＝2）：
2－> 5
3－> 6
上面的整数 234 经过变换后可能产生出的整数为（包括原数）:
234
534
264
564
共 4 种不同的产生数
问题：
给出一个整数 n 和 k 个规则。
求出：
经过任意次的变换（0次或多次），能产生出多少个不同整数。
仅要求输出个数。
*/
int main(int argc, char **argv)
{
	int num[31], k, len;
	int f[31] = {0};
	bool map[10][10] = {{false}};
	long long int ans = 1;
	char s[32];
	
	scanf("%s %d", s+1, &k);
	for(len = 1; s[len] != '\0'; ++len)
		num[len] = s[len] - '0';
	
	for(int i = 1; i <= k; ++i)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = true;
	}

	for(int i = 0; i < 10; ++i)
		map[i][i] = true;
	
	for(int k = 0; k < 10; ++k)
	{
		for(int i = 0; i < 10; ++i)
		{
			for(int j = 0; j < 10; ++j)
				map[i][j] = map[i][j] | (map[i][k] & map[k][j]);
		}
	}

	for(int i = 1; i < len; ++i)
	{
		for(int j = 0; j < 10; ++j)
		{
			if(map[num[i]][j])
				f[i]++;
		}
		ans *= f[i];
	}
	cout << ans;

	return 0;
}
/*
输入描述 Input Description
键盘输人，格式为：
n k
x1 y1
x2 y2
... ...
xn yn
输出描述 Output Description
屏幕输出，格式为：
一个整数（满足条件的个数）
样例输入 Sample Input
234 2
2 5
3 6
样例输出 Sample Output
4
数据范围及提示 Data Size & Hint
*/