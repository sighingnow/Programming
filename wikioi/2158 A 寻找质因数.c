# include <stdio.h>
# include <math.h>
# include <string.h>
/*
题目描述 Description
给出N个数字，试求质因数最大的数字。
*/
int buf[2][5001]; 
int main()
{
	int n, i, j, max, flag, m;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &buf[0][i]);
		m = buf[0][i], j = 2;
		while(m != 1)
		{
			while(m % j == 0)
			{
				m /= j;
			}
			j++;
		}
		buf[1][i] = j - 1;
	}
	max = buf[1][0], flag = 0;
	for(i = 1; i < n; i++)
	{
		if(max < buf[1][i])
			max = buf[1][i], flag = i;
	}
	printf("%d\n", buf[0][flag]);
	
	return 0;
}

/*
输入描述 Input Description
第一行，一个整数N，表示数字个数。
接下来N行，每行一个整数A_i，表示给出的数字。
输出描述 Output Description
一个整数，表示质因数最大的数字。
样例输入 Sample Input
4
36
38
40
42
样例输出 Sample Output
38
数据范围及提示 Data Size & Hint
N <= 5000, A_i <= 20000
举例 38和12
38=19*2
12=2*3*3
38最大的是19
12最大的是3
所以本数据要输出38
*/
