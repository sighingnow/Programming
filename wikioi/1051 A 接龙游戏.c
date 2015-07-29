#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
/*
题目描述 Description
给出了N个单词，已经按长度排好了序。如果某单词i是某单词j的前缀，i->j算一次接龙(两个相同的单词不能算接龙)。
你的任务是：对于输入的单词，找出最长的龙。
*/
/******************************************************************************************************************************
*维护一个栈，枚举所有的字符串（按字典序排好的） 如果当前的字符串能和栈顶的字符串接龙的话，那么当前字符串入栈，继续枚举下一个字符串，
*如果不能接龙，那么栈顶字符串弹出，当前字符串继续与弹出后的栈顶字符串比较，直到当前字符串与栈顶字符串能接成龙，然后当前字符串入栈，
*在这期间统计栈最多有多少个元素
*******************************************************************************************************************************/
//解法：数据范围过大，不宜用 DP；
struct Words
{
	char data[50];
}str[100005];

int cmp(const void *p, const void *q)
{
	return strcmp(((struct Words *)p)->data, ((struct Words *)q)->data);
}
bool isLink(char *a, char *b)        //如果 b 能接在 a 后边，return 1，否则return 0；
{
	int i, len1, len2;
	len1 = strlen(a), len2 = strlen(b);
	for(i = 0; i < len1 && i < len2; ++i)
	{
		if(a[i] != b[i])
			break;
	}
	if(i >= len1 && len1 != len2)
		return true;
	else
		return false;
}
int main()
{
	int max = 0, i, n, stack[100], top = 0;
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
		scanf("%s", str[i].data);
	qsort(str, n, sizeof(str[0]), cmp);
	stack[top++] = 0, max = top;
	for(i = 1; i < n; ++i)
	{
		while(top > 0 && !isLink(str[stack[top-1]].data, str[i].data))
			--top;
		stack[top++] = i;
		max = max > top ? max : top;
	}
	printf("%d", max);

	return 0;
}
/*
输入描述 Input Description
第一行为N(1<=N<=10^5)。以下N行每行一个单词（由小写组成），已经按长度排序。(每个单词长度<50)
输出描述 Output Description
仅一个数，为最长的龙的长度。
样例输入 Sample Input
5
i
a
int
able
inter
样例输出 Sample Output
3
数据范围及提示 Data Size & Hint
1<=N<=10^5
*/
