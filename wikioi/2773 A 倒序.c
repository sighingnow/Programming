# include <stdio.h>
# include <string.h>
/*
题目描述 Description
输入一句话，完全倒序输出。
*/
char s[210];
int main()
{
	int i, len = 0;
	gets(s);
	len = strlen(s);
	for(i = len-2; i >= 0; i--)             //表准数据点最后一个是回车
		printf("%c", s[i]);

	return 0;
}

/*
输入描述 Input Description
一句话，
输出描述 Output Description
一句倒序的话。
样例输入 Sample Input
i am a boy
样例输出 Sample Output
yob a ma i
数据范围及提示 Data Size & Hint
长度小于200；
保证最后一个词末尾无空格
注意：单词间可能有多个空格，一并输出。
*/
