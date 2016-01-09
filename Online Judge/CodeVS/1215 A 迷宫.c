# include <stdio.h>
# include <string.h>
/*1215 迷宫
题目描述 Description
在N*N的迷宫内，“#”为墙，“.”为路，“s”为起点，“e”为终点，一共4个方向可以走。从左上角（(0,0)“s”）位置处走到右下角（(n-1,n-1)“e”）位置处，
可以走通则输出YES，不可以走则输出NO。
*/
char s[16][16];
int n, t, flag;
void find(int i, int j)
{
	if(s[i][j] == 'e')
		flag = 1;
	else
	{
		s[i][j] = '#';
		if(j+1 < n && s[i][j+1] != '#')
		{
			find(i, j+1);
		}
		if(j-1 >= 0 && s[i][j-1] != '#')
		{
			find(i, j-1);
		}
		if(i+1 < n && s[i+1][j] != '#')
		{
			find(i+1, j);
		}
		if(i-1 >= 0 && s[i-1][j] != '#')
		{
			find(i-1, j);
		}
	}
}

int main(void)
{
	int num, i;
	scanf("%d", &num);
	while(num--)
	{
		scanf("%d", &n);
		for(i = 0; i < n; i++)
			scanf("%s", s[i]);
		s[0][0] = '#', flag = 0;
		find(0, 0);
		if(flag == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}

/*
输入描述 Input Description
输入的第一行为一个整数m，表示迷宫的数量。 
其后每个迷宫数据的第一行为一个整数n（n≤16），表示迷宫的边长，接下来的n行每行n个字符，字符之间没有空格分隔。
输出描述 Output Description
输出有m行，每行对应的迷宫能走，则输出YES，否则输出NO。
样例输入 Sample Input
1
7
s...##.
.#.....
.......
..#....
..#...#
###...#
......e
样例输出 Sample Output
YES
数据范围及提示 Data Size & Hint
*/
