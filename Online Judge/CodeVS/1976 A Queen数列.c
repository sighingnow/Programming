# include <stdio.h>
# include <string.h>
/*
题目描述 Description
将1到N的整数数列（1，2，3，……，N）打乱，变为数列a（a[1]，a[2]，a[3]，……，a[N]）。如果这个数列对于任意的i∈{1，2，3，……，N}都满足
a[a[i]]=N+1-i，则这个数列叫做长度为N的Queen数列。
现给你长度N，请输出字典序最小的Queen数列。
所谓字典序最小，即为a[1]最小，在此基础上a[2]最小，在此基础上a[3]最小……
*/
int main()               //递推解法时间复杂度过高，注意观察规律
{
	int n, i, half;
	scanf("%d", &n);
	if(n % 4 > 1)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		int s[n+1];            //下标为 0 的项不使用
		half = n / 2;
		if(n % 2 == 1)
			s[(n+1)/2] = (n + 1) / 2;
		for(i = 1; i <= half; i += 2)
		{
			s[i] = (i + 1 ), s[n+1-i] = n + 1 - s[i];
			s[i+1] = n + 2 - (i + 1), s[n+1-(i+1)] = n + 1 - s[i+1];
		}
		for(i = 1; i <= n; i++)
		printf("%d ", s[i]);
	}

	return 0;
}

/*
输入描述 Input Description
共一行，为一个整数N。
输出描述 Output Description
共一行，有i个整数，以空格隔开（行尾没有空格），第i个整数为a[i]。其中a为字典序最小的长度为N的Queen数列。如果不存在这样的数列，请输出
一个0。
样例输入 Sample Input
Input1:
3
Input2:
4
Input3:
5
样例输出 Sample Output
Output1:
0
Output2:
2 4 1 3
Output3:
2 5 3 1 4
数据范围及提示 Data Size & Hint
不存在长度为3的Queen数列。
2 4 1 3为字典序最小的长度为4的Queen数列。
2 5 3 1 4为字典序最小的长度为5的Queen数列。
对于20%的数据，N≤10；对于50%的数据，N≤1000；对于100%的数据，1≤N≤200000。
*/
/*题解：
分析n<10数列的规律
0
0
0
2 4 1 3
2 5 3 1 4
0
0
2 8 4 6 3 5 1 7
2 9 4 7 5 3 6 1 8
0
而且一头一尾之和相等，于是搜索二分，时间复杂度减半，不过还是搜索
减半后 n范围可以到20
再拿20分析
2 20 4 18 6 16 8 14 10 12 9 11 7 13 5 15 3 17 1 19
发现了
*/
