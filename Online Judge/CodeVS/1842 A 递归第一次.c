# include <stdio.h>
/*
题目描述 Description
同学们在做题时常遇到这种函数
f(x)=5 (x>=0)
f(x)=f(x+1)+f(x+2)+1 (x<0)
下面就以这个函数为题做一个递归程序吧
*/
int f(int x)
{
	if(x >= 0)
		return 5;
	else
		return (f(x + 1)+f(x + 2) + 1);
}
int main()
{
	int x;
	scanf("%d", &x);
	printf("%d\n", f(x));

	return 0;
}

/*
输入描述 Input Description
一个数表示f(x)中x值
大家注意就一个数，前面代表样例编号
输出描述 Output Description
一个数表示值
大家注意就一个数，前面代表样例编号
样例输入 Sample Input
样例一：0
样例二：-5
样例输出 Sample Output
样例一：5
样例二：77
数据范围及提示 Data Size & Hint
x>=-30
*/
