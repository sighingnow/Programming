# include <stdio.h>

/*
题目描述 Description
输入二个正整数x0,y0(2<=x0<100000,2<=y0<=1000000),求出满足下列条件的P,Q的个数
条件:  1.P,Q是正整数
2.要求P,Q以x0为最大公约数,以y0为最小公倍数.
试求:满足条件的所有可能的两个正整数的个数.
*/

int gcd(int a,int b)
{
	int temp;
	if(a<b)
	{
		temp = a; a = b; b = temp;	
	}
	if(a%b == 0)
		return b;
	else
		return gcd(a%b,b);
}
int mlc(int a,int b)
{
	return a * b / gcd(a,b);
}
int main()
{
	int x,y,t1,t2,temp,s;
	scanf("%d %d",&x,&y);
	temp = y / x;
	s = 0;
	for(t1 = 1; t1 <= temp; t1++)
	{
		for(t2 = 1; t2 <= temp; t2++)
		{
			if((mlc(t1*x,t2*x) == y) &&(gcd(t1*x,t2*x)) == x)
				s ++;
		}
	}
	printf("%d",s);
	
	return 0;
}
/*
输入描述 Input Description
二个正整数x0,y0
输出描述 Output Description
满足条件的所有可能的两个正整数的个数
样例输入 Sample Input
3 60
样例输出 Sample Output
4
*/
