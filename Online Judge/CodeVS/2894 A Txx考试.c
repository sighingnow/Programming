# include <stdio.h>
# include <string.h>
/*
题目描述 Description
Txx是一个成绩很差的人，考试便成了他的噩梦。于是他常在考试时睡觉以打发时间。今天他又要面临一次考试，为了保证有充足的睡眠，
他决定只做k分钟题目。这次测试有n道题，第i题的得分是pi分，需要耗费ti分钟解决（将要完成也得不到分）。
请你算出他最少扣多少分（总分是所有题目分值的总和）。
*/
int main()
{
	int n, k, i, j, sum;
	scanf("%d %d", &k, &n);
	int f[k+1], t, p;
	sum = 0;
	memset(f, 0, sizeof(f[0])*(k+1));
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &t, &p);
		sum += p;
		for(j = k; j >= t; j--)
		{
			f[j] = f[j] > (f[j-t] + p) ? f[j] : (f[j-t] + p);
		}
	}
	printf("%d\n", sum-f[k]);

	return 0;
}

/*
输入描述 Input Description
第一行k
第二行n
第三行到第n+2行每行两个数：ti和pi
输出描述 Output Description
Txx最少的扣分
样例输入 Sample Input
5
3
2 6
1 3
4 7
 
样例输出 Sample Output
6
 
数据范围及提示 Data Size & Hint
100%的数据中，k<=100000，ti<=10000，pi<=10000；
30%的数据中，n<=20；
100%的数据中，n<=500
*/
