# include <stdio.h>
# include <string.h>
/*
题目描述 Description
Wikioi上有个人叫小融，他喜欢改名。
现在他的要求变了，只要是英文字母就是他的名字。
先给你N个名字，请你一一判断是不是小融。
本题还加强了测试数据
*/
int main()
{
	int i, n, len, j;
	char s[100000];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%s", s);
		len = strlen(s);
		j = 0;
		while((s[j] <= 'Z' && s[j] >= 'A') || (s[j] <= 'z' && s[j] >= 'a'))
		{
			j ++;
		}
		if(j == len)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

/*
输入描述 Input Description
N
N行名字(全部为字符)
输出描述 Output Description
 N行，YES或NO(大写)
样例输入 Sample Input
3
&6*14315
Rinkement
micsloox
样例输出 Sample Output
NO
YES
YES
数据范围及提示 Data Size & Hint
对于40%的数据 N≤10 名字长度≤100
对于100%的数据 N≤50 名字长度≤100000
*/
