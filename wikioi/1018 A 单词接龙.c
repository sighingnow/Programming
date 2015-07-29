# include <stdio.h>
# include <string.h>
# include <malloc.h>
/*
题目描述 Description
单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长
的“龙”（每个单词都最多在“龙”中出现两次），在两个单词相连时，其重合部分合为一部分，例如beast和astonish，如果接成一条龙则变为
beastonish，另外相邻的两部分不能存在包含关系，例如at和atide间不能相连。
*/
int n, maxlen, length = 1, flag[21], isLink[21][21], commenLen[21][21], len[21]; //isLink存是否可以相连
char *s[21], start;

void judge(void)                  //判断能否相连
{
	int i, j, k, tmp, length;
	for(i = 1; i <= n; ++i)
	{
		if(s[i][0] == start)
		{
			isLink[0][i] = 1;
			commenLen[0][i] = 1;
		}
	}
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			k = 0;
			tmp = len[i] <= len[j] ? len[i] : len[j];
			tmp --;
			for(length = 0; length < tmp; length++)
			{
				if(s[i][len[i]-1-length] == s[j][0])
				{
					for(k = 0; k <= length; ++k)
					{
						if(s[i][len[i]-1-k] != s[j][length-k])
							break;
					}
					if(k > length)
						break;
				}
			}
			if(length < tmp && k)
			{
				isLink[i][j] = 1;
				commenLen[i][j] = k;
			}
		}
	}
}

void DfsDragon(int m)
{
	int i, tmp;
	for(i = 1; i <= n; ++i)
	{
		if(flag[i] < 2 && isLink[m][i] == 1)
		{
			flag[i] ++;
			tmp = length;
			length += (len[i] - commenLen[m][i]);
			maxlen = maxlen >= length ? maxlen : length;

			DfsDragon(i);

			length = tmp;
			flag[i] --;
		}
	}
}
int main()
{
	scanf("%d", &n);
	char tmp[500];
	int i;
	for(i = 1; i <= n; ++i)
	{
		scanf("\n%s", tmp);
		len[i] = strlen(tmp);
		s[i] = (char *)malloc(sizeof(char) * len[i]);
		strcpy(s[i], tmp);
	}
	scanf("\n%c", &start);
	judge();
	DfsDragon(0);
	for(i = 1; i <= n; ++i)
		free(s[i]);
	printf("%d", maxlen);

	return 0;
}
/*
输入描述 Input Description
输入的第一行为一个单独的整数n(n<=20)表示单词数，以下n行每行有一个单词，输入的最后一行为一个单个字符，表示“龙”开头的字母。
你可以假定以此字母开头的“龙”一定存在.
输出描述 Output Description
只需输出以此字母开头的最长的“龙”的长度
样例输入 Sample Input
5
at
touch
cheat
choose
tact
a
样例输出 Sample Output
23
数据范围及提示 Data Size & Hint
（连成的“龙”为atoucheatactactouchoose）
*/
