#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
/*
题目描述 Description
集合论与图论对于小松来说是比数字逻辑轻松，比数据结构难的一门专业必修课。虽然小松在高中的时候已经自学过了离散数学中的图论，组合，
群论等知识。但对于集合论，小松还是比较陌生的。集合论的好多东西也涉及到了图论的知识。在第四讲的学习中，小松学到了“有序对”这么一
个概念，即用<x, y>表示有序对x和y。要注意的是有序对<x, y>不等于有序对<y, x>。对于一个有序对集合R={<x,y>, <y, z>, <x,  z>，……}，我们
说R是传递的，当且仅当他满足下面的性质：
红色字体用直观的语言描述是：如果存在<x, y>∈R，<y, z>∈R，那么一定存在<x, z>∈R。
这里集合R可以对应到一个有向图G，有序对<x ,y>对应到了G中的一条有向边。 你现在的任务是，对于任意给定的一个简单有向图G（同一有向边
不出现两次），判断G是否具有传递性。
*/
void init(int m, bool map[][1005])
{
	int a, b;
	memset(map, 0, sizeof(map[0][0]) * 1005 * 1005);
	while(m--)
	{
		scanf("%d%d", &a, &b);
		map[a][b] = true;
	}
}

bool judge(int n, bool map[][1005])
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(map[i][j])
			{
				for(int k = 1; k <= n; ++k)
				{
					if(map[j][k] && !map[i][k])
						return false;
				}
			}
		}
	}
	return true;
}

int main(int argc, char **argv)
{
	int t, n, m;
	bool map[1005][1005];
	cin >> t;
	while(t--)
	{
		scanf("%d %d", &n, &m);
		init(m, map);
		if(judge(n, map))
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0;
}
/*
输入描述 Input Description
输入文件set.in第一行包含测试数据的个数T(1<=T<=10)。接下来T组测试数据，每组测试数据第一行包含两个个整数n和m（1<=n<=1000, n<=m<=
100000），表示G中元素个数和有向边的个数，接下来的m行每行2个整数x, y（1<=x,y<=n）表示x与y之间有一条有向边连接。
输出描述 Output Description
对于每组数据，如果G是传递的，你需要向输出文件set.out输出一行”Yes”, 否则输出一行”No”。
样例输入 Sample Input
2
3 3
1 2
1 3
2 3
4 5
1 2
1 3
1 4
2 3
3 4
样例输出 Sample Output
Yes
No
数据范围及提示 Data Size & Hint
有30%满足1<=n<=100, 1<=m<=10000;
有100%的数据满足1<=n<=1000, 1<=m<=100000;
*/
