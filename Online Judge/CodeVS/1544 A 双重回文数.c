# include <stdio.h>
# include <string.h>
/*
题目描述 Description
如果一个数从左往右读和从右往左读都是一样，那么这个数就叫做“回文数”。例如，12321就是一个回文数，而77778就不是。当然，回文数的首和尾都
应是非零的，因此0220就不是回文数。事实上，有一些数（如21），在十进制时不是回文数，但在其它进制（如二进制时为10101）时就是回文数。
编一个程序，从文件读入两个十进制数N 、S 然后找出前N个满足大于S且在两种或两种以上进制（二进制至十进制）上是回文数的十进制数。
本问题的解决方案不需要使用大于32位的整型
*/
short int ch[1000000];
int hunwen(int n, int k)
{
	int top = 0, mid, i;
	while(n > 0)
	{
		ch[top++] = n % k;
		n /= k;
	}
	mid = top / 2;
	for(i = 0; i <= mid; i++)
	{
		if(ch[i] != ch[top-1-i])
			break;
	}
	if(i > mid)
		return 1;
	else
		return 0;
}
int main()
{
	int n, s, t = 0, p, i;
	scanf("%d %d", &n, &s);
	s++;
	while(t < n)
	{
		p = 0;
		for(i = 2; i <= 10; i++)
		{
			if(hunwen(s, i) == 1)
				p ++;
			if(p == 2)
				break;
		}
		if(i <= 10)
		{
			printf("%d\n", s);
			t++;
		}
		s ++;
	}
	
	return 0;
}
/*
输入描述 Input Description
*第一行 两个整数n，s
输出描述 Output Description
N行, 每行一个满足上述要求的数，并按从小到大的顺序输出.
样例输入 Sample Input
3 25
样例输出 Sample Output
26
27
28
数据范围及提示 Data Size & Hint
对于100%的数据，1≤N≤15  0<S<10000
*/
