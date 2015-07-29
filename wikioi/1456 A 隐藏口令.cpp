#include <iostream>
#include <cstdio>
using namespace std;
/*
题目描述 Description
有时候程序员有很奇怪的方法来隐藏他们的口令。Billy"Hacker"Geits会选择一个字符串S（由L个小写字母组成，5<=L<=100,000），然后他把
S顺时针绕成一个圈，每次取一个做开头字母并顺时针依次取字母而组成一个字符串。这样将得到一些字符串，他把它们排序后取出第一
个字符串。把这个字符串的第一个字母在原字符串中的位置做为口令。
第一个字母所在的位置是0
如字符串alabala，按操作的到7个字符串，排序后得：
aalabal abalaal alaalab alabala balaala laalaba labalaa
第一个字符串为aalabal，这个a在原字符串位置为6，则6为口令。 
*/

string s, temp;

int main(int argc, char **argv)
{
	int len;
	int ans = 0, i, k;
	int tmp;
	scanf("%d", &len);
	while(cin >> temp)  //注意可能有多段
		s += temp;
	s += s;
	for(i = 0; i < len; i++)
		s[len+i] = s[i];
	s[len+i] = '\0';
	for(i = 1, ans = 0; i < len; )
	{
		for(k = 0; k < len && s[ans+k] == s[i+k]; )
		{
			++k;
		}
		if(k >= len)
			break;
		if(s[ans+k] < s[i+k])
		{
			i += (k + 1);
		}
		else
		{
			tmp = ans + k;
			ans = i;
			i = max(tmp, i) + 1;
		}
	}

	printf("%d\n", ans);
	return 0;
}

/*
输入描述 Input Description
第一行：一个数：L
第二行：字符串：S 
输出描述 Output Description
一行，为得到的口令
样例输入 Sample Input
7
alabala
样例输出 Sample Output
6
数据范围及提示 Data Size & Hint
*/
