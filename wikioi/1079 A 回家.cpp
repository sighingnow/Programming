# include <cstdio>
# include <iostream>
using namespace std;

# define INF 0x3fffffff
/*
题目描述 Description		1079 回家
现在是晚餐时间,而母牛们在外面分散的牧场中。 农民约翰按响了电铃,所以她们开始向谷仓走去。 你的工作是要指出哪只母牛会最先到
达谷仓(在给出的测试数据中,总会有且只有一只最快的母牛)。 在挤奶的时候(晚餐前),每只母牛都在她自己的牧场上,一些牧场上可能
没有母牛。 每个牧场由一条条道路和一个或多个牧场连接(可能包括自己)。 有时，两个牧场(可能是字母相同的)之间会有超过一条道
路相连。 至少有一个牧场和谷仓之间有道路连接。 因此,所有的母牛最后都能到达谷仓,并且母牛总是走最短的路径。 当然,母牛能向
着任意一方向前进,并且她们以相同的速度前进。 牧场被标记为'a'..'z'和'A'..'Y',在用大写字母表示的牧场中有一只母牛,小写字母中
则没有。 谷仓的标记是'Z',注意没有母牛在谷仓中。
注意'm'和'M'不是同一个牧场否则错误上面的意思是说：输入数据中可能会同时存在M,m（郁闷ing)，比如
M a a m m z
*/
int map[52][52];

void Init(void)
{
	char c1[5], c2[5];
	int i, k, p;
	scanf("%d", &p);
	for(i = 0; i < 52; ++i)
	{
		for(k = 0; k < 52; ++k)
			map[i][k] = INF;
		map[i][i] = 0;
	}
	for(i = 1; i <= p; ++i)
	{
		scanf("\n%s %s %d", c1, c2, &k);        //注意最前边的 '\n'
		if(c1[0] >= 'a')
			c1[0] -= ('a' - 'Z' - 1);
		if(c2[0] >= 'a')
			c2[0] -= ('a' - 'Z' - 1);
		if(c1[0] != c2[0] && map[c1[0]-'A'][c2[0]-'A'] > k)
		{
			map[c1[0]-'A'][c2[0]-'A'] = map[c2[0]-'A'][c1[0]-'A'] = k;
		}
	}
}

void Dijkstra(int v)
{
	int flag[52] = {0}, d[52], i, j, min;
	for(i = 0; i < 52; ++i)
		d[i] = map[v][i];
	flag[v] = 1;
	for(i = 1; i < 52; ++i)
	{
		int u = v, tmp = INF;
		for(j = 0; j <= 52; ++j)
		{
			if(!flag[j] && d[j] < tmp)
			{
				u = j;
				tmp = d[j];
			}
		}
		flag[u] = 1;
		for(j = 0; j < 52; ++j)
		{
			if(!flag[j] && map[u][j] < INF)
			{
				tmp = d[u] + map[u][j];
				if(tmp < d[j])
					d[j] = tmp;
			}
		}
	}
	min = 0;
	for(i = 0; i < 25; ++i)
	{
		if(i != v && d[i] < d[min])
			min = i;
	}
	printf("%c %d", min + 'A', d[min]);
}

int main()
{
	Init();
	Dijkstra('Z'-'A');

	return 0;
}
/*
输入描述 Input Description
第 1 行: 整数 P(1<= P<=10000),表示连接牧场(谷仓)的道路的数目。
第 2 ..P+1行:  用空格分开的两个字母和一个整数:
被道路连接牧场的标记和道路的长度(1<=长度<=1000)。
输出描述 Output Description
单独的一行包含二个项目:最先到达谷仓的母牛所在的牧场的标记,和这只母牛走过的路径的长度。
样例输入 Sample Input
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
样例输出 Sample Output
B 11
数据范围及提示 Data Size & Hint
*/
