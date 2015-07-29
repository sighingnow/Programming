# include <stdio.h>
# include <string.h>
/*
题目描述 Description
CYD吃饭时有N个骨头可以啃，但CYD要午睡了，所以他只有M分钟吃饭，已知啃每个骨头需花费时间Ai，可以得到Bi个单位的营养。
问CYD最多得到多少营养。
*/
int main()
{
	int m, n, i, j;
	scanf("%d %d", &m, &n);
	int f[m+1], a, b;
	memset(f, 0, sizeof(f));
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		for(j = m; j >= a; j--)
		{
			f[j] = f[j] > (f[j-a] + b) ? f[j] : (f[j-a] + b);
		}
	}
	printf("%d\n", f[m]);

	return 0;
}

/*
输入描述 Input Description
M  N
A1 B1
A2 B2
……
AN BN
输出描述 Output Description
得到的最大营养值
样例输入 Sample Input
10  3
5  20
3  15
8  29
样例输出 Sample Output
35
数据范围及提示 Data Size & Hint
 对于100%的数据  N≤100  M≤1000  Ai，Bi≤100
 */
