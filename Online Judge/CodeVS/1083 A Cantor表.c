# include <stdio.h>
# include <math.h>

/*
题目描述 Description
现代数学的著名证明之一是Georg Cantor证明了有理数是可枚举的。他是用下面这一张表来证明这一命题的： 
1/1 1/2 1/3 1/4 1/5 … 
2/1 2/2 2/3 2/4 … 
3/1 3/2 3/3 … 
4/1 4/2 … 
5/1 … … 
我们以Z字形给上表的每一项编号。
第一项是1/1，然后是1/2，2/1，3/1，2/2，…
*/
int main(int argc,char *argv[])
{
	int n,k,t;
	scanf("%d",&n);
	for(k = 1;; k++)
	{
		if(k * (k + 1) >= 2 * n)      //注意每一斜排分子分母之和相等
			break;
	}
	t = n - k * (k - 1) / 2;
	if(k % 2 == 1)
	{
		printf("%d/%d\n", k+1-t, t);
	}
	else
	{
		printf("%d/%d\n", t, k+1-t);
	}
	
	return 0;
}

/*
输入描述 Input Description
整数N（1≤N≤10000000）
输出描述 Output Description
表中的第N项
样例输入 Sample Input
7
样例输出 Sample Output
1/4
*/
