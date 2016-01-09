# include <stdio.h>
# include <math.h>
/*
题目描述 Description
有一个未完成的等式：1 2 3 4 5 6 7 8 9=N 空格（1前面没有空格）内可以填入+,-,也可以不填。 编程找出输入某个整数 N 后使
等式成立的所有方案的总数。保证有解。
*/
int ans, n;
char s[9];
void dfs(int m)
{
	if(m > 8)
	{
		int i, j = 1, num = 0, tmp;
		while(s[j] == ' ')
			num = num * 10 + j++;
		num = num * 10 + j;
		tmp = num;
		for(i = j; i <= 8; ++i)
		{
			j = i + 1, num = 0;
			while(j <= 8 && s[j] == ' ')
				num = num * 10 + j++;
			num = num * 10 + j;
			if(s[i] == '+')
				tmp += num;
			if(s[i] == '-')
				tmp -= num;
			i = j - 1;
		}
		if(tmp == n)
			++ans;
	}
	else
	{
		s[m] = ' ';
		dfs(m+1);
		s[m] = '+';
		dfs(m+1);
		s[m] = '-';
		dfs(m+1);
	}
}
int main()
{
	scanf("%d", &n);
	dfs(1);
	printf("%d", ans);

	return 0;
}
/*
输入描述 Input Description
输入一个数N。
输出描述 Output Description
输出一个数。所有的方案数。
样例输入 Sample Input
108
样例输出 Sample Output
15
数据范围及提示 Data Size & Hint
*/
