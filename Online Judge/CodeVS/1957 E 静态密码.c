# include <stdio.h>
# include <string.h>

/*
题目描述 Description
saffah十分爱和同学们传纸条，其内容均由大写字母组成，不过其中经常涉及一些不可告人的秘密，
于是saffah发明了一种简单的加密算法。由于对于同一个明文，其所对应的密文是惟一的，故saffah它们称这种加密方法为“
静态密码”（static password，简称stpass）。
 
这种加密算法的核心是一个从字母集’A’..’Z’到其本身的一一映射f，例如，明文的“ABCDEFGHIJKLMNOPQRSTUVWXYZ”
对应密文的“QWERTYUIOPASDFGHJKLZXCVBNM”就是一种合法的映射。换言之，一个明文不可能对应多个密文，一个密文也不
可能有多个明文与之对应。
 
作为一个暗恋着saffah的人，你有幸截获了一张saffah传给某个人的纸条，上面一行是明文，另一行是其对应的密文。你试图
计算出这个对应法则，即明文的“ABCDEFGHIJKLMNOPQRSTUVWXYZ”分别对应着什么密文。
 
注意，纸条中的内容可能是自相矛盾的，例如，如果明文是“AAC”，密文是“ACC”，那么这是不合法的，因为明文A对应着
两个密文A和C，密文C也对应着两个明文A和C。但是如果没有自相矛盾的现象出现，我们就假定纸条中的所有内容都是正确的。
*/

int main()
{
	int i,len,t,flag,mark;
	char s1[100],s2[100];
	int haxi1[26], haxi2[26];
	for(i = 0; i < 26; i++)
	{
		haxi1[i] = -1;
		haxi2[i] = -1;
	}
	gets(s1);
	gets(s2);
	len = strlen(s1);
	for(i = 0; i < len; i++)
	{
		if(haxi1[s1[i]-'A'] == -1)
		{
			haxi1[s1[i]-'A'] = s2[i] - 'A';
		}
		else
		{
			if((s2[i] - 'A') != haxi1[s1[i]-'A'])
			{
				printf("'\n");
				return 0;
			}
		}
		if(haxi2[s2[i]-'A'] == -1)
		{
			haxi2[s2[i]-'A'] = s1[i] - 'A';
		}
		else
		{
			if((s1[i] - 'A') != haxi2[s2[i]-'A'])
			{
				printf("'\n");
				return 0;
			}
		}
	}
	t = 0;
	for(i = 0; i < 26; i++)
	{
		if(haxi1[i] == -1)
		{
			t ++;
		}
	}
	if(t >= 2)
	{
		printf("No_Solution\n");
		return 0;
	}
	else if(t == 1)
	{
		for(i = 0; i < 26; i++)
		{
			if(haxi1[i] == -1)
			{
				flag = i;
				break;
			}
		}
		for(i = 0; i < 26; i++)
		{
			if(haxi2[i] == -1)
			{
				mark = i;
				break;
			}
		}
		haxi1[flag] = mark;
	}
	for(i = 0; i < 26; i++)
		printf("%c", haxi1[i] + 'A');
	printf("\n");
	
	return 0;
}

/*
输入描述 Input Description
输入文件共两行，为两个长度均为N的字符串S1，S2，其中仅包含大写字母。
输出描述 Output Description
输出文件只有一行，为一个字符串：
如果纸条中出现了自相矛盾的现象，则只输出一个单引号（'）；
如果没有出现自相矛盾的现象，但由于条件不足，无法确定出对应法则，则输出以下字符串：’No_Solution’（不含引号）；
否则，请输出明文“ABCDEFGHIJKLMNOPQRSTUVWXYZ”所对应的密文。
样例输入 Sample Input
Input1:
AAC
ACC
Input2:
ABCDE
FGHIJ
Input3:
THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG
ZITJXOEAWKGVFYGBPXDHLGCTKZITSQMNRGU
样例输出 Sample Output
Output1:
'
Output2:
No_Solution
Output3:
QWERTYUIOPASDFGHJKLZXCVBNM
数据范围及提示 Data Size & Hint
对于100%的数据，1≤N≤63。
对于60%的数据，S1中至少出现了26个字母各一次。
*/
/*
数据点：
THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG
ZITJXOEAWKGVFYGBPXDHLGCTKZITSQMNRGU

BCDEFGHIJKLMNOPQRSTUVWXYZ
CDEFGHIJKLMNOPQRSTUVWXYZZ

QWERTYUIOPASDFGHJKLZXCVBN
BCDEFGHIJKLMNOPQRSTUVWXYZ

Q
Q

RANGWOQINGHEYIKANA
FZYBSLAKYBNDHKPZYZ

ABCDEFFFFFGHIJKLMNOPQRSTUVWXYZ
QWERTYYYYYUIOPASDFGHJKLZXCVBMN

QQQQWERTYUIOPASDFGHJKLZXCVBNM
ZZZZXCVBNMASDFGHJKLQQWERTYUIO

QWEWEWEWERASDFZXCVTYUIGHJKBNMOPL
POIOIOIOIULKJHMNBVYTREGFDSCXZWQA

ABCDEFGHIJKLMNOPQRSTUVWXY
QWERTYUIOPASDFGHJKLZXCVNB

QWERTYUIOPASDFGHJKLZXCVBN
BACDEFGHIJKLMNOPQRSTUVWXY
*/
