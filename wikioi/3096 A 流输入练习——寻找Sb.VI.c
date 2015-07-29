# include <stdio.h>
# include <string.h>
/*
题目描述 Description
已知某开放授权人员名叫Serb,由于经常修改各种数据，因此开发人员们都喊他SB.现在他和许多人一起过飞机安检，排成了一长队列，
请问SB.是否在队列中。
*/
int main()
{
	char sb, s[101];
	int len;
	scanf("%c %s", &sb, s);
	len = strlen(s);
	while(len--)
		if(sb == s[len])
			break;
	if(len < 0)
		printf("NO");
	else
		printf("YES");
	
	return 0;
}
/*
输入描述 Input Description
第一行：SB.所代表的某个符号
第二行：一排等待飞机安检的人所代表的符号(小于等于100，大于等于1)
输出描述 Output Description
YES或NO
样例输入 Sample Input
1
2356@Qfrr
样例输出 Sample Output
NO
数据范围及提示 Data Size & Hint
一排等待飞机安检的人所代表的符号数量小于等于100，大于等于1且为正整数。我们保证只有一个Serb。
C/C++:流输入有木有！
*/
