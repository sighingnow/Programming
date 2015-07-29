# include <stdio.h>
# include <string.h>
/*
题目描述 Description
话说上回他给女孩送了n件礼物，由于是廉价的所以全部都坏掉了，女孩很在意这些礼物，所以决定自己缝补，但是人生苦短啊，女孩时间有限，
她总共有m分钟能去缝补礼物。由于损坏程度不一样所以缝补的时间p也是不一样的，每件礼物呢，都有一个女孩的喜爱程度为w，后面还有一个
数字h为这种礼物的件数。女孩想让自己的喜爱程度的和最大，那么请聪明的你帮她算一算！（注意：礼物非常多，不一定都能缝补完，女孩也
不用把所有时间都花费）
*/
int main()
{
	int m, n, i, j, k;
	scanf("%d %d", &m, &n);
	int f[m+1], p, w, h;
	memset(f, 0, sizeof(f));
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d", &p, &w, &h);
		for(k = 0; k < h; k++)
		{
			for(j = m; j >= p; j--)
			{
				f[j] = f[j] > (f[j-p] + w) ? f[j] : (f[j-p] + w);
			}
		}
	}
	printf("%d\n", f[m]);
	
	return 0;
}

/*
输入描述 Input Description
第1行2个整数 m,n
第2行到第n+1行 每行三个整数 p，w，h
输出描述 Output Description
一个整数s表示最大的喜爱程度
样例输入 Sample Input
8 2
2 100 4
4 100 2
样例输出 Sample Output
400
 
数据范围及提示 Data Size & Hint
m<=10000
n<=100
p,h,w<=6000
*/
