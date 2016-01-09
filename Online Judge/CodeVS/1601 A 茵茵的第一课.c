# include <stdio.h>
/*
题目描述 Description
茵茵今年已经六年级了，爸爸给她报了一个学习程序设计的班。第一节课上，老师讲的就是如何输入一个数，再原样输出出来。以现在的
你看来，挺容易的是不？那么，就请你也写出一个一样的程序吧。
*/
int main()
{
	char s[10000];
	scanf("%s", s);
	printf("%s", s);

	return 0;
}

/*
输入描述 Input Description
只有一个数（可能是小数，也可能是整数）
输出描述 Output Description
也只有一个数 ，并与输入完全相同。
样例输入 Sample Input
3.5
样例输出 Sample Output
3.5
数据范围及提示 Data Size & Hint
输入中的字符个数<=100
*/
