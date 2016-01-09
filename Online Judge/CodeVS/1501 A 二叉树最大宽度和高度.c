# include <stdio.h>
# include <string.h>
/*
题目描述 Description
给出一个二叉树，输出它的最大宽度和高度。
*/
struct tree
{
	int num;
	struct tree *pl, *pr;
} s[17];

int high[17], wide[17];

int main()
{
	int n, i;
	int temp1, temp2;
	int max_high = 0, max_wide = 0;
	scanf("%d", &n);
	memset (s, 0, sizeof(struct tree) * 17);
	high[1] = 1;
	s[1].num = 1;
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d", &temp1, &temp2);
		s[i].pl = &s[temp1], s[i].pr = &s[temp2];
		s[i].pl -> num = temp1, s[i].pr -> num = temp2;
		high[s[i].pl -> num] = high[i] + 1;
		high[s[i].pr -> num] = high[i] + 1;
	}
	/*
	输入的另一种写法为：
	for(i = 1; i <= n; i++)
	{
		s[i].num = i;
		scanf("%d %d", &temp1, &temp2);
		high[temp1] = high[i] + 1;
		high[temp2] = high[i] + 1;
	}
	*/
	for(i = 1; i <= n; i++)
	{
		if(max_high < high[i])
		{
			max_high = high[i];
		}
		wide[high[i]] ++;
	}
	for(i = 1; i <= 16; i++)
	{
		if(max_wide < wide[i])
		{
			max_wide = wide[i];
		}
	}
	printf("%d %d\n", max_wide, max_high);

	return 0;
}

/*
输入描述 Input Description
第一行一个整数n。
下面n行每行有两个数，对于第i行的两个数，代表编号为i的节点所连接的两个左右儿子的编号。如果没有某个儿子为空，则为0。
输出描述 Output Description
输出共一行，输出二叉树的最大宽度和高度，用一个空格隔开。
样例输入 Sample Input
5
2 3
4 5
0 0
0 0
0 0
样例输出 Sample Output
2 3
数据范围及提示 Data Size & Hint
n<16
默认第一个是根节点
以输入的次序为编号
2-N+1行指的是这个节点的左孩子和右孩子
注意：第二题有极端数据！
1
0 0
这题你们别想投机取巧了，给我老老实实搜索！
*/
