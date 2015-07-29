#include <iostream>
#include <cstdio>
using namespace std;
/*
题目描述 Description
有一天，小猫rainbow和freda来到了湘西张家界的天门山玉蟾宫，玉蟾宫宫主蓝兔盛情地款待了它们，并赐予它们一片土地。
这片土地被分成N*M个格子，每个格子里写着'R'或者'F'，R代表这块土地被赐予了rainbow，F代表这块土地被赐予了freda。
现在freda要在这里卖萌。。。它要找一块矩形土地，要求这片土地都标着'F'并且面积最大。
但是rainbow和freda的OI水平都弱爆了，找不出这块土地，而蓝兔也想看freda卖萌（她显然是不会编程的……），所以它们决定，如果
你找到的土地面积为S，它们每人给你S两银子。
*/
int __left[1001][1001], __right[1001][1001], __up[1001][1001];
char map[1001][1001];
int n, m, ans = 0;

int main(int argc, char **argv)
{
	cin >> n >> m;
	char tmp;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			while((tmp = getchar()) != 'R' && tmp != 'F')
				;
			map[i][j] = tmp;
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		int lo = 0, ro = m + 1;
		for(int j = 1; j <= m; ++j)
		{
			if(map[i][j] == 'R')
			{
				__left[i][j] = 1;
				__up[i][j] = 0;
				lo = j;
			}
			else
			{
				__left[i][j] = (i == 1 ? lo + 1 : max(__left[i-1][j], lo + 1));
				__up[i][j] = (i == 1 ? 1 : __up[i-1][j] + 1);
			}
		}
		for(int j = m; j > 0; --j)
		{
			if(map[i][j] == 'R')
			{
				__right[i][j] = m + 1;
				ro = j;
			}
			else
			{
				__right[i][j] = (i == 1 ? ro - 1 : min(__right[i-1][j], ro-1));
				ans = max(ans, (__right[i][j] - __left[i][j]+1) * __up[i][j]);
			}
		}
	}
	printf("%d", ans * 3);
}
/*
输入描述 Input Description
第一行两个整数N,M，表示矩形土地有N行M列。
接下来N行，每行M个用空格隔开的字符'F'或'R'，描述了矩形土地。
输出描述 Output Description
输出一个整数，表示你能得到多少银子，即(3*最大'F'矩形土地面积)的值。
样例输入 Sample Input
5 6
R F F F F F
F F F F F F
R R R F F F
F F F F F F
F F F F F F
样例输出 Sample Output
45
数据范围及提示 Data Size & Hint
对于50%的数据，1<=N,M<=200
对于100%的数据，1<=N,M<=1000

来源：Nescafe 20
*/
