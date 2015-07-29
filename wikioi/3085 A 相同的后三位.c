# include <stdio.h>
/*
题目描述 Description
对于给定的p，编写程序求最小正整数m,n(0＜n＜m)为何值时,pm与pn的最后三位数字相同。
*/
int flag[2][1000];
int main()
{
	int p, tmp = 1, i;
	scanf("%d", &p);
	for(i = 1;; ++i)
	{
		tmp = (tmp * p) % 1000;
		if(flag[0][tmp])
		{
			printf("%d %d\n", i, flag[1][tmp]);
			break;
		}
		else
		{
			flag[0][tmp] = 1;
			flag[1][tmp] = i;
		}
	}
	
	return 0;
}
/*
输入描述 Input Description
一个正整数p(100≤p≤9999)
输出描述 Output Description
一行，最小的m和n,m和n用空格隔开。如有多组,输出最小的m那组。
样例输入 Sample Input
100
样例输出 Sample Output
3 2
数据范围及提示 Data Size & Hint
100≤p≤9999
*/
