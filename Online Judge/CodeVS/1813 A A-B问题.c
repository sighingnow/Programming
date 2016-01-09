# include <stdio.h>
# define abs(a) (a) > 0 ? (a) : (-a)
/*
题目描述 Description
给出一个A/B-C/D表示的分数减法算式，A，B，C，D均为不超过32767的正整数，求A/B-C/D的差，若差为整数，则输出这个整数；若差为分数，
则按A/B格式输出；要求为最简分数，若差为负数，则在上述要求下最前面添加负号。
输入中A/B或C/D有可能不是最简分数，但是你的输出必须是最简分数。
*/
int gcd(int a, int b)
{
	int c;
	while(a % b != 0)
	{
		c = a % b, a = b, b = c;
	}
	return b;
}
int main()
{
	char s[100], ch1, ch2, ch3;
	int x, y, gcd2;
	int n, a, b, c, d;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", s);
		sscanf(s, "%d%c%d%c%d%c%d", &a, &ch1, &b, &ch2, &c, &ch3, &d);
		y = b * d;
		x = a * d - b * c;
		if(x % y == 0)
			printf("%d\n", x / y);
		else
		{
			gcd2 = abs(gcd(x, y));
			printf("%d/%d\n", x / gcd2, y / gcd2);
		}
	}

	return 0;
}

/*
输入描述 Input Description
输入的第1行为一个正整数T，表示数据组数，
接下来T行，每行为按A/B-C/D格式给出的算式。 
输出描述 Output Description
输出包括T行，分别对于每个算式给出答案。
样例输入 Sample Input
3
1/3-1/2
10/4-2/2
3/2-1/2
样例输出 Sample Output
-1/6
3/2
1
数据范围及提示 Data Size & Hint
【数据规模】
对于30%的数据，有T≤10；
对于100%的数据，有T≤10000。
*/
