//filename:
# include <stdio.h>
/*
题目描述 Description
    给定x轴上的N（0<N<100）条线段，每个线段由它的二个端点a_I和b_I确定，I=1,2,……N.这些坐标都是区间（－999，999）的整数。
	有些线段之间会相互交叠或覆盖。请你编写一个程序，从给出的线段中去掉尽量少的线段，使得剩下的线段两两之间没有内部公共点。
	所谓的内部公共点是指一个点同时属于两条线段且至少在其中一条线段的内部（即除去端点的部分）。
*/
void swap(int *a, int *b)
{
	int c;
	c = *a, *a = *b, *b = c;
}

int main(void)           //此题也可以用动态规划解决，类型同最长升序子串问题
{
	int hash[2000] = {0};
	int i, j, n, temp1, temp2, temp, line;
	scanf("%d", &n);
	line = 0;
	for(i = 1; i <= n; i++)
	{
		scanf("%d %d", &temp1, &temp2);
		if(temp1 > temp2)
		{
			temp = temp1, temp1 = temp2, temp2 = temp;
		}
		temp1 += 1000;
		temp2 += 1000;
		if(hash[temp1] == 0)    //注意可能出现右端点不同而左端点相同的情形
		{
			hash[temp1] = temp2;
		}
		else
		{
			line ++;
			hash[temp1] = temp2 < hash[temp1] ? temp2 : hash[temp1];
		}
	}
	for(i = 0; i < 2000; i++)
	{
		if(hash[i] != 0)
		{
			for(j = i + 1; j < hash[i]; j++)
			{
				if(hash[j] != 0)
				{
					line ++;
					if(hash[i] >= hash[j])
					{
						i = j;
					}
				}
			}
			i = j - 1;
		}
	}
	line = n - line;
	printf("%d\n", line);

	return 0;
}

/*
输入描述 Input Description
    输入第一行是一个整数N。接下来有N行，每行有二个空格隔开的整数，表示一条线段的二个端点的坐标。
输出描述 Output Description
    输出第一行是一个整数表示最多剩下的线段数。
样例输入 Sample Input
3
6  3
1  3
2  5
样例输出 Sample Output
2
数据范围及提示 Data Size & Hint
0<N<100
*/
