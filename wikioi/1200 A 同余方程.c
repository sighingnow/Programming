# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description
求关于 x 同余方程 ax ≡ 1 (mod b)的最小正整数解。 
*/
int x, y;

void ex_gcd(int a, int b)
{
	if(b == 0)
	{
		x = 1, y = 0;
	}
	else
	{
		ex_gcd(b, a % b);
		int temp;
		temp = y, y = -(x + (a / b) * y), x = -temp;
	}
}

int main()          //思路：扩展欧几里德算法的思想，可以通过手算的方式寻求解题思路
{
	int a, b;
	scanf("%d %d", &a, &b);
	ex_gcd(a, b);
	while(x < 0)       //找到最小的正解
	{
		x += b;
	}
	printf("%d\n", x);

	return 0;
}

/*
输入描述 Input Description
输入只有一行，包含两个正整数 a, b，用 一个 空格隔开。 
输出描述 Output Description
输出只有一行包含一个正整数x0，即最小正整数解，输入数据保证一定有解。
样例输入 Sample Input
3 10 
样例输出 Sample Output
7
数据范围及提示 Data Size & Hint
【数据范围】
对于 40%  的数据， 2 ≤b≤ 1,000 ；
对于 60% 的数据， 2 ≤b≤ 50,000,000 
对于 100%  的数据， 2 ≤a, b≤ 2,000,000,000
*/
