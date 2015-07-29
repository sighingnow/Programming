# include <stdio.h>
# include <string.h>
/*
题目描述 Description
输入一列整数，输出它们的总和、最大值、最小值、并从大到小输出。
*/
int main()
{
	int n, i, j, min, max, sum, temp;
	scanf("%d", &n);
	int f[n];
	scanf("%d", &f[0]);
	sum = min = max = f[0];
	for(i = 1; i < n; i++)
	{
		scanf("%d", &f[i]);
		sum += f[i];
		min = min <= f[i] ? min : f[i];
		max = max >= f[i] ? max : f[i];
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(f[i] > f[j])
			{
				temp = f[i], f[i] = f[j], f[j] = temp;
			}
		}
	}
	printf("%d\n%d\n%d\n%d\n", sum, max, min, f[0]);
	for(i = 1; i < n; i++)
	{
		if(f[i] != f[i-1])
			printf("%d\n", f[i]);
	}

	return 0;
}

/*
输入描述 Input Description
第1行：一个整数N表示总共有几个整数要处理
第2行：N个整数
输出描述 Output Description
第1行：它们的总和
第2行：最大值
第3行：最小值
第3+1行：最大值（此行开始从大到小依次输出：注有相同的数字时只输出其中一个）
第3+2行：
........
最后一行：最小值
样例输入 Sample Input
样1:
6
2 5 5 4 9 4
样2：
4
7 7 7 7
样例输出 Sample Output
样1:
29（//提示：这是总和，）
9(//这是最大的数)
2(//这是最小的数)
9
5
4
2
样2：
28
7
7
7
数据范围及提示 Data Size & Hint
从大到小排序输出时，应注意筛除相同的数字（如果系列中全部数均相同，只需要输出其中一个即可）
*/
