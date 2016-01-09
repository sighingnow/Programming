#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
/*
有一矩形区域的城市中建筑了若干建筑物，如果某两个单元格有一个点相联系，则它们属于同一座建筑物。现在想在这些建筑物之间
搭建一些桥梁，其中桥梁只能沿着矩形的方格的边沿搭建，如下图城市1有5栋建筑物，可以搭建4座桥将建筑物联系起来。城市2有两座
建筑物，但不能搭建桥梁将它们连接。城市3只有一座建筑物，城市4有3座建筑物，可以搭建一座桥梁联系两栋建筑物，但不能与第三座
建筑物联系在一起。
*/
struct Arc
{
	int u, v;
	int len;
}line[200 * 200];

int cmp(const void *a, const void *b)
{
	struct Arc *p = (struct Arc *)a, *q = (struct Arc *)b;
	if(p->len != q->len)
		return p->len - q->len;
	else if(p -> u != q ->u)
		return p->u - q->u;
	else
		return p->v - q->v;
}

int find(int t, int *uset)
{
	if(t != uset[t])
		uset[t] = find(uset[t], uset);
	return uset[t];
}

void usetUnion(int x, int y, int *uset, int *rank)
{
	if((x = find(x, uset)) == (y = find(y, uset)))
		return;
	if(rank[x] > rank[y])
		uset[y] = x;
	else
		uset[x] = y;
	if(rank[x] == rank[y])
		rank[y]++;
}

void init(int r, int c, int i, int j, char s[][200], int *uset, int *rank)
{
	if(i > 1 && s[i-1][j] == '#')
		usetUnion(200 * (i - 1) + j, 200 * i + j, uset, rank);
	if(j < c && s[i][j+1] == '#')
		usetUnion(200 * i + j + 1, 200 * i + j, uset, rank);
	if(i < r && s[i+1][j] == '#')
		usetUnion(200 * (i + 1) + j, 200 * i + j, uset, rank);
	if(j > 1 && s[i][j-1] == '#')
		usetUnion(200 * i + j - 1, 200 * i + j, uset, rank);
	if(i > 1 && j < c && s[i-1][j+1] == '#')
		usetUnion(200 * (i - 1) + (j + 1), 200 * i + j, uset, rank);
	if(i < r && j < c && s[i+1][j+1] == '#')
		usetUnion(200 * (i + 1) + (j + 1), 200 * i + j, uset, rank);
	if(i < r && j > 1 && s[i+1][j-1] == '#')
		usetUnion(200 * (i + 1) + (j - 1), 200 * i + j, uset, rank);
	if(i > 1 && j > 1 && s[i-1][j-1] == '#')
		usetUnion(200 * (i - 1) + (j - 1), 200 * i + j, uset, rank);
}

