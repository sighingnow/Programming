# include <stdio.h>
# include <string.h>
/*
题目描述 Description
小明最近在为线性代数而头疼，线性代数确实很抽象（也很无聊），可惜他的老师正在讲这矩阵乘法这一段内容。
当然，小明上课打瞌睡也没问题，但线性代数的习题可是很可怕的。小明希望你来帮他完成这个任务。
现在给你一个ai行aj列的矩阵和一个bi行bj列的矩阵，要你求出他们相乘的积（当然也是矩阵）。(输入数据保证aj=bi,不需要判断)
矩阵乘法的定义：
1. 矩阵A乘以B的时候，必须要求A的列数=B的行数，否则无法进行乘法运算。因此矩阵乘法也不满足交换律。
2. 设A是X*N的矩阵，B是N*Y的矩阵，用A的每一行乘以B的每一列，得到一个X*Y的矩阵。对于某一行乘以某一列的运算，我们称之为向量运算，即对应位置的每个数字相乘之后求和。
写为公式及：
C[i,j] = Sigma(A[i,k] * B[k,j])
*/
int x[201][201], y[201][201], multi[201][201];
int main()
{
	int xs, xt, ys, yt, i, j, k;
	scanf("%d %d", &xs, &xt);
	for(i = 1; i <= xs; ++i)
	{
		for(j = 1; j <= xt; ++j)
			scanf("%d", &x[i][j]);
	}
	scanf("%d %d", &ys, &yt);
	for(i = 1; i <= ys; ++i)
	{
		for(j = 1; j <= yt; ++j)
			scanf("%d", &y[i][j]);
	}
	for(i = 1; i <= xs; ++i)
	{
		for(j = 1; j <= yt; ++j)
		{
			for(k = 1; k <= xt; ++k)
				multi[i][j] += x[i][k] * y[k][j];
			printf("%d ", multi[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

/*
输入描述 Input Description
输入文件共有ai+bi+2行，并且输入的所有数为整数（long long范围内）。
第1行：ai 和 aj
第2~ai+2行：矩阵a的所有元素
第ai+3行：bi 和 bj
第ai+3~ai+bi+3行：矩阵b的所有元素
输出描述 Output Description
输出矩阵a乘矩阵b的积（矩阵c)
样例输入 Sample Input
2 2
12 23
45 56
2 2
78 89
45 56
样例输出 Sample Output
1971 2356
6030 7141
数据范围及提示 Data Size & Hint
矩阵大小<=200*200
*/
