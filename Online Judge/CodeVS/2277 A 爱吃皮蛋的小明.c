# include <stdio.h>
# include <string.h>
/*
题目描述 Description
小明特别爱吃蛋，特别是皮蛋。他一次可以吃一个蛋或者两个蛋（整个吞下去），而且他喜欢吃得有花样，他想知道对于一定蛋的数量，有几种不同
的吃法。
*/
int main()             //分析：菲波那契数列
{
	int n;
	long long k1 = 1, k2 = 2, ans, i;
	scanf("%d", &n);
	if(n == 1)
		ans = 1;
	else if(n == 2)
		ans = 2;
	else
	{
		for(i = 0; i < n - 2; i++)
		{
			ans = k1 + k2, k1 = k2, k2 = ans;
		}
	}
	printf("%I64d\n", ans);

	return 0;
}

/*
输入描述 Input Description
一行一个整数N，表示皮蛋的数量
输出描述 Output Description
一行一个整数sum，表示吃法总数
样例输入 Sample Input
3
样例输出 Sample Output
3 
说明：有以下3种吃法
（1+1+1）
（1+2）
（2+1）
数据范围及提示 Data Size & Hint
0<N≤90
*/
