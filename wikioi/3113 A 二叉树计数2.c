# include <stdio.h>
/*
题目描述 Description
一个有n个结点的二叉树总共有多少种形态
h(0)*h(n-1) + h(2)*h(n-2) +   + h(n-1)h(0)=h(n))
h(n)=((4*n-2)/(n+1))*h(n-1);
*/
void Catalan(int n)   //二维数组初始化求出前 n 个Catalan数
{
	int i, j, len, tmp, digit;
	int CatalanNum[n+1][1000], lenCatalanNum[n+1];
	/*Catalan[i][]用来存储第 i 个Catalan数(高位在后，低位在前)，len[i] 用来存储第 i 个Catalan数的长度(可省略)*/
	CatalanNum[1][0] = lenCatalanNum[1] = len = 1;
	for(i = 2; i <= n; ++i)
	{
		for(j = 0; j < len; ++j)      //先每一位乘以(4 * i - 2)
			CatalanNum[i][j] = CatalanNum[i-1][j] * (4 * i - 2);
		digit = 0;
		for(j = len-1; j >= 0; --j)     //除以 (i + 1)
		{
			tmp = digit * 10 + CatalanNum[i][j];
			CatalanNum[i][j] = tmp / (i + 1);
			digit = tmp % (i + 1);
		}
		/*处理进位*/
		digit = 0;
		for(j = 0; j < len; ++j)
		{
			tmp = CatalanNum[i][j] + digit;
			CatalanNum[i][j] = tmp % 10;
			digit = tmp / 10;
		}
		while(digit)
		{
			CatalanNum[i][len++] = digit % 10;
			digit /= 10;
		}
		lenCatalanNum[i] = len;   //记录每一个Catalan数的长度
	}
	for(i = lenCatalanNum[n]-1; i >= 0; --i)
		printf("%d", CatalanNum[n][i]);
}
int main()
{
	int n;
	scanf("%d", &n);
	Catalan(n);
	
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
1<=n<=100
*/
