# include <stdio.h>
# include <string.h>
/*
题目描述 Description
平江路是苏州最美丽的道路，路中间的绿化带上种了两行漂亮的大树，每行50棵，一共100棵大树，这些大树被编上了号，编号方式如下：
1 3 5 7 ………… 45 47 49 …………99     第一行
2 4 6 8 ………… 46 48 50 …………100    第二行
但是昨天晚上却发生了一件令人震惊的大事--可恶的破坏分子竟然偷去了这100棵大树中的一部分！ 公安部门马上出动，列出了被偷去了大树的编号。
现在摆在我们面前的情况是，如果你带领的游客走过的旁边是空空的树坑，那是令人无法接受的，因此我们只能压缩游客在平江路上的旅游距离，务
必使游客在连续的大树边游玩，当时，我们就得找出一列（边）最长的连续的大树展现在游客面前。请你编写程序解决这一难题。
*/
int main()
{
	int s[2][50] = {{0}}, tree[100] = {0};
	int n, i, j, temp, max;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &temp), tree[temp-1] = 1;
	for(i = 0; i < 50; i++)
	{
		j = i;
		while(j < 50 && tree[j*2] == 0)
		{
			s[0][i] ++, j++;
		}
		j = i;
		while(j < 50 && tree[2 * j + 1] == 0)
		{
			s[1][i] ++, j++;
		}
	}
	max = s[0][0], temp = 0;
	for(i = 1; i < 50; i++)
	{
		if(max < s[0][i])
			max = s[0][i], temp = i * 2;
	}
	for(i = 0; i < 50; i++)
	{
		if(max < s[1][i])
			max = s[1][i], temp = 2 * i + 1;
	}
	printf("%d %d\n", temp + 1, max);

	return 0;
}

/*
输入描述 Input Description
N （表示有N棵大树被盗） N1 N2 N3……NN  （被盗大树的编号）
输出描述 Output Description
M X   （表示从第M棵大树开始，共有连续的X棵大树，如果有多个解，输出M最小的解即可）
样例输入 Sample Input
5 9 15 27 35 6
样例输出 Sample Output
8 47
数据范围及提示 Data Size & Hint
N<=100
*/
