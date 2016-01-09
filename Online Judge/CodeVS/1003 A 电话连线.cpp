#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
题目描述 Description		1003 电话连线
一个国家有n个城市。若干个城市之间有电话线连接，现在要增加m条电话线（电话线当然是双向的了），使得任意两个城市之间都直接或间
接经过其他城市有电话线连接，你的程序应该能够找出最小费用及其一种连接方案。
*/
int main(int argc, char **argv)		//Prim
{
	int map[101][101];
	int isConnected[101] = {0};//标记是否被连接
	int n;
	int count = 0, sum = 0, ans = 0;
	int line[2][101];
	int connection[101];//记录被连接的顺序
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			scanf("%d", &map[i][j]);
		}
	}
	for(int i = 1; i <= n; ++i)//将与 1 点标记为已连接
	{
		if(!map[1][i])
		{
			isConnected[i] = 1;
			connection[count++] = i;
		}
	}
	
	while(count < n)
	{
		int u = 0, v = 0;
		map[0][0] = 0x3fffffff;
		for(int i = 0; i < count; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				if(!isConnected[j] && map[connection[i]][j] < map[u][v])
				{
					u = connection[i];
					v = j;
				}
			}
		}
		for(int i = 1; i <= n; ++i)
		{
			if(!map[i][v] && !isConnected[i])
			{
				isConnected[i] = 1;
				connection[count++] = i;
			}
		}
		line[0][ans] = u < v ? u : v;
		line[1][ans++] = u > v ? u : v;
	}
	cout << ans << endl;
	for(int i = 0; i < ans; ++i)
	{
		cout << line[0][i] << " " << line[1][i] << endl;
		sum += map[line[0][i]][line[1][i]];
	}
	cout << sum << endl;
	
	return 0;
}
/*
输入描述 Input Description
输入文件的第一行是n的值（n<=100）.
第二行至第n+1行是一个n*n的矩阵，第i行第j列的数如果为0表示城市i与城市j有电话线连接，否则为这两个城市之间的连接费用（范围不
超过10000）。
输出描述 Output Description
输出文件的第一行为你连接的电话线总数m，第二行至第m+1行为你连接的每条电话线，格式为i j，（i<j）， i j是电话线连接的两个城市。输
出请按照Prim算法发现每一条边的顺序输出，起始点为1.第m+2行是连接这些电话线的总费用。
样例输入 Sample Input
5
 0 15 27  6  0
15  0 33 19 11
27 33  0  0 17
 6 19  0  0  9
 0 11 17  9  0
样例输出 Sample Output
2
1 4
2 5
17
数据范围及提示 Data Size & Hint
n<=100
*/
