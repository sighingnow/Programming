# include <stdio.h>
# include <string.h>
/*
题目描述 Description
数轴上有n条线段，线段的两端都是整数坐标，坐标范围在0~1000000，每条线段有一个价值，请从n条线段中挑出若干条线段，使得这些线段两两不覆盖
（端点可以重合）且线段价值之和最大。n<=1000
*/
long long f[1000], max;
struct lines
{
	int x, y, v;
}line[1000], temp;
int main()
{
	int n, i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d", &line[i].x, &line[i].y, &line[i].v);
	}
	for(i = 0; i < n; i++)              //对线段按下端点排序
	{
		for(j = 0; j < i; j++)
		{
			if(line[i].x < line[j].x)
			{
				temp = line[i], line[i] = line[j], line[j] = temp;
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		f[i] = line[i].v;         //关键
		for(j = 0; j < i; j++)          //注意是顺序
		{
			if(line[j].y <= line[i].x)
				f[i] = f[i] > (f[j]+ line[i].v) ? f[i] : (f[j] + line[i].v);
		}
	}
	max = f[0];
	for(i = 1; i < n; i++)
		max = max >= f[i] ? max : f[i];
	printf("%I64d\n", max);

	return 0;
}

/*
输入描述 Input Description
第一行一个整数n，表示有多少条线段。
接下来n行每行三个整数, ai bi ci，分别代表第i条线段的左端点ai，右端点bi（保证左端点<右端点）和价值ci。
输出描述 Output Description
输出能够获得的最大价值
样例输入 Sample Input
3
1 2 1
2 3 2
1 3 4
样例输出 Sample Output
4
数据范围及提示 Data Size & Hint
数据范围
对于40%的数据，n≤10；
对于100%的数据，n≤1000；
0<=ai,bi<=1000000
0<=ci<=1000000
*/
