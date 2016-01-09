# include <stdio.h>
/*
题目描述 Description
一个有n个结点的二叉树总共有多少种形态

Catalan数
先去一个点作为顶点,然后左边依次可以取0至N-1个相对应的,右边是N-1到0个,两两配对相乘,就是
h(0)*h(n-1) + h(2)*h(n-2) +   + h(n-1)h(0)=h(n))
h(n)=((4*n-2)/(n+1))*h(n-1);
*/
int main()
{
	int n, sum = 1, i;
	scanf("%d", &n);
	if(n > 1)
	{
		for(i = 2; i <= n; ++i)
		{
			sum = (4 * i - 2) * sum / (i + 1);
		}
	}
	printf("%d", sum);

	return 0;
}
/*
输入描述 Input Description
读入一个正整数n
输出描述 Output Description
输出一个正整数表示答案
样例输入 Sample Input
5
样例输出 Sample Output
42
数据范围及提示 Data Size & Hint
1<=n<=20
*/
