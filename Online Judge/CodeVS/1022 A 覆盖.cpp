#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
/*
有一个N×M的单位方格中，其中有些方格是水塘，其他方格是陆地。如果要用1×2的矩阵区覆盖（覆盖过程不容许有任何部分重叠）这个陆
地，那么最多可以覆盖多少陆地面积。
*/
/*建图：
首先把所有被水塘覆盖的点排除，即接下来所有动作都与其无关
然后设想这是一个图，每个格子是一个节点，与它周围（上下左右）的格子有一条无权的无向边
*/
void initMap(int n, int m, int k, int & numPoint, int map[][5])
{
	bool posi[101][101] = {{false}};
	int order[101][101] = {{0}};
	for(int i = 1; i <= k; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		posi[x][y] = true;
	}
	for(int i = 1; i <= n; ++i)//对点进行标号
	{
		for(int j = 1; j <= m; ++j)
		{
			if(!posi[i][j])
				order[i][j] = ++numPoint;
		}
	}
	for(int i = 1; i <= n; ++i)//构成邻接表
	{
		for(int j = 1; j <= m; ++j)
		{
			if(!posi[i][j])
			{
				if(i-1 > 0 && !posi[i-1][j])
					map[order[i][j]][++map[order[i][j]][0]] = order[i-1][j];
				if(j-1 > 0 && !posi[i][j-1])
					map[order[i][j]][++map[order[i][j]][0]] = order[i][j-1];
				if(j+1 <= m && !posi[i][j+1])
					map[order[i][j]][++map[order[i][j]][0]] = order[i][j+1];
				if(i+1 <= n && !posi[i+1][j])
					map[order[i][j]][++map[order[i][j]][0]] = order[i+1][j];
			}
		}
	}
}

bool dfs(int t, int m, bool *isVisit, int *link, int map[][5])//dfs算法寻找增广路径
{
	if(map[t][0])
	{
		for(int i = 1; i <= map[t][0]; ++i)
		{
			if(!isVisit[map[t][i]])
			{
				isVisit[map[t][i]] = 1;
				if(link[map[t][i]] == -1 || dfs(link[map[t][i]], m, isVisit, link, map))
				{
					link[map[t][i]] = t;
					return true;
				}
			}
		}
	}
	return false;
}
int Hungarian(int n, int m, int map[][5])
{
	bool isVisit[m+1];
	int link[m+1], ans = 0;
	memset(link, 0xff, sizeof(link));
	memset(isVisit, 0, sizeof(isVisit));
	for(int i = 1; i <= n; ++i)
	{
		memset(isVisit, 0, sizeof(isVisit));
		if(dfs(i, m, isVisit, link, map))
			++ans;
	}
	return ans / 2; //在计算过程中，每个匹配都算了两次
}

int main()//Hungarian算法，max_match
{
	//静态邻接表表示无向图，map[i][0]记录地 i 个点的邻接点数目,numPoint为陆地块的个数，即为点的数目
	int map[10001][5] = {{0}}, numPoint = 0;
	int n, m, k, ans;
	cin >> n >> m >> k;
	initMap(n, m, k, numPoint, map);
	ans = Hungarian(numPoint, numPoint, map);
	cout << ans << endl;

	return 0;
}

/*
输入描述 Input Description
输入文件的第一行是两个整数N，M  (1<=N，M<=100)，第二行为一个整数K( K<=50)，接下来的K行，每行两个整数X，Y表示K个水塘的行列位
置。(1<=X<=N，1<=Y<=M)。
输出描述 Output Description
输出所覆盖的最大面积块（1×2面积算一块）。
样例输入 Sample Input
4 4
6
1 1
1 4
2 2
4 1
4 2
4 4
样例输出 Sample Output
4
数据范围及提示 Data Size & Hint
见描述
*/
