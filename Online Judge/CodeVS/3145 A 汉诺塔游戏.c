# include <stdio.h>
/*
题目描述 Description
汉诺塔问题（又称为河内塔问题），是一个大家熟知的问题。在A，B，C三根柱子上，有n个不同大小的圆盘（假设半径分别为1-n吧），
一开始他们都叠在我A上（如图所示），你的目标是在最少的合法移动步数内将所有盘子从A塔移动到C塔。
游戏中的每一步规则如下：
1. 每一步只允许移动一个盘子（从一根柱子最上方到另一个柱子的最上方）
2. 移动的过程中，你必须保证大的盘子不能在小的盘子上方（小的可以放在大的上面，最大盘子下面不能有任何其他大小的盘子）
 
如对于n=3的情况，一个合法的移动序列式：
1 from A to C
2 from A to B
1 from C to B
3 from A to C
1 from B to A
2 from B to C
1 from A to C
 
给出一个数n，求出最少步数的移动序列
*/
int t;
char ch[1024][3];

void hanoi(int n, char a, char b, char c)
{
	if(n == 1)
	{
		ch[t][0] = n, ch[t][1] = a, ch[t][2] = c;
		t ++;
	}
	else
	{
		hanoi(n-1, a, c, b);
		ch[t][0] = n, ch[t][1] = a, ch[t][2] = c;
		t ++;
		hanoi(n-1, b, a, c);
	}

}

int main()
{
	char a = 'A', b = 'B', c = 'C';
	int n, i;
	scanf("%d", &n);
	hanoi(n, a, b, c);
	printf("%d\n", t);
	for(i = 0; i < t; i++)
	{
		printf("%d from %c to %c\n", ch[i][0], ch[i][1], ch[i][2]);
	}

	return 0;
}

/*
输入描述 Input Description
一个整数n
输出描述 Output Description
第一行一个整数k，代表是最少的移动步数。
接下来k行，每行一句话，N from X to Y，表示把N号盘从X柱移动到Y柱。X,Y属于{A,B,C}
样例输入 Sample Input
3
样例输出 Sample Output
7
1 from A to C
2 from A to B
1 from C to B
3 from A to C
1 from B to A
2 from B to C
1 from A to C
数据范围及提示 Data Size & Hint
n<=10
*/
