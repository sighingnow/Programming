# include <stdio.h>
/*
题目描述 Description
比起第一题，本题加了另外一个操作，访问栈顶元素(编号3，保证访问栈顶元素时或出栈时栈不为空)，现在给出这N此操作，输出结果。
*/
int main()
{
	int stack[100000] = {0}, s_top = 0;
	int n, x, y, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		switch (x)
		{
			case 1: 
			{
				scanf("%d", &y);
				stack[s_top ++] = y;
				break;
			}
			case 2:
			{
				s_top --;
				break;
			}
			case 3:
			{
				printf("%d\n", stack[s_top - 1]);
				break;
			}
		}
	}

	return 0;
}

/*
输入描述 Input Description
N
N次操作(1入栈 2出栈 3访问栈顶)
输出描述 Output Description
K行(K为输入中询问的个数)每次的结果
样例输入 Sample Input
6
1  7
3
2
1  9
1  7
3
样例输出 Sample Output
7
7
数据范围及提示 Data Size & Hint
对于50%的数据 N≤1000 入栈元素≤200
对于100%的数据 N≤100000入栈元素均为正整数且小于等于10^4 
 */
