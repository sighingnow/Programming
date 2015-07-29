# include <stdio.h>
/*
题目描述 Description
进入XX中学的第二天，老师又给我们出了A+B PROBLEM
但这次的A+B PROBLEM 难度降(ti)低(gao)了
这回读入两个矩阵A,B输出结果.
*/
int main()
{
	int n, i, j, tmp;
	scanf("%d", &n);
	int array[n][n];
	for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j)
			scanf("%d", &array[i][j]);
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			scanf("%d", &tmp);
			printf("%d ", tmp + array[i][j]);
		}
		printf("\n");
	}

	return 0;
}
/*
输入描述 Input Description
第一行n 表示a b 的行列数
接下来n行表示矩阵a
接下来n行表示矩阵b
输出描述 Output Description
n行为两个矩阵的和
样例输入 Sample Input
2
1 1
1 1
2 2
2 2
样例输出 Sample Output
3 3
3 3
数据范围及提示 Data Size & Hint
行数列数相同，且均<=100.
矩阵里的数字不超过int型
空间开的很紧（4M），小心。
*/
