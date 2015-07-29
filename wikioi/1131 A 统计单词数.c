# include <stdio.h>
# include <string.h>

/*
题目描述 Description
一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，有的还能统计出特定单词在文章中
出现的次数。
现在，请你编程实现这一功能，具体要求是：给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。
注意：匹配单词时，不区分大小写，但要求完全匹配，即给定单词必须与文章中的某一独立单词在不区分大小写的情况下完全
相同（参见样例1），如果给定单词仅是文章中某一单词的一部分则不算匹配（参见样例2）。

*/

int main()
{
	int i, j, t, loca;
	char op[11], ch[1000001];
	int len,length;
	gets(op);
	gets(ch);
	length = strlen(op);
	len = strlen(ch);
	for(i = 0; i < length; i++)
	{
		if(op[i] <= 'Z' && op[i] >= 'A')
			op[i] += ('a' - 'A');
	}
	for(i = 0; i < len; i++)
	{
		if(ch[i] <= 'Z' && ch[i] >= 'A')
			ch[i] += ('a' - 'A');
	}
	t = 0;
	for(i = 0; i < len; i++)
	{
		if((i == 0 || ch[i-1] == ' ') && (i+length > len || ch[i+length]==' '))
		{
			j = 0;
			while(ch[i+j] == op[j])
			{
				j++;
			}
			if(j == length)
			{
				t ++;
				if(t == 1)
				{
					loca = i;       //位置指的是在字符串中的位置，而不是第几个单词
				}
			}
		}
	}
	if(t > 0)
		printf("%d %d\n", t, loca);
	else
		printf("-1\n");

	return 0;
}

/*
输入描述 Input Description
第 1 行为一个字符串，其中只含字母，表示给定单词；
第 2 行为一个字符串，其中只可能包含字母和空格，表示给定的文章。
输出描述 Output Description
只有一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，分别是单词在文章中出现的次数和
第一次出现的位置（即在文章中第一次出现时，单词首字母在文章中的位置，位置从0 开始）；如果单词在文章中没有出现，
则直接输出一个整数-1。
样例输入 Sample Input
输入1：
To
to be or not to be is a question
输入2：
to
Did the Ottoman Empire lose its power at that time
样例输出 Sample Output
输出1：
2 0
输出2：
-1
数据范围及提示 Data Size & Hint
数据范围
1 ≤ 单词长度≤ 10。
1 ≤ 文章长度≤ 1,000,000。
*/


