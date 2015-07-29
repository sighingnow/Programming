#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define INF 0x7fffffffffffffff
using namespace std;
/*
题目描述 Description
平面上有n个点（n<=100），每个点的坐标均在-10000~10000之间。其中的一些点之间有连线。若有连线，则表示可从一个点到达另一个点，
即两点间有通路，通路的距离为两点间的直线距离。现在的任务是找出从一点到另一点之间的最短路径。
*/
int main(int argc, char **argv)		//Floyd
{
	float map[101][101], dist[101][101], posi[101][2];
	int s, t, n, m;

	for(int i = 0; i < 101; ++i)
	{
		for(int j = 0; j < 101; ++j)
		{
			map[i][j] = INF;
		}
		map[i][i] = 0;
	}

	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		scanf("%f %f", &posi[i][0], &posi[i][1]);
	}

	cin >> m;
	for(int i = 1; i <= m; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		map[v][u] = map[u][v] = sqrt((posi[u][0] - posi[v][0]) * (posi[u][0] - posi[v][0]) 
								   + (posi[u][1] - posi[v][1]) * (posi[u][1] - posi[v][1]));
	}
	scanf("%d %d", &s, &t);
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= n; ++j)
			dist[i][j] = map[i][j];
	}
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printf("%.2f", dist[s][t]);
	
	return 0;
}
/*
输入描述 Input Description
第一行为整数n。
第2行到第n+1行（共n行），每行两个整数x和y，描述了一个点的坐标。
第n+2行为一个整数m，表示图中连线的个数。
此后的m行，每行描述一条连线，由两个整数i和j组成，表示第i个点和第j个点之间有连线。
最后一行：两个整数s和t，分别表示源点和目标点。
输出描述 Output Description
仅一行，一个实数（保留两位小数），表示从s到t的最短路径长度。
样例输入 Sample Input
5
0 0
2 0
2 2
0 2
3 1
5
1 2
1 3
1 4
2 5
3 5
1 5
样例输出 Sample Output
3.41
数据范围及提示 Data Size & Hint
*/
