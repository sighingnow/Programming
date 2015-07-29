# include <stdio.h>
# include <string.h>
/*
题目描述 Description
下午，CYD要刷题了，已知CYD有N题可刷，但他只有M分钟的时间，而且他的智慧值为Q，也就是说他只能做出难度小于等于Q的题目。
已知每题可得积分Ai，需花费时间Bi，难度为Ci，问CYD最多可得多少积分。
*/
int main()
{
	int n, m, q, i, j;
	scanf("%d %d %d", &n, &m, &q);
	int f[m+1], a[n], b[n], c[n];
	memset(f, 0, sizeof(f[0])*(m+1));
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		if(c[i] <= q)
		{
			for(j = m; j >= b[i]; j--)
			{
				f[j] = f[j] > (f[j-b[i]] + a[i]) ? f[j] : (f[j-b[i]] + a[i]);
			}
		}
	}
	printf("%d\n", f[m]);

	return 0;
}

/*
输入描述 Input Description
N  M  Q
Ai Bi Ci
输出描述 Output Description
可得最多积分
样例输入 Sample Input
4  20  10
20 3 7
30 7 9
30 1 11
20 17 6
样例输出 Sample Output
50
数据范围及提示 Data Size & Hint
【样例解释】
选第1题和第2题
【数据范围】
对于33%的数据  N≤20 M≤100 Q≤20
对于100%的数据 N≤50 M≤500 Q≤100 AiBiCi≤300
*/
