# include <stdio.h>
# include <string.h>
/*
题目描述 Description
非常经典的问题，拿来给大家练手了。 
序列 { 1,2,...,n } 的一个子序列是指序列 { i1, i2, ……, ik },其中 1<=i1 < i2 < …… < ik<=n, 序列 { a1, a2, ……, an } 的一个子序列是
指序列 { ai1, ai2, ……, aik },其中 { i1, i2, ……, ik } 是 { 1, 2, ……, n } 的一个子序列.同时,称 k 为此子序列的长度. 
如果 { ai1, ai2, ……, aik } 满足 ai1 ≤ ai2 ≤ …… ≤ aik,则称之为上升子序列.如果不等号都是严格成立的,则称之为严格上升子序列.同理,如
果前面不等关系全部取相反方向,则称之为下降子序列和严格下降子序列. 
长度最长的上升子序列称为最长上升子序列.本问题对于给定的整数序列,请求出其最长严格上升子序列的长度
*/
int main()
{
	int n, i, j, max;
	scanf("%d", &n);
	int f[n], s[n];
	memset(f, 0, sizeof(f));
	scanf("%d", &s[0]);
	for(i = 1; i < n; i++)
	{
		scanf("%d", &s[i]);
		for(j = 0; j < i; j++)
		{
			if(s[i] > s[j])
			{
				f[i] = f[i] > (f[j] + 1) ? f[i] : (f[j] + 1);
			}
		}
	}
	max = f[0];         //记住要找最大值
	for(i = 1; i < n; i++)
	{
		max = max > f[i] ? max : f[i];
	}
	printf("%d\n", max+1);

	return 0;
}

/*
输入描述 Input Description
第一行，一个整数N。
第二行 ，N个整数（N < = 5000）
输出描述 Output Description
输出K的极大值，即最长严格上升子序列的长度
样例输入 Sample Input
5
9 3 6 2 7
样例输出 Sample Output
3
数据范围及提示 Data Size & Hint
【样例解释】
最长严格上升子序列为3,6,7
【说明】
此题非常基础，希望每个人都能拿到此题的全部分数
*/
