# include <stdio.h>
/*
题目描述 Description
输入n个互不相同的正整数，若其中两个数a和b满足a=2*b，则称为一对“倍数”。编程统计倍数的对数。注意若存在a=2*b和b=2*c，记为2对，
即整数b可重复使用。
*/
int main()
{
	int n, flag[10001] = {0}, i, sum = 0;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &i);
		flag[i] = 1;
	}
	for(i = 1; i <= 5000; ++i)
	{
		if(flag[i] && flag[2 * i])
			sum ++;
	}
	printf("%d", sum);

	return 0;
}
/*
输入描述 Input Description
输入文件有两行，第一行为正整数n(≤1000)，第二行为以空格隔开的n个正整数ai(≤10000)。
输出描述 Output Description
输出仅包含一个整数，表示倍数的对数。
样例输入 Sample Input
4
2 4 8 10
样例输出 Sample Output
2
数据范围及提示 Data Size & Hint
100%数据：n≤1000，ai≤10000。
*/
