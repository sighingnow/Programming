#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
/*
题目描述 Description
cc是个超级帅哥，口才又好，rp极高（这句话似乎降rp），又非常的幽默，所以很多mm都跟他关系不错。然而，最关键的是，cc能够很好的
调解各各妹妹间的关系。mm之间的关系及其复杂，cc必须严格掌握她们之间的朋友关系，好一起约她们出去，cc要是和不是朋友的两个mm
出去玩，后果不堪设想……
cc只掌握着一些mm之间的关系，但是cc比较聪明，他知道a和b是朋友，b和c 是朋友，那么a和c也是朋友。
下面给出m对朋友关系, cc 定了p次约会，每次约会找两个mm，如果这两个mm是朋友，那么不会出乱子，输出‘safe'，要是不是朋友，那么
cc必然会挨……，输出‘cc cry'
*/
int findSet(int x, int *uset)//带权路径压缩
{
	if(x != uset[x])
		uset[x] = findSet(uset[x], uset);
	return uset[x];
}

void unionSet(int x, int y, int *uset, int *rank)//按秩合并
{
	if((x = findSet(x, uset)) == (y = findSet(y, uset)))
		return;
	if(rank[x] > rank[y])
		uset[y] = x;
	else
		uset[x] = y;
	if(rank[x] == rank[y])
		++rank[y];
}

int main(int argc, char **argv)//并查集
{
	int n, m, p;
	string tmp1, tmp2;
	map<string, int>nameHash;
	map<string, int>::iterator iter;
	int uset[2009], rank[2009] = {0};

	cin >> n >> m >> p;
	for(int i = 1; i <= n; ++i)
	{
		cin >> tmp1;
		nameHash.insert(map<string, int>::value_type(tmp1, i));
		uset[i] = i;
	}
	for(int i = 1; i <= m; ++i)
	{
		cin >> tmp1 >> tmp2;
		unionSet(nameHash.find(tmp1)->second, nameHash.find(tmp2)->second, uset, rank);
	}
	while(p--)
	{
		cin >> tmp1 >> tmp2;
		if(findSet(nameHash.find(tmp1)->second, uset) == findSet(nameHash.find(tmp2)->second, uset))
			printf("safe\n");
		else
			printf("cc cry\n");
	}

	return 0;
}
/*
输入描述 Input Description
第一行为n，m，p。n为mm的数量，cc知道m对朋友关系，有p次约会。
2到n+1 行，每行一个字符串，为第i个mm的名字。{字符串长度<=11,且全大写}
以下m行，每行两个字符串，用空格隔开 ，为有朋友关系的两个mm的名字。
以下p行，每行为两个字符串，用空格隔开，为这p次约会中两个mm的名字。
{保证数据不会出现没有出现过的名字}
输出描述 Output Description
输出P行表示第i次约会的情况，输出‘safe'或者‘cc cry'
样例输入 Sample Input
3 1 1
AAA
BBB
CCC
AAA CCC
AAA BBB
样例输出 Sample Output
cc cry
数据范围及提示 Data Size & Hint
0<m<=2008
0<p<=2008
*/
