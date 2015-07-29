# include <stdio.h>
# include <string.h>
/*
题目描述 Description
Aiden马上要考试了，可他还没怎么复习，于是他决定临时抱佛脚。他列了N个知识点，并分析出了复习每个知识点所需的时间t以及可能获得的分数k。
他现在还有T时间来复习，他希望选择正确的知识点来在最短的时间内获得最高的期望分数。
*/
int main()
{
	int n, t, i, j;
	scanf("%d %d", &n, &t);
	int f[t+1], x, y;
	memset(f, 0, sizeof(f));
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		for(j = t; j >= x; j--)
		{
			f[j] = f[j] > (f[j-x]+y) ? f[j] : (f[j-x]+y);
		}
	}
	printf("%d\n", f[t]);

	return 0;
}

/*
输入描述 Input Description
第一行，两个数，分别为N、T。
接下来的N行，每行两个数t、k，表示一个知识点所需的时间和期望得分。
输出描述 Output Description
一行，一个数，表示可以获得的最高期望得分。
样例输入 Sample Input
3 5
3 5
3 2
2 2
样例输出 Sample Output
7
数据范围及提示 Data Size & Hint
对于10%的数据，0<N≤10，0<T≤100。
对于50%的数据，0<N≤1000，0<T≤10000。
对于100%的数据，0<N≤5000，0<T≤10000，0<t,k≤1000。
*/
