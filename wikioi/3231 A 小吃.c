# include <stdio.h>
# include <string.h>
/*
题目描述 Description
这里简直是吃货的天堂，小吃太多了。数不胜数。
假设岛上有N种小吃，每种体积Vi，美味度Wi。
设某吃货旅行者的食量C,求他能吃到食品的最大美味度。
*/
int main()
{
	int c, n, i, j;
	scanf("%d %d", &n, &c);
	int f[c+1], w[n], v[n];
	memset(f, 0, sizeof(f));
	for(i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	for(i = 0; i < n; i++)
	{
		scanf("%d", &w[i]);
	}
	for(i = 0; i < n; i++)
	{
		for(j = c; j >= v[i]; j--)
			f[j] = f[j] > (f[j-v[i]] + w[i]) ? f[j] : (f[j-v[i]] + w[i]);
	}
	printf("%d\n", f[c]);

	return 0;
}

/* 
输入描述 Input Description
两个正整数N  C
N个正整数，Vi
N个正整数，Wi
输出描述 Output Description
最大美味值
样例输入 Sample Input
4 10
2 5 1 9
10 24 1 100
样例输出 Sample Output
101
数据范围及提示 Data Size & Hint
*/
