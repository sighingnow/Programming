# include <stdio.h>
/*
题目描述 Description
斐波纳契数列是这样的数列：
f1 = 1
f2 = 1
f3 = 2
f4 = 3
....
fn = fn-1 + fn-2
 
输入一个整数n
求fn
*/
int fi(int n)
{
	if(n <= 2)
		return 1;
	else
		return (fi(n-1) + fi(n-2));
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fi(n));

	return 0;
}

/*前边为递归写法，用循环的地推写法为：
int main()
{
	int f[40] = {1,1};
	int n, i;
	scanf("%d", &n);
	for(i = 2; i < 40; i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
	printf("%d\n", f[n-1]);

	return 0;
}

*/
/*
输入描述 Input Description
一个整数n, n<= 40
输出描述 Output Description
一个整数fn
样例输入 Sample Input
3
样例输出 Sample Output
2
数据范围及提示 Data Size & Hint
n<=40
*/
