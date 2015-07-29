//file:
# include <stdio.h>

/*
题目描述 Description
我们要求找出具有下列性质数的个数(包含输入的自然数n):
先输入一个自然数n(n<=1000),然后对此自然数按照如下方法进行处理:
1. 不作任何处理;
2. 在它的左边加上一个自然数,但该自然数不能超过原数的一半;
3. 加上数后,继续按此规则进行处理,直到不能再加自然数为止.
输入描述 Input Description
一个数n
输出描述 Output Description
满足条件的数的个数
*/

int num = 1;

void count(int n)
{
	int i, half;
	half = n / 2;
	num += half;
	for(i = half; i >= 1; i--)
    {
        count(i);
    }
}

int main()
{
	int n;
	scanf("%d", &n);
	count(n);
	printf("%d", num);

	return 0;
}

/*
样例输入 Sample Input
6
样例输出 Sample Output
6
数据范围及提示 Data Size & Hint
6个数分别是：
6
16
26
126
36
136
*/
