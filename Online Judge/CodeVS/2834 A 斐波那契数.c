# include <stdio.h>
# include <string.h>
/*
题目描述 Description
小X是个聪明的孩子，他记得斐波那契数列f(n)中前1000个数。不过由于学业的压力，他无法记得每一个数在数列中的位置。
他现在知道斐波那契数列中的一个数f(x)模P后的值N（即f(x) mod P=N）以及x可能的最大值M，如果再对于斐波那契数列中每一个数都模P，他想知道这个数可能出现在第几个。
不过小X还要做作业呢，这个问题就交给你由编程来解决了。
*/
int main()
{
	int n, p, m, x, y, z, i;
	scanf("%d %d %d", &n, &p, &m);
	x = 1, y = 1;
	if(n == 0)
	{
		printf("0");
		return 0;
	}
	if(n == 1)
	{
		printf("1");
		return 0;
	}
	for(i = 3; i <= m; i++)
	{
		z = x + y;
		x = y;
		y = z % p;
		if(y == n)
		{
			printf("%d", i);
			break;
		}
	}
	if(i > m)
		printf("-1");
	
	return 0;
}

/*
输入描述 Input Description
一行，共3个整数，第一个数为N，第二个数为P，第三个数为x可能的最大值M，三个数以空格隔开。
输出描述 Output Description
一个整数，满足f(i) mod P = N的最小的i，如果不存在则输出-1。
样例输入 Sample Input
3 7 5
样例输出 Sample Output
4
数据范围及提示 Data Size & Hint
对于20%的数据，保证0＜M≤50
对于50%的数据，保证0＜M≤100
对于70%的数据，保证0＜M≤500
对于100%的数据，保证0＜M≤1000，0≤N<P，P为素数且2<P<105。
*/
