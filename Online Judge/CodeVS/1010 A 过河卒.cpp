#include <iostream>
#include <cstdio>

using namespace std;
/*
题目描述 Description
如图，A 点有一个过河卒，需要走到目标 B 点。卒行走规则：可以向下、或者向右。同时在棋盘上的任一点有一个对方的马（如上图的C点），该马
所在的点和所有跳跃一步可达的点称为对方马的控制点。例如上图 C 点上的马可以控制 9 个点（图中的P1，P2 … P8 和 C）。卒不能通过对方马
的控制点。
棋盘用坐标表示，A 点（0，0）、B 点（n,m）(n,m 为不超过 20 的整数，并由键盘输入)，同样马的位置坐标是需要给出的（约定: C不等于A，同时C不
等于B）。现在要求你计算出卒从 A 点能够到达 B 点的路径的条数。
1<=n,m<=15
*/
int f[21][21], e[21][21];//全局变量坐在的数据区自动初始化为0，全局数组越界后值仍为0，而局部变量为乱码

int main(int argc, char **argv)
{
	int n, m, x, y;

	cin >> n >> m >> x >> y;
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= m; ++j)
			e[i][j] = 1;
	}
	f[0][0] = 1;
	
	e[0][0] = 0;
	e[x][y] = 0;
	e[x+1][y+2] = 0;
	e[x+1][y-2] = 0;
	e[x+2][y+1] = 0;
	e[x+2][y-1] = 0;
	e[x-1][y+2] = 0;
	e[x-1][y-2] = 0;
	e[x-2][y-1] = 0;
	e[x-2][y+1] = 0;

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= m; ++j)
		{
			if(e[i][j])
				f[i][j] = f[i-1][j] + f[i][j-1];
		}
	}
	cout << f[n][m];

	return 0;
}
/*
输入描述 Input Description
键盘输入
B点的坐标（n,m）以及对方马的坐标（X,Y）{不用判错}
输出描述 Output Description
屏幕输出
一个整数（路径的条数）。
样例输入 Sample Input
6 6 3 2
样例输出 Sample Output
17
数据范围及提示 Data Size & Hint
如描述
*/