#include <iostream>
#include <cstdio>
using namespace std;
/*题目描述 Description
孔子是我国古代著名的教育家。他有先见之明，可以判断学生出师以后给他带来的声望。声望共有三种“G”“M”“B”，“G”可以给他带
来3点声望，“M”可以给他带来2点声望，“B”可以让他丢失2点声望。每个学生出师后的声望为ai。当然，学生出师的时间不同,第i个
的学生需要bi个单位时间。他每次只能教1名学生。他共有x个学生，有y个单位时间，但必须教z名学生。求孔子可获得的最大声望。
*/
struct Stu
{
	int repu;
	int time;
};

Stu student[11];

int buf[11];
int ans = -0x3ffffff;

void dfs(int k, int m, int x, int y, int z)
{
	if(k > z)
	{
		int tmptime = 0, tmprepu = 0;
		for(int i = 1; i <= z; ++i)
		{
			tmptime += student[buf[i]].time;
			tmprepu += student[buf[i]].repu;
		}
		if(tmptime <= y && ans < tmprepu)
			ans = tmprepu;
	}
	else
	{
		for(int i = m; i <= x; ++i)
		{
			buf[k] = i;
			if(z - k > x - i)
				break;
			dfs(k + 1, i + 1, x, y, z);
		}
	}
}

int main(int argc, char **argv)
{
	int x, y, z;
	int i;
	cin >> x >> z >> y;
	for(i = 1; i <= x; ++i)
	{
		char tmp;
		scanf("\n%c %d", &tmp, &student[i].time);
		switch (tmp)
		{
		case 'G':
			student[i].repu = 3;
			break;
		case 'M':
			student[i].repu = 2;
			break;
		case 'B':
			student[i].repu = -2;
			break;
		default:
			break;
		}
	}
	for(i = 1; i <= z; ++i)
	{
		if(y >= student[i].time)
			break;
	}
	dfs(1, 1, x, y, z);
	if(ans == -0x3ffffff)
		ans = -1;
	printf("%d", ans);

	return 0;
}

/*
输入描述 Input Description
输入格式：
x z y
a1 b1
……
……
……
ax bx
输出描述 Output Description
输出格式：
ans（为最大声望）
无解输出- 1
样例输入 Sample Input
例一：
2 2 2
G 0
G 2
例二：
4 2 2
B 1
B 1
G 4
M 3
样例输出 Sample Output
例一：
6
例二：
-4
数据范围及提示 Data Size & Hint
x<=10,z<=a,y<=200,声望可能为负数，保证时间大于0,但不一定有解。
*/