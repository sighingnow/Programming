#include <iostream>
#include <cstdio>
#include <deque>
#include <vector>
#include <algorithm>
#define INF 0x3fffffff
#define read(x) {char ch;\
	            x=0;\
                while((ch=getchar())>'9'||ch<'0');\
                x=ch-'0';\
	            while((ch= getchar())<='9'&&ch>='0')\
					x=x*10+ch-'0';\
	            }
using namespace std;
/*
题目描述 Description
麦克找了个新女朋友，玛丽卡对他非常恼火并伺机报复。因为她和他们不住在同一个城市，因此她开始准备她的长途旅行。在这个国家
中每两个城市之间最多只有一条路相通，并且我们知道从一个城市到另一个城市路上所需花费的时间。麦克在车中无意中听到有一条
路正在维修，并且那儿正堵车，但没听清楚到底是哪一条路。无论哪一条路正在维修，从玛丽卡所在的城市都能到达麦克所在的城市。
玛丽卡将只从不堵车的路上通过，并且她将按最短路线行车。麦克希望知道在最糟糕的情况下玛丽卡到达他所在的城市需要多长时间，
这样他就能保证他的女朋友离开该城市足够远。
编写程序，帮助麦克找出玛丽卡按最短路线通过不堵车道路到达他所在城市所需的最长时间(用分钟表示)。
*/
struct map
{
	int link;
	int time;
};

vector<struct map>Map[1001];
vector<struct map>::iterator iter;

void initMap(int m)
{
	int tmp1, tmp2, tmp3;
	struct map temp1, temp2;
	for(int i = 1; i <= m; ++i)
	{
		read(tmp1); read(tmp2); read(tmp3);
		temp1.link = tmp2, temp1.time = tmp3;
		temp2.link = tmp1, temp2.time = tmp3;
		Map[tmp1].push_back(temp1);
		Map[tmp2].push_back(temp2);
	}
}

int spfa(int n, int *prev)//SLF优化
{
	bool isVisit[n+1];
	deque <int> Q;
	int dist[n+1];
	for(int i = 1; i <= n; ++i)
	{
		isVisit[i] = false;
		dist[i] = INF;
		prev[i] = 0;
	}
	dist[1] = 0, isVisit[1] = true;
	Q.push_back(1);

	while(!Q.empty())
	{
		int tmp = Q.front();
		for(int i = 0; i < (int)Map[tmp].size(); ++i)
		{
			vector<struct map>::iterator p = Map[tmp].begin() + i;////由于vector的寻址速度较慢,故在此进行一次优化
			if(dist[tmp] + p->time < dist[p->link])
			{
				dist[p->link] = dist[tmp] + p->time;
				prev[p->link] = tmp;
				if(!isVisit[p->link])
				{
					if(dist[p->link] > dist[Q.front()])
						Q.push_back(p->link);
					else
						Q.push_front(p->link);
					isVisit[p->link] = true;
				}
			}
		}
		Q.pop_front();
		isVisit[tmp] = false;
	}
	return dist[n];
}

class vectorFind
{
	private:
		int key;
	public:
		vectorFind(const int link)
		{
			key = link;
		}
		bool operator()(vector<struct map>::value_type & value)
		{
			return value.link == key;
		}
};

int main()		//SPFA
{
	int n, m;
	cin >> n >> m;
	int route[n+1], len = 0;//存储被枚举删除的路线,利用存储每一个点的前缀点实现
	int prev[n+1];
	initMap(m);

	spfa(n, prev);
	for(int i = n; i != 0; i = prev[i])
		route[len++] = i;
	long long int path[len], max = 0;
	
	for(int i = 1; i < len; ++i)
	{
		vector<struct map>::iterator iter1, iter2;
		int temp1 = route[i], temp2 = route[i-1];
		iter1 = find_if(Map[temp1].begin(), Map[temp1].end(), vectorFind(temp2));
		iter2 = find_if(Map[temp2].begin(), Map[temp2].end(), vectorFind(temp1));

		struct map tmp1, tmp2;
		tmp1.link = iter1->link;
		tmp1.time = iter1->time;
		tmp2.link = iter2->link;
		tmp2.time = iter2->time;

		iter1 = Map[temp1].erase(iter1);
		iter2 = Map[temp2].erase(iter2);

		path[i] = spfa(n, prev);

		Map[temp1].insert(iter1, tmp1);
		Map[temp2].insert(iter2, tmp2);
	}

	for(int i = 1; i < len; ++i)
	{
		max = max > path[i] ? max : path[i];
	}
	cout << max;

	return 0;
}
/*
输入描述 Input Description
第一行有两个用空格隔开的数N和M，分别表示城市的数量以及城市间道路的数量。1≤N≤1000，1≤M≤N*(N-1)/2。城市用数字1至N标识，麦克
在城市1中，玛丽卡在城市N中。
接下来的M行中每行包含三个用空格隔开的数A，B和V。其中1≤A，B≤N，1≤V≤1000。这些数字表示在A和城市B中间有一条双行道，并且在V分
钟内是就能通过。
输出描述 Output Description
输出文件的第一行中写出用分钟表示的最长时间，在这段时间中，无论哪条路在堵车，玛丽卡应该能够到达麦克处，如果少于这个时间的话，则必定存在一条路，该条路一旦堵车，玛丽卡就不能够赶到麦克处。
样例输入 Sample Input
5 7
1 2 8
1 4 10
2 3 9
2 4 10
2 5 1
3 4 7
3 5 10
样例输出 Sample Output
27
数据范围及提示 Data Size & Hint
*/