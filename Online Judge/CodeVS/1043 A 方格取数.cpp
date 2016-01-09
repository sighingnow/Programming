#include <iostream>
#include <cstdio>
using namespace std;
/*
题目描述 Description
设有N*N的方格图(N<=10,我们将其中的某些方格中填入正整数,而其他的方格中则放入数字0。如下图所示（见样例）：
某人从图的左上角的A 点出发，可以向下行走，也可以向右走，直到到达右下角的B点。在走过的路上，他可以取走方格
中的数（取走后的方格中将变为数字0）。
此人从A点到B 点共走两次，试找出2条这样的路径，使得取得的数之和为最大。
*/
int map[11][11];
int dp[11][11][11][11];

int main(int argc, char **argv)
{
	int n;
	cin >> n;
	while(1)
	{
		int x, y, num;
		scanf("%d %d %d", &x, &y, &num);
		if(x == 0)
			break;
		map[x][y] = num;
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			for(int k = 1; k <= n; ++k)
			{
				for(int l = 1; l <= n; ++l)
				{
					dp[i][j][k][l] = max(max(dp[i-1][j][k-1][l], dp[i-1][j][k][l-1]), 
										 max(dp[i][j-1][k][l-1], dp[i][j-1][k-1][l])) + map[i][j] + map[k][l];
					if(i == k || j == l)
						dp[i][j][k][l] -= map[i][j];
				}
			}
		}
	}
	cout << dp[n][n][n][n];

	return 0;
}
/*
输入描述 Input Description
输入的第一行为一个整数N（表示N*N的方格图），接下来的每行有三个整数，前两个表示位置，第三个数为该位置上所放
的数。一行单独的0表示输入结束。
输出描述 Output Description
只需输出一个整数，表示2条路径上取得的最大的和。
样例输入 Sample Input
8
2  3  13
2  6   6
3  5   7
4  4  14
5  2  21
5  6   4
6  3  15
7  2  14
0  0  0
样例输出 Sample Output
67
数据范围及提示 Data Size & Hint
如描述
*/
