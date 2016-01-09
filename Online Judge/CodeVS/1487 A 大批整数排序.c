# include <stdio.h>
# include <string.h>
/*
题目描述 Description
现在有一大批（总数不超过10000000个）1到10之间的整数，现在请你从小到大进行排序输出。
（测试数据将超过11MB。）
输入描述 Input Description
第一行表示将下排序的个数N；
第2行到最后一行，每行一个数，表示有待排序的数（均是1-10之间的数，含1和10）
（注：最后有一空行）
*/
int main()
{
	int f[11] = {0};
	int n, temp;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &temp);
		f[temp] ++;
	}
	for(n = 1; n <= 10; n++)
	{
		for(temp = 0; temp < f[n]; temp ++)
			printf("%d\n", n);
	}

	return 0;
}

/*
输出描述 Output Description
输出N个从小到大排列好的数，每行一个（注：最后有一空行）
样例输入 Sample Input
11
9
10
1
2
3
4
5
6
7
8
9
 
样例输出 Sample Output
1
2
3
4
5
6
7
8
9
9
10
数据范围及提示 Data Size & Hint
注意内存限制只有2MB哦
*/
