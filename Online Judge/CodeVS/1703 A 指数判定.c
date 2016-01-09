# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description   1703 指数判定
我们知道一个数字m, 它既可以是a的b次方, 也可以是c的d次方. 不难看出, a和c之间应该是(a, c)≠1. 现在给你m和a, 请你计算出b来.
*/
int main()
{
	int n;
	double m, a, x;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%lf %lf", &m, &a);
		x = log(m) / log(a);
		printf("%.3lf\n", x);
	}

	return 0;
}

/*
输入描述 Input Description
第1行为一个正整数n. 第2~n+1行每行包括两个正整数m和a.
输出描述 Output Description
共n行. 每行为一个小数点后三位实数b, 这个b满足a的b次方为m.
样例输入 Sample Input
2
4 9
357418 685
 
样例输出 Sample Output
0.631
1.958
 
数据范围及提示 Data Size & Hint
对于100%的数据, 1≤n≤10000, 1≤m≤214748364700, 1<a≤214748364700.
*/
