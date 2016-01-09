# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description
笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，
用这种方法去选择选项的时候选对的几率非常大！
这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，
如果maxn-minn是一个质数，那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。
*/
int ispri(int a)    //判断质数 
{
	int i,k;
	k = sqrt(a);
	if(a == 1 || a == 0)
		return 0;
	for(i = 2;i <= k; i++)
	{
		if(a%i == 0)
		break;
	}
	if(i > k)
		return 1;
	else
		return 0;
}

int main()
{
	int len,max,min,i,j;
	char s[101];
	int t[26]={0};
	scanf("%s",s);
	len = strlen(s);
	for(i = 0; i < len; i++)
		t[s[i]-'a'] ++;
	for(j = 0; j < 26; j++)
		if(t[j] != 0)
		break;
	max = t[j];
	min = t[j];
	for(i = j; i < 26; i++)
	{
		if(t[i] != 0)
		{
			if(t[i] > max)
				max = t[i];
			if(t[i] < min)
				min = t[i];
		}
	}
	if(ispri(max-min) == 1)
		printf("Lucky Word\n%d",max-min);
	else
		printf("No Answer\n0");
		
	return 0;
}
/*
输入描述 Input Description
输入文件word.in只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。
输出描述 Output Description
输出文件word.out共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，
否则输出“No Answer”；
第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0。
样例输入 Sample Input
样例一
error
样例二
olympic
 
样例输出 Sample Output
样例一
Lucky Word
2
样例二
No Answer
0
*/
