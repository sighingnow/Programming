# include <stdio.h>
# include <stdlib.h>
/*
题目描述 Description
出题是一件痛苦的事情！
题目看多了也有审美疲劳，于是我舍弃了大家所熟悉的A+B Problem，改用A-B了。
题目是这样的：给你一串包含N个整数的数列以及一个整数C，要求在这个数列中找出所有满足A-B=C的数对的个数。
说明：不同位置上的数字即使是一样的数对算不同的数对。
*/
int buf[2000001];

int main()
{
	int n, i, c, total = 0, temp;
	scanf("%d %d", &n, &c);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		buf[temp] ++;
	}
	for(i = c; i < 2000001; i++)
	{
		if(buf[i] != 0 && buf[i-c] != 0)
			total += buf[i] * buf[i-c];
	}
	printf("%d", total);

	return 0;
}

/*
输入描述 Input Description
第一行包括2个非负整数N和C，中间用空格隔开。
第二行有N个整数，中间用空格隔开，作为要求处理的那串数列。
输出描述 Output Description
输出一行，表示该串数列中包含的所有满足A-B=C的数对的个数。
样例输入 Sample Input
4 1
1 1 2 3
样例输出 Sample Output
3
数据范围及提示 Data Size & Hint
100%的数据满足：N≤200000，所有的数据都在int范围内。
*/
