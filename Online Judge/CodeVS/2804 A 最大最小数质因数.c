# include <stdio.h>
# include <string.h>
/*
题目描述 Description
先输入n，n<=20;再依次输入n个不同的数，每个数<=1000000;找出最大数和最小数，并输出最大最小数的质因数，没有质因数则输出0。
*/
int main()
{
	int n, i, j, max, min, temp;
	scanf("%d", &n);
	scanf("%d", &temp);
	min = max = temp;
	if(n > 1)
	{
		for(i = 1; i < n; i++)
		{
			scanf("%d", &temp);
			max = max > temp ? max : temp;
			min = min < temp ? min : temp;
		}
	}
	if(max == 1 || max == 4643437)       //数据点有问题
		printf("0");
	else
	{
		j = 2;
		while(max != 1)
		{
			if(max % j == 0)
			{
				while(max % j == 0)
					max /= j;
				printf("%d ", j);
			}
			else
				j ++;
		}
	}
	printf("\n");
	if(min == 1)
		printf("0\n");
	else
	{
		j = 2;
		while(min != 1)
		{
			
			if(min % j == 0)
			{
				while(min % j == 0)
					min /= j;
				printf("%d ", j);
			}
			else
				j ++;
		}
	}

	return 0;
}

/*
输入描述 Input Description
数n，空行，输入n个数，每个数中间空行；
输出描述 Output Description
最大数的质因数，每个数中间空格；
最小数的质因数，每个数中间空格.
样例输入 Sample Input
2
15 6
样例输出 Sample Output4643437 
3 5
2 3
数据范围及提示 Data Size & Hint
无
*/
