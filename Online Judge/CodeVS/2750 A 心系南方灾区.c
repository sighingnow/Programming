# include <stdio.h>
# include <string.h>
/*
题目描述 Description
现在我国南方正在承受百年不遇的大雪、冻雨灾害。北京市已经开始了面向全体市民的捐款活动，并组织运力，以最快速度将这些救灾物资运送到灾区人
民的手中。
已知救灾物资中有m件大衣（10000<=m<=2000000）,一辆卡车一次最多可以运走n件（2000<=n<=10000）.请你编写程序计算一下，要将所有的大衣运走，
北京市政府最少需要调动多少辆卡车参与运送。
*/
int main()
{
	int n, m;
	scanf("%d %d", &m, &n);
	if(m % n == 0)
		printf("%d\n", m / n);
	else
		printf("%d\n", m / n + 1);

	return 0;
}

/*
输入描述 Input Description
文件中只有两个整数m、n
输出描述 Output Description
文件中只有一个整数，表示需要的卡车数量。
样例输入 Sample Input
10000 2000
样例输出 Sample Output
5
数据范围及提示 Data Size & Hint
*/
