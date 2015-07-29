# include <stdio.h>
# include <string.h>
/*
题目描述 Description
背包体积为V ,给出N个物品，每个物品占用体积为Vi,价值为Wi,每个物品要么至多取1件，要么至多取mi件（mi > 1） , 要么数量无限 ， 
在所装物品总体积不超过V的前提下所装物品的价值的和的最大值是多少？
*/
int main()
{
	int v, n, i, j;
	scanf("%d %d", &n, &v);
	int f[v+1], vi, wi, mi;
	memset(f, 0, sizeof(f));
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d", &vi, &wi, &mi);
		if(mi == -1)          //完全背包的处理
		{
			for(j = vi; j <= v; j++)
			{
				f[j] = f[j] > (f[j-vi] + wi) ? f[j] : (f[j-vi] + wi);
			}
		}
		else if(mi == 1)      //0-1背包的处理
		{
			for(j = v; j >= vi; j--)
			{
				f[j] = f[j] > (f[j-vi] + wi) ? f[j] : (f[j-vi] + wi);
			}
		}
		else                   //多重背包的处理，需要优化
		{
			int  s[mi][2], k = 1, t = 0;
			while(1)
			{
				if(mi <= k)
				{
					s[t][0] = mi * vi, s[t++][1] = mi * wi;
					break;
				}
				else
				{
					s[t][0] = k * vi, s[t++][1] = k * wi;
				}
				mi = mi - k;
				k = k * 2;
			}
			while(t--)
			{
				for(j = v; j >= s[t][0]; j--)
				{
					f[j] = f[j] > (f[j-s[t][0]] + s[t][1]) ? f[j] : (f[j-s[t][0]] + s[t][1]);
				}
			}
		}
	}
	printf("%d\n", f[v]);

	return 0;
}

/*
输入描述 Input Description
第一行两个数N,V,下面N行每行三个数Vi,Wi,Mi表示每个物品的体积，价值与数量，Mi=1表示至多取一件，Mi>1表示至多取Mi件，Mi=-1表示数量无限
输出描述 Output Description
1个数Ans表示所装物品价值的最大值
样例输入 Sample Input
2 10
3 7 2
2 4 -1
样例输出 Sample Output
22
数据范围及提示 Data Size & Hint
对于100%的数据,V <= 200000 , N <= 200
*/
