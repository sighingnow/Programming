# include <stdio.h>
/*
题目描述 Description
给定N（小于等于8）个点的地图，以及地图上各点的相邻关系，请输出用4种颜色将地图涂色的所有方案数（要求相邻两点不能涂成相同的
颜色）数据中0代表不相邻，1代表相邻
*/
int map[9][9], n, color[9], sum;
void search(int m)       //DFS
{
	int i, j;
	if(m > n)
		++sum;
	else
	{
		for(i = 1; i <= 4; ++i)
		{
			for(j = 1; j < m; ++j)
			{
				if(map[m][j] == 1 && color[j] == i)
					break;
			}
			if(j >= m)
			{
				color[m] = i;
				search(m+1);
			}
		}
	}
}
int main()
{
	int i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			scanf("%d", &map[i][j]);
	search(1);
	printf("%d\n", sum);

	return 0;
}

/*
输入描述 Input Description
第一行一个整数n，代表地图上有n个点
接下来n行，每行n个整数，每个整数是0或者1。第i行第j列的值代表了第i个点和第j个点之间是相邻的还是不相邻，相邻就是1，不相邻
就是0.
我们保证a[i][j] = a[j][i] （a[i,j] = a[j,i]）
输出描述 Output Description
染色的方案数
样例输入 Sample Input
8
0 0 0 1 0 0 1 0
0 0 0 0 0 1 0 1
0 0 0 0 0 0 1 0
1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0
1 0 1 0 0 0 0 0
0 1 0 0 0 0 0 0
样例输出 Sample Output
15552
数据范围及提示 Data Size & Hint
n<=8
*/
