# include <stdio.h>
# include <string.h>
/*
题目描述 Description
有n堆石子排成一列，每堆石子有一个重量w[i], 每次合并可以合并相邻的两堆石子，一次合并的代价为两堆石子的重量和w[i]+w[i+1]。
问安排怎样的合并顺序，能够使得总合并代价达到最小。
*/
int stone[105], n, t, ans;
void combine(int k)             //后缀树优化可实现 n*log n;
{
	int i, tmp = stone[k] + stone[k-1];
	ans += tmp, t--;
	for(i = k; i < t; ++i)
		stone[i] = stone[i+1];
	for(i = k - 1; i > 1 && tmp > stone[i-1]; --i)
		stone[i] = stone[i-1];
	stone[i] = tmp;
	while(i >= 3 && stone[i-2] <= stone[i])
	{
		combine(--i);
	}
}

int main()     //GarsiaWachs算法
{
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
		scanf("%d", stone+i);
	t = 3, ans = 0;
	for(i = 3; i <= n; ++i)
	{
		stone[t++] = stone[i];
		while(t > 3 && stone[t-3] <= stone[t-1])
			combine(t-2);
	}
	while(t > 2)
		combine(t - 1);
	printf("%d\n", ans);

	return 0;
}

/*
输入描述 Input Description
第一行一个整数n（n<=100）
第二行n个整数w1,w2...wn  (wi <= 100)
输出描述 Output Description
一个整数表示最小合并代价
样例输入 Sample Input
4
4 1 1 4
样例输出 Sample Output
18
数据范围及提示 Data Size & Hint
*/
