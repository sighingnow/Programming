# include <stdio.h>
# include <math.h>
/*
题目描述 Description
小明因为没做作业而被数学老师罚站，之后数学老师要他回家把第n个质数找出来。（1<=n<=100000)
老师随机写了几个数，交给了小明。小明百度找了很久，都没能解决。现在交给聪明的你。请你帮忙！
简单描述：把第n个质数找出来。
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
	int n, i, total = 1;
	scanf("%d", &n);
	if(n == 1)
		printf("2\n");
	else
	{
		for(i = 3;; i += 2)
		{
			if(ispri(i) == 1)
				total ++;
			if(total == n)
			{
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}

/*
输入描述 Input Description
一个正整数n。
（1<=n<=100000)
输出描述 Output Description
第n个质数。
（第1个质数为2，第2个质数为3。）
样例输入 Sample Input
样例1
2
样例2
65
样例3
20133
样例输出 Sample Output
样例1
3
样例2
313
样例3
226381
数据范围及提示 Data Size & Hint
有大数据等着你，小心超时，不许交表哦。
（1<=n<=100000)
*/
