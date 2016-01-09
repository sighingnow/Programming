# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description        1675 大质数 2
小明因为没做作业而被数学老师罚站，之后数学老师要他回家把第n个质数找出来。
小明于是交给聪明的你。请你帮忙！【wikioi-1530】
…………………………以上为背景…………………………
老师怀疑小明仅仅是找到第n个质数，于是又叫小明把1到n以内（不包括n）的质数全部找出来。小明又找到了你……
*/
int ispri(int n)
{
	int i, k;
	k = sqrt(n);
	for(i = 2; i <= k; i++)
	{
		if(n % i == 0)
			break;
	}
	if(i > k)
		return 1;
	else
		return 0;
}
int main()
{
	int n, i, j, temp;
	scanf("%d", &n);
	if(n <= 6)
	{
		if(n == 1 || n == 2)
		return 0;
		else if(n == 3)
		{
			printf("2\n");
			return 0;
		}
		else if(n == 4 || n == 5)
		{
			printf("2\n3\n");
			return 0;
		}
		else if(n == 6)
		{
			printf("2\n3\n5\n");
			return 0;
		}
	}
	else
	{
		printf("2\n3\n5\n");
		for(i = 5; i < n; i += 2)
		{
			temp = i % 10;
			if(temp == 1 || temp == 3 || temp == 7 || temp == 9)
			{
				if(ispri(i) == 1)
					printf("%d\n", i);
			}
		}
	}

	return 0;
}

/*
输入描述 Input Description
一个正整数n。
（1<=n<=1000000)
输出描述 Output Description
n以内的质数，每个一行。
样例输入 Sample Input
233
样例输出 Sample Output
2
3
5
7
11
13
17
19
23
29
31
37
41
43
47
53
59
61
67
71
73
79
83
89
97
101
103
107
109
113
127
131
137
139
149
151
157
163
167
173
179
181
191
193
197
199
211
223
227
229          //（不含n=233）
数据范围及提示 Data Size & Hint
注意优化算法
*/
