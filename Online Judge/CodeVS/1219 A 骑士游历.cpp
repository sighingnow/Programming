#include <iostream>
using namespace std;
/*
题目描述 Description
设有一个n*m的棋盘（2≤n≤50，2≤m≤50），如下图，在棋盘上有一个中国象棋马。
规定：
1)马只能走日字
2)马只能向右跳
问给定起点x1,y1和终点x2,y2，求出马从x1,y1出发到x2,y2的合法路径条数。示的数字三角形，从顶部出发，在每一结点可以选择向
左走或得向右走，一直走到底层，要求找出一条路径，使路径上的值最大。
*/
long long ans[55][55];

int main(int argc, char **argv)
{
	int n, m;
	int x1, y1, x2, y2;
	cin >> n >> m;
	cin >> x1 >> y1 >> x2 >> y2;
	ans[x1][y1] = 1;
	for(int i = x1 + 1; i <= x2; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(i-2 >= 1 && j-1 >= 1)
				ans[i][j] += ans[i-2][j-1];
			if(i-2 >= 1 && j+1 <= m)
				ans[i][j] += ans[i-2][j+1];
			if(i-1 >= 1 && j-2 >= 1)
				ans[i][j] += ans[i-1][j-2];
			if(i-1 >= 1 && j+2 <= m)
				ans[i][j] += ans[i-1][j+2];
		}
	}
	cout << ans[x2][y2];
	return 0;
}
/*
输入描述 Input Description
第一行2个整数n和m
第二行4个整数x1,y1,x2,y2
输出描述 Output Description
输出方案数
样例输入 Sample Input
30 30
1 15 3 15
样例输出 Sample Output
2
数据范围及提示 Data Size & Hint
2<=n,m<=50
*/
