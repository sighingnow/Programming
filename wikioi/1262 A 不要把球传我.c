# include <stdio.h>
# include <string.h>
/*
题目描述 Description
CCC的足球比赛和传统的足球比赛有一点不同， 一次进球当且仅当先后接触到球的4名队员的球衣编号是升序排列的。
球员的球衣编号从过1到99，并且每个人的编号都不同。
给出最后得分球员的球衣编号，请计算出有多少合法的球员组合能够产生这一进球。
*/
int buf[4], total, n;
void search(int m)
{
	int i;
	if(m == 3)
		total ++;
	else
	{
		for(i = buf[m]-1; i >= 3-m; i--)
		{
			buf[m+1] = i;
			search(m+1);
		}
	}
}

int main()
{
	scanf("%d", &buf[0]);
	if(buf[0] < 4)
		printf("0\n");
	else
	{
		search(0);
		printf("%d\n", total);
	}

	return 0;
}

/*
输入描述 Input Description
输入一个整数1<=J<=99，代表进球球员的球衣编号
输出描述 Output Description
输出只有一行，包含一个整数代表有多少种组合能够使得最后进球的球员编号为J。
样例输入 Sample Input
样例输入 1： 4
样例输入 2： 2
样例输入 3： 90
样例输出 Sample Output
样例输出 1： 1
样例输出 2： 0
样例输出 3： 113564
数据范围及提示 Data Size & Hint
无
*/
