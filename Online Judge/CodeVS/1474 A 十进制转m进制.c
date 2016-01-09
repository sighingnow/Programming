# include <stdio.h>
/*
题目描述 Description
将十进制数n转换成m进制数 m<=16
n<=100
*/
int main()
{
	int n, m, f[100]={0}, t, i;
	scanf("%d %d", &n, &m);
	t = 0;
	while(n / m != 0)
	{
		f[t++] = n % m;
		n = (n - f[t-1]) / m;
	}
	f[t] = n;
	for(i = t; i >= 0; i--)
	{
		if(f[i] < 10)
			printf("%d", f[i]);
		else
			printf("%c", f[i] - 10 + 'A');
	}
	
	return 0;
}

/*
输入描述 Input Description
共一行
n和m
输出描述 Output Description
共一个数
表示n的m进制
样例输入 Sample Input
样例1：10 2
样例2:100 15
样例输出 Sample Output
样例1：1010
样例2:6A
数据范围及提示 Data Size & Hint
用反向取余法
*/
