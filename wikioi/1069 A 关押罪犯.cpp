#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
/*
题目描述 Description
S 城现有两座监狱，一共关押着N 名罪犯，编号分别为1~N。他们之间的关系自然也极
不和谐。很多罪犯之间甚至积怨已久，如果客观条件具备则随时可能爆发冲突。我们用“怨
气值”（一个正整数值）来表示某两名罪犯之间的仇恨程度，怨气值越大，则这两名罪犯之
间的积怨越多。如果两名怨气值为c 的罪犯被关押在同一监狱，他们俩之间会发生摩擦，并
造成影响力为c 的冲突事件。
每年年末，警察局会将本年内监狱中的所有冲突事件按影响力从大到小排成一个列表，
然后上报到S 城Z 市长那里。公务繁忙的Z 市长只会去看列表中的第一个事件的影响力，
如果影响很坏，他就会考虑撤换警察局长。
在详细考察了N 名罪犯间的矛盾关系后，警察局长觉得压力巨大。他准备将罪犯们在
两座监狱内重新分配，以求产生的冲突事件影响力都较小，从而保住自己的乌纱帽。假设只
要处于同一监狱内的某两个罪犯间有仇恨，那么他们一定会在每年的某个时候发生摩擦。那
么，应如何分配罪犯，才能使Z 市长看到的那个冲突事件的影响力最小？这个最小值是少？
*/
/*
1、并查集分两段：f[1] ~ f[n]， f[1+n] ~ f[n+n]
对于 i <= n，f[i+n] 可理解为代表 f[i] 的补集
2、int sa=find(crime[i].a);   sa 代表 罪犯 crime[i].a 所属集合
int sb=find(crime[i].b);   sb 代表 罪犯 crime[i].b 所属集合
3、集合并操作：f[sa]=find(crime[i].b+n);  
f[sb]=find(crime[i].a+n);
要把crime[i].a、crime[i].b 拆开，因只分到两个监狱，对应只有两个大集合：
一个包含 crime[i].b， 一个不包含 crime[i].b
显然，crime[i].a 要属于不包含 crime[i].b 的集合，即 crime[i].b 的补集，就是 f[crime[i].b + n] 代表的集合
所以 f[sa]  代表的集合 是  f[crime[i].b + n]  代表的集合的一部分， 故将 f[sa] 与 find(crime[i].b+n)  合并
同理 将  f[sb] 与 find(crime[i].a+n) 合并
*/
struct Crime
{
	int a, b;
	int anger;
}crime[100001];

int cmp(const void *a, const void *b)
{
	return ((struct Crime *)b)->anger - ((struct Crime *)a)->anger;
}

int find(int x, int *f)
{
	if(x != f[x])
		f[x] = find(f[x], f);
	return f[x];
}

int main(int argc, char *argv[])
{
	int f[40001] = {0};
	int n, m, ans = -1;
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
		scanf("%d %d %d", &crime[i].a, &crime[i].b, &crime[i].anger);
	qsort(crime, m, sizeof(crime[0]), cmp);
	for(int i = 0; i < 40001; ++i)
		f[i] = i;
	for(int i = 0; i < m; ++i)
	{
		int sa = find(crime[i].a, f);
		int sb = find(crime[i].b, f);
		if(sa == sb)
		{
			ans = i;
			break;
		}
		else
		{
			f[sa] = find(crime[i].b + n, f);
			f[sb] = find(crime[i].a + n, f);
		}
	}
	if(ans == -1)
		cout << "0";
	else
		cout << crime[ans].anger;

	return 0;
}

/*
输入描述 Input Description
第一行为两个正整数N 和M，分别表示罪犯的数目以及存在仇恨的罪犯对数。
接下来的M 行每行为三个正整数aj，bj，cj，表示aj 号和bj 号罪犯之间存在仇恨，其怨气值为cj。数据保证，且每对罪犯组合只出现一次。
输出描述 Output Description
共1 行，为Z 市长看到的那个冲突事件的影响力。如果本年内监狱
中未发生任何冲突事件，请输出0。
样例输入 Sample Input
4 6
1 4 2534
2 3 3512
1 2 28351
1 3 6618
2 4 1805
3 4 12884
样例输出 Sample Output
3512
数据范围及提示 Data Size & Hint
罪犯之间的怨气值如下面左图所示，右图所示为罪犯的分配方法，市长看到的冲突事件
影响力是3512（由2 号和3 号罪犯引发）。其他任何分法都不会比这个分法更优。
【数据范围】
对于30%的数据有N≤ 15。
对于70%的数据有N≤ 2000，M≤ 50000。
对于100%的数据有N≤ 20000，M≤ 100000。
*/