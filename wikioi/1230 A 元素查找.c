# include <stdio.h>
/*
题目描述 Description
给出n个正整数，然后有m个询问，每个询问一个整数，询问该整数是否在n个正整数中出现过。
*/

char f[100000000];            //开成全局变量就可通过，也可用C++中的bool类型(C++ bool型貌似会超时)

int main()
{
	int n, m, i, temp;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		f[temp] = 1;
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		if(f[temp] == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

/*
输入描述 Input Description
第一行两个整数 n 和m。
第二行n个正整数（1<=n<= 100000）
第三行m个整数(1<=m<=100000)
输出描述 Output Description
一共m行，若出现则输出YES，否则输出NO
样例输入 Sample Input
4 2
2 1 3 4
1 9
样例输出 Sample Output
YES
NO
数据范围及提示 Data Size & Hint
所有数据都不超过10^8
*/
