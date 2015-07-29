#include <iostream>
#include <cstdio>
#define INF 0x3fffffff
using namespace std;
/*
题目描述 Description
在G城保卫战中，超级孪生蜘蛛Phantom001和Phantom002作为第三层防卫被派往守护内城南端一带极为隐秘的通道。
根据防护中心的消息，敌方已经有一只特种飞蛾避过第二层防卫，直逼内城南端通道入口。但优秀的蜘蛛已经在每个通道内埋下了坚固
的大网，无论飞蛾进入哪个通道，他只有死路一条！（因为他是无法挣脱超级蛛网的）
现在，001和002分别驻扎在某两个通道内。各通道通过内线相通，通过每条内线需要一定的时间。当特种飞蛾被困某处，001或002会迅速赶
来把它结果掉（当然是耗时最少的那个）。
001跟002都想尽早的完成任务，他们希望选择在最坏情况下能尽早完成任务的方案。
*/
int main(int argc, char **argv)		//Floyd
{
	int map[101][101], dist[101][101];
	int n;

	for(int i = 0; i < 101; ++i)
	{
		for(int j = 0; j < 101; ++j)
		{
			map[i][j] = INF;
		}
		map[i][i] = 0;
	}

	cin >> n;
	int tmp1, tmp2, tmp3;
	while(scanf("%d %d %d", &tmp1, &tmp2, &tmp3) != EOF)
	{
		map[tmp1][tmp2] = map[tmp2][tmp1] = tmp3;
	}
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= n; ++j)
			dist[i][j] = map[i][j];
	}
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	int x = 1, y = 2, ans = INF;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = i + 1; j <= n; ++j)
		{
			int tmp = min(dist[i][1], dist[j][1]);
			for(int k = 1; k <= n; ++k)
			{
				if(tmp < min(dist[i][k], dist[j][k]))
					tmp = min(dist[i][k], dist[j][k]);
			}
			if(tmp < ans)
			{
				ans = tmp;
				x = i, y = j;
			}
		}
	}
	cout << x << " " << y;
	
	return 0;
}
/*
输入描述 Input Description
第一行为一个整数N (N<=100) 表示通道数目。
接下来若干行每行三个正整数a,b,t 表示通道a,b有内线相连，通过的时间为t。(t<=100)
（输入保证每个通道都直接/间接连通）
输出描述 Output Description
两个不同的整数x1,x2，分别为001，002驻扎的地点。（如果有多解，请输出x1最小的方案，x1相同则输出x2最小的方案）
样例输入 Sample Input
3
1 2 5
2 3 10
3 1 3
样例输出 Sample Output
1 2
数据范围及提示 Data Size & Hint
*/
