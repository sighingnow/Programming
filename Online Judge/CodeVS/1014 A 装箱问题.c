# include <stdio.h>
# include <string.h>
/*
题目描述 Description
有一个箱子容量为V（正整数，0＜＝V＜＝20000），同时有n个物品（0＜n＜＝30），每个物品有一个体积（正整数）。
要求n个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。
*/
int main(void)
{
	int n, v, i, j;
	scanf("%d %d", &v, &n);
	int w[n], f[v+1];
	memset(f, 0, sizeof(f[0]) * (v + 1));
	//思路：用f[v]才存储以v为上限时所剩余的体积
	/*DP:
	如果不放第i件物品，那么问题就转化为“前i-1件物品放入容量为v的背包中”，价值为f[i-1][v]；如果放第i件物品，
	那么问题就转化为“前i-1件物品放入剩下的容量为v-c[i]的背包中”，此时能获得的最大价值就是f [i-1][v-c[i]]再加上通过放入第i件物品
	获得的价值w[i]。
	*/
	for(i = 0; i < n; i++)
	{
		scanf("%d", &w[i]);
		for(j = v; j >= w[i]; j--)
		{
			f[j] = f[j] > (f[j - w[i]] + w[i]) ? f[j] : (f[j - w[i]] + w[i]);
		}
	}
	printf("%d\n", v - f[v]);

	return 0;
}


/*
输入描述 Input Description
一个整数v，表示箱子容量
一个整数n，表示有n个物品
接下来n个整数，分别表示这n 个物品的各自体积
输出描述 Output Description
一个整数，表示箱子剩余空间。
样例输入 Sample Input
24
6
8
3
12
7
9
7
样例输出 Sample Output
0
数据范围及提示 Data Size & Hint
*/
