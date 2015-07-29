# include <stdio.h>
# include <string.h>
/*
题目描述 Description
在一个圆上，有2*K个不同的结点，我们以这些点为端点，连K条线段，使得每个结点都恰好用一次。在满足这些线段将圆分成最少部分的
前提下，请计算有多少种连线的方法
*/
int main()    //Catalan数
{
	long long int ans = 1;
	int i, k;
	scanf("%d", &k);
	if(k > 1)
	{
		for(i = 2; i <= k; ++i)
			ans = ans * (4 * i - 2) / (i + 1);
	}
	printf("%I64d %d", ans, k + 1);

	return 0;
}

/*
题目描述 Description
在一个圆上，有2*K个不同的结点，我们以这些点为端点，连K条线段，使得每个结点都恰好用一次。在满足这些线段将圆分成最少部分的
前提下，请计算有多少种连线的方法
输入描述 Input Description
仅一行，一个整数K(1<=K<=30)
输出描述 Output Description
两个用空格隔开的数，后者为最少将圆分成几块，前者为在此前提下连线的方案数
样例输入 Sample Input
2
样例输出 Sample Output
2 3
数据范围及提示 Data Size & Hint
见题目
*/
