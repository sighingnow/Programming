#include <iostream>
#include <cstdio>
using namespace std;

#define read(x) {char ch;\
				 x = 0;\
				 while((ch = getchar()) > '9' || ch < '0');\
			     x = ch - '0';\
                 while((ch = getchar()) <= '9' && ch >= '0')\
					x = x * 10 + (ch - '0');\
				 }

/*
题目描述 Description
已知n个点(n<=100)，给你n*n的方阵，a[i,j]表示从第i个点到第j个点的直接距离。        
现在有Q个询问，每个询问两个正整数，a和b，让你求a到b之间的最短路程。        
满足a[i,j]=a[j,i];
输入描述 Input Description
 第一行一个正整数n，接下来n行每行n个正整数，满足a[i,i]=0,再一行一个Q，接下来Q行，每行两个正整数a和b。
*/
int main(int argc, char **argv)
{
	int n, map[101][101] = {{0}}, dist[101][101] = {{0}};
	read(n);
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			read(map[i][j]);
	}
	
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			dist[i][j] = map[i][j];
	}

	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
				dist[i][j] = dist[i][j] < (dist[i][k] + dist[k][j]) 
					       ? dist[i][j] : (dist[i][k] + dist[k][j]);
		}
	}
	
	
	int q, u, v;
	read(q);
	for(int i = 1; i <= q; ++i)
	{
		read(u); read(v);
		printf("%d\n", dist[u][v]);
	}

	return 0;
}
/*
输入描述 Input Description
 第一行一个正整数n，接下来n行每行n个正整数，满足a[i,i]=0,再一行一个Q，接下来Q行，每行两个正整数a和b。
输出描述 Output Description
一共Q行，每行一个整数。
样例输入 Sample Input
3
0 1 1
1 0 3
1 3 0
1
2 3
样例输出 Sample Output
2
数据范围及提示 Data Size & Hint
n<=100，Q可能非常大。g[i][j]均>=0
请使用flyod算法
使用C/C++的同学请注意：由于输入数据较大，使用cin和cout会导致程序超时。请使用scanf与printf进行输入和输出。
*/
