#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
/*
题目描述 Description
今年是国际数学联盟确定的“2000——世界数学年”，又恰逢我国著名数学家华罗庚先生诞辰90周年。在华罗庚先生的家乡江苏金坛，组织了一场别
开生面的数学智力竞赛的活动，你的一个好朋友XZ也有幸得以参加。活动中，主持人给所有参加活动的选手出了这样一道题目：
设有一个长度为N的数字串，要求选手使用K个乘号将它分成K+1个部分，找出一种分法，使得这K+1个部分的乘积能够为最大。
同时，为了帮助选手能够正确理解题意，主持人还举了如下的一个例子：
有一个数字串：312， 当N=3，K=1时会有以下两种分法：
1)  3*12=36
2)  31*2=62
这时，符合题目要求的结果是：31*2=62
现在，请你帮助你的好朋友XZ设计一个程序，求得正确的答案。
*/
long long trans(char *s, int *posi, int k, int n)
{
	long long int tmp = 0, ans = 1;
	for(int i = 1; i <= posi[1]; ++i)
		tmp = tmp * 10 + s[i] - '0';
	ans *= tmp;
	for(int i = 2; i <= k; ++i)
	{
		tmp = 0;
		for(int j = posi[i-1] + 1; j <= posi[i]; ++j)
			tmp = tmp * 10 + s[j] - '0';
		ans *= tmp;
	}
	tmp = 0;
	for(int i = posi[k] + 1; i <= n; ++i)
		tmp = tmp * 10 + s[i] - '0';
	ans *= tmp;
	return ans;
}

void dfs(int n, int m, int k, char *s, int *posi, long long & ans)
{
	if(m > k)
	{
		int tmp = trans(s, posi, k, n);
		ans = ans >= tmp ? ans : tmp;
	}
	else
	{
		for(int i = posi[m-1] + 1; i < n && k - m < n - i; ++i)
		{
			posi[m] = i;
			dfs(n, m+1, k, s, posi, ans);
		}
	}
}

int main(int argc, char **argv)
{
	char s[45];
	int n, k;
	long long ans = 0;
	cin >> n >> k;
	int posi[k+1];
	memset(posi, 0, sizeof(posi));
	scanf("%s", s+1);
	dfs(n, 1, k, s, posi, ans);
	cout << ans;
	return 0;
}
/*
输入描述 Input Description
程序的输入共有两行：
第一行共有2个自然数N，K（6≤N≤40，1≤K≤6）
第二行是一个长度为N的数字串。
输出描述 Output Description
结果显示在屏幕上，相对于输入，应输出所求得的最大乘积（一个自然数）。
样例输入 Sample Input
4 2
1231
样例输出 Sample Output
62
数据范围及提示 Data Size & Hint
本题由于比较老，数据实际也比较小，用long long 即可通过
*/
