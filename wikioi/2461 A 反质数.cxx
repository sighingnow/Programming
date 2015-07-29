#include <iostream>
using namespace std;
/*
题目描述 Description
对于任何正整数x，其约数的个数记作g(x)。例如g(1)=1、g(6)=4。
如果某个正整数x满足：g(x)>g(i) 0<i<x，则称x为反质数。例如，整数1，2，4，6等都是反质数。
现在给定一个数N，你能求出不超过N的最大的反质数么？
*/
/*
对任意一个数可以分解质因数得到::p=2^t1*3^t2*5^t3*7^t4.....；
其因数的个数为：(t1+1)*(t2+1)*(t3+1)......
于是反质数必然t1>=t2>=t3>=....(若对p'有t3>t2,则有p'大于某个与它因数个数相等的数，故p'非反质数)。
也就是说在因数个数相同的情况下，反质数一定最小。
*/
//直接找小于n的质因数最多的数，dfs

int num[15] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int count[15] = {0x3fffff};

long long int ans, n, anst;

void dfs(int x, long long int y, int cnt)
{
	x /= (count[cnt] + 1);//若乘上第cnt个质数，因子数就变成 x/(b[cnt]+1)*(b[cnt]+2);
	y *= num[cnt];
	count[cnt] ++;
	x *= (count[cnt]+1);
	if(y > n)
	{
		count[cnt]--;
		return;
	}
	if(x <= anst && y >= ans)
	{
		count[cnt] --;
		return;
	}
	if(x >= anst)//若x>anst，那必然更新。若等于，则y<ans(由剪枝得）,也更新.
	{
		anst = x;
		ans = y;
	}
	if(count[cnt+1] < count[cnt])//优先枚举大的
		dfs(x, y, cnt+1);
	if(count[cnt] < count[cnt-1])
		dfs(x, y, cnt);
	count[cnt]--;//回溯
}

int main(int argc, char **argv)
{
	cin >> n;
	dfs(1, 1, 1);
	cout << ans;
	return 0;
}
/*
输入描述 Input Description
一个数N。
输出描述 Output Description
不超过N的最大的反质数。
样例输入 Sample Input
1000
样例输出 Sample Output
840
数据范围及提示 Data Size & Hint
1<=N<=2,000,000,000
*/
