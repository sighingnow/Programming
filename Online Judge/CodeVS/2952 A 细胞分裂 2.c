# include <stdio.h>
/*
题目描述 Description
著名生物学家F博士发现了一种单细胞生物。
它长得像蚯蚓，分裂速度极快（每分钟一次），分裂也像蚯蚓一样，断成两段，再长成。
它很好斗，只要q只聚集在一起，就会q只一群打起来，当然都会打死。
假设一开始有1只，求a分钟后有多少只单细胞蚯蚓？s
*/
long long a, q;
long long int QuickPow(long long int x, long long int y)
{
	long long int ret = x % y, pow = 1;
	while(y)
	{
		if(y & 1)
		{
			pow = (pow * ret) % q;
		}
		ret = (ret * ret) % q;
		y >>= 1;
	}
	return pow;
}
int main()
{
	long long int ans;
	scanf("%I64d %I64d", &a, &q);
	ans = QuickPow(2, a);
	printf("%I64d", ans);
	return 0;
}

/*
输入描述 Input Description
两个正整数A  Q
输出描述 Output Description
答案
样例输入 Sample Input
4 5
样例输出 Sample Output
1
数据范围及提示 Data Size & Hint
对于50%数据，A<=20,Q<=100.
对于全部数据，A<=2*10^9,Q<=10^8.
*/