void init2(int r, int c, int i, int j, int & countLine, char s[][200])
{
	if(i > 2)
	{
		for(int k = i - 2; k >= 1; --k)
		{
			if(s[k][j] == '#')
			{
				line[countLine].u = 200 * k + j;
				line[countLine].v = 200 * i + j;
				line[countLine++].len = i - 1 - k;
			}
		}
	}
	if(j < c - 1)
	{
		for(int k = j + 2; k <= c; ++k)
		{
			if(s[i][k] == '#')
			{
				line[countLine].u = 200 * i + k;
				line[countLine].v = 200 * i + j;
				line[countLine++].len = k - j - 1;
			}
		}
	}
	if(i < r - 1)
	{
		for(int k = i + 2; k <= r; ++k)
		{
			if(s[k][j] == '#')
			{
				line[countLine].u = 200 * k + j;
				line[countLine].v = 200 * i + j;
				line[countLine++].len = k - i - 1;
			}
		}
	}
	if(j > 2)
	{
		for(int k = j - 2; k >= 1; --k)
		{
			if(s[i][k] == '#')
			{
				line[countLine].u = 200 * i + k;
				line[countLine].v = 200 * i + j;
				line[countLine++].len = j - 1 - k;
			}
		}
	}
	
	if(i > 2 && j < c && s[i-2][j+1] == '#')
	{
		line[countLine].u = 200 * (i - 2) + j + 1;
		line[countLine].v = 200 * i + j;
		line[countLine++].len = 1;
	}
	if(i > 1 && j < c - 1 && s[i-1][j+2] == '#')
	{
		line[countLine].u = 200 * (i - 1) + j + 2;
		line[countLine].v = 200 * i + j;
		line[countLine++].len = 1;
	}

	if(i < r && j < c - 1 && s[i+1][j+2] == '#')
	{
		line[countLine].u = 200 * (i + 1) + j + 2;
		line[countLine].v = 200 * i + j;
		line[countLine++].len = 1;
	}
	if(i < r - 1 && j < c && s[i+2][j+1] == '#')
	{
		line[countLine].u = 200 * (i + 2) + j + 1;
		line[countLine].v = 200 * i + j;
		line[countLine++].len = 1;
	}

	if(i < r - 1 && j > 1 && s[i+2][j-1] == '#')
	{
		line[countLine].u = 200 * (i + 2) + j - 1;
		line[countLine].v = 200 * i + j;
		line[countLine++].len = 1;
	}
	if(i < r && j > 2 && s[i+1][j-2] == '#')
	{
		line[countLine].u = 200 * (i + 1) + j - 2;
		line[countLine].v = 200 * i + j;
		line[countLine++].len = 1;
	}

	if(i > 1 && j > 2 && s[i-1][j-2] == '#')
	{
		line[countLine].u = 200 * (i - 1) + j - 2;
		line[countLine].v = 200 * i + j;
		line[countLine++].len = 1;
	}
	if(i > 2 && j > 1 && s[i-2][j-1] == '#')
	{
		line[countLine].u = 200 * (i - 2) + j - 1;
		line[countLine].v = 200 * i + j;
		line[countLine++].len = 1;
	}
}

int main(int argc, char **argv)
{
	int r, c;
	char s[200][200];
	memset(s, 0, sizeof(s));
	scanf("%d %d", &r, &c);
	for(int i = 1; i <= r; ++i)
		scanf("%s", s[i]+1);
	int city = 0, brige = 0, length = 0;
	int countLine = 0;
	int uset[200 * 200] = {0}, rank[200 * 200] = {0};
	for(int i = 0; i < 40000; ++i)
		uset[i] = i;

	for(int i = 1; i <= r; ++i)
	{
		for(int j = 1; j <= c; ++j)
		{
			if(s[i][j] == '#')
			{
				init(r, c, i, j, s, uset, rank);
			}
		}
	}
	for(int i = 1; i <= r; ++i)
	{
		for(int j = 1; j <= c; ++j)
		{
			if(s[i][j] == '#' && uset[200 * i + j] == (200 * i + j))
				city++;
		}
	}
	
	cout << city << endl;
	
	for(int i = 1; i <= r; ++i)
	{
		for(int j = 1; j <= c; ++j)
		{
			if(s[i][j] == '#')
				init2(r, c, i, j, countLine, s);
		}
	}

	for(int i = 0; i < countLine; ++i)
	{
		if(line[i].u > line[i].v)
			swap(line[i].u, line[i].v);
	}

	qsort(line, countLine, sizeof(line[0]), cmp);

	for(int i = 0; i < countLine; ++i)
	{
		int tmp1 = line[i].u, tmp2 = line[i].v;
		
		if(find(tmp1, uset) != find(tmp2, uset))
		{
			brige++;
			length += line[i].len;
			usetUnion(tmp1, tmp2, uset, rank);
		}
	}
	cout << brige << " " << length;
	
	return 0;
}
/*
输入描述 Input Description
在输入的数据中的第一行包含描述城市的两个整数r 和c, 分别代表从北到南、从东到西的城市大小(1 <= r <= 100 and 1 <=  c <= 100). 
接下来的r 行, 每一行由c 个(“#”)和(“.”)组成的字符. 每一个字符表示一个单元格。“#”表示建筑物，“.”表示空地。
输出描述 Output Description
在输出的数据中有两行，第一行表示建筑物的数目。第二行输出桥的数目和所有桥的总长度。
样例输入 Sample Input
样例1
3 5
#...#
..#..
#...#

样例2
3 5
##...
.....
....#

样例3
3 5
#.###
#.#.#
###.#

样例4:
3 5
#.#..
.....
....#

样例输出 Sample Output
样例1
5
4 4
样例2
2
0 0
样例3
1
0 0
样例4
3
1 1
数据范围及提示 Data Size & Hint
见描述
*/