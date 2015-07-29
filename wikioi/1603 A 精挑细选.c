# include <stdio.h>
/*
题目描述 Description
小王是公司的仓库管理员，一天，他接到了这样一个任务：从仓库中找出一根钢管。这听起来不算什么，但是这根钢管的要求可真是让他
犯难了，要求如下：
1、 这根钢管一定要是仓库中最长的；
2、 这根钢管一定要是最长的钢管中最细的；
3、 这根钢管一定要是符合前两条的钢管中编码最大的（每根钢管都有一个互不相同的编码，越大表示生产日期越近）。
相关的资料到是有，可是，手工从几百份钢管材料中选出符合要求的那根…… 
要不，还是请你编写个程序来帮他解决这个问题吧。
*/
int main()
{
	int n, i, maxlen = 0, minthin = 0, maxnum = 0, len, thin, num;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d", &len, &thin, &num);
		if(len > maxlen)
		{
			maxlen = len, minthin = thin, maxnum = num;
		}
		else if(len == maxlen)
		{
			if(thin < minthin)
			{
				maxlen = len, minthin = thin, maxnum = num;
			}
			else if(thin == minthin)
			{
				if(num > maxnum)
					maxlen = len, minthin = thin, maxnum = num;
			}
		}
	}
	
	printf("%d\n", maxnum);

	return 0;
}

/*
输入描述 Input Description
文件第一行为一个整数 n，表示仓库中所有钢管的数量。
之后n行，每行三个整数，分别表示一根钢管的长度（以毫米为单位）、直径（以毫米为单位）和编码（一个9位整数）。
输出描述 Output Description
只有一个9位整数，表示选出的那根钢管的编码。
样例输入 Sample Input
4
3000 50 872198442
3000 45 752498124
2000 60 765128742
3000 45 652278122
样例输出 Sample Output
752498124
数据范围及提示 Data Size & Hint
n<=1000
*/
