# include <stdio.h>
# include <string.h>
/*
题目描述 Description
德国放松对英国的进攻后，把矛头指向了东北——苏联。 1943年初，东线的站头进行到白热化阶段。据可靠情报，90余万德国军队在库尔斯克
准备发动好大的攻势。因此，朱可夫元帅要求你立即从远东的军工厂运输大量装备支援库尔斯克前线。 列车司机告诉你，一趟列车最多可以
容纳V体积的武器装备，但是你可能不能装满，因为列车承受不了那么大的重量，一趟列车最多可以承载G单位的重量。同时，军工厂仓库提供
给你一份装备清单，详细记录了每件装备的体积、重量和火力。为了有效支援朱可夫元帅，你要找到一种方案，使得总火力值最大。
*/
int main()            //二维动态规划
{
	int v, g, n, i, j, k;
	scanf("%d %d %d", &v, &g, &n);
	int f[v+1][g+1], ti, vi, gi;
	memset(f, 0, sizeof(f));
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d", &ti, &vi, &gi);
		for(j = v; j >= vi; j--)
		{
			for(k = g; k >= gi; k--)
			{
				f[j][k] = f[j][k] > (f[j-vi][k-gi] + ti) ? f[j][k] : (f[j-vi][k-gi] + ti);
			}
		}
	}
	printf("%d\n", f[v][g]);

	return 0;
}

/*
输入描述 Input Description
第一行：V和G表示最大重量和体积。 第二行：N表示仓库有N件装备； 第三到N+2行：每行3个数Ti  Vi  Gi表示个装备的火力值、体积和重量；
输出描述 Output Description
输出一个数，表示可能获得的最大火力值
样例输入 Sample Input
6 5
4
10 2  2
20 3  2
40  4  3
30  3  3
样例输出 Sample Output
50
数据范围及提示 Data Size & Hint
【数据范围】
对于50%的数据，V,G,N≤100
对于100%的数据，V,G,N≤1000
*/
