# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description
如m=100,n=6
则将输出100以内的所有相差6的孪生素数：如，
5　11
7　13
....
83　89
请按此规律输出数与数之间用半角空格区分，每一对一行．
*/
int ispri(int n)
{
	int i, k;
	k = sqrt(n);
	for(i = 2; i <= k; i++)
	{
		if(n % i == 0)
			break;
	}
	if(i > k)
		return 1;
	else
		return 0;
}
int main()
{
	int i, m, k, total = 0;
	scanf("%d %d", &m, &k);
	for(i = 2; i <= m - k; i++)
	{
		if(ispri(i) == 1 && ispri(i+k) == 1)
		{
			printf("%d %d\n", i, i+k);
			total ++;
		}
	}
	printf("Total Is:%d\n", total);

	return 0;
}

/*
输入描述 Input Description
第一行输入一个整数数m为一个范围(如１００)
第二行输入一个整数k为目标孪生素数的公差(如６)
输出描述 Output Description
每行输出一对，最后一行输出：Total Is:？(？表示总共有几对这样的数，如果不存在则输出Total Is:0)
样例输入 Sample Input
例如１：
50　2
例如２：
100 90
例如３：
200　199
样例输出 Sample Output
例如１：
3 5
5 7
11 13
17 19
29 31
41 43
Total Is:6
例如２：
7 97
Total Is:1
例如３：
Total Is:0
数据范围及提示 Data Size & Hint
m<=100
*/
