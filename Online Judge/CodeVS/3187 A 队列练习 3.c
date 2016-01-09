# include <stdio.h>
/*
题目描述 Description
(此题与队列练习1相比改了2处:1加强了数据 2不保证队空时不会出队)
(比起第一题，本题加了另外一个操作，访问队头元素(编号3，保证访问队头元素时或出队时队不为空)，现在给出这N此操作，输出结果。)
给定一个队列(初始为空)，现给出这些操作请输出最终的队头元素。 操作解释：1表示入队，2表示出队
*/
int main()
{
	int queue[100000] = {0}, head = 0, tail = 0;
	int n, x, y, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if(x == 1)
		{
			scanf("%d", &y);
			queue[tail++] = y; 
		}
		if(x == 2 && head < tail)
		{
			head ++;
		}
		if(x == 3 && head < tail)
		{
			printf("%d\n", queue[head]);
		}
	}
	
	return 0;
}

/*
输入描述 Input Description
N(操作个数)
N个操作(如果是入队则后面还会有一个入队元素)
具体见样例(输入保证队空时不会出队)
输出描述 Output Description
K行(K为输入中询问的个数)每次的结果
样例输入 Sample Input
6
1 7
3
2
1 9
1 7
3
样例输出 Sample Output
7
9
数据范围及提示 Data Size & Hint
对于50%的数据 N≤1000 入队元素≤200
对于100%的数据 N≤100000入队元素均为正整数且小于等于10^4
*/
