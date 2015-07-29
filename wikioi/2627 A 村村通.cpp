# include <iostream>
# include <cstdio>
using namespace std;
/*
题目描述 Description		1078 最小生成树
农民约翰被选为他们镇的镇长！他其中一个竞选承诺就是在镇上建立起互联网，并连接到所有的农场。当然，他需要你的帮助。 约翰已经给
他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。为了使花费最少，他想铺设最短的光纤去连接所有的农场。 你将得
到一份各农场之间连接费用的列表，你必须找出能连接所有农场并所用光纤最短的方案。 每两个农场间的距离不会超过100000
*/
int map[105][105], ans, n;

void InitMap(void)
{
	int i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

void Prim(void)
{
	int v, u, i, j, t, minSpanTree[105], top = 1, isvisit[105] = {0};
	minSpanTree[top++] = 1, isvisit[1] = 1;
	for(t = 2; t <= n; ++t)
	{
		v = u = 0, map[v][u] = 0x7fffffff;
		for(i = 1; i < top; ++i)
		{
			for(j = 1; j <= n; ++j)
			{
				if(!isvisit[j] && map[minSpanTree[i]][j] < map[v][u])
				{
					v = minSpanTree[i], u = j;
				}
			}
		}
		isvisit[u] = 1;
		minSpanTree[top++] = u;
		ans += map[v][u];
	}
}

int main()				//prim 算法，MST 性质, 也可以用 Kruskal 算法
{
	InitMap();
	Prim();
	printf("%d", ans);

	return 0;
}

/*
输入描述 Input Description
第一行： 农场的个数，N（3<=N<=100）。
第二行..结尾: 接下来的行包含了一个N*N的矩阵,表示每个农场之间的距离。理论上，他们是N行，每行由N个用空格分隔的数组成，实际上
，他们每行限制在80个字符以内，因此，某些行会紧接着另一些行。当然，对角线将会是0，因为线路从第i个农场到它本身的距离在本题
中没有意义。
输出描述 Output Description
只有一个输出，是连接到每个农场的光纤的最小长度和。
样例输入 Sample Input
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
样例输出 Sample Output
28
数据范围及提示 Data Size & Hint
*/
