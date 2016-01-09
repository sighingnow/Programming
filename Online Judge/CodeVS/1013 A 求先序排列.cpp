#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
/*
题目描述 Description
给出一棵二叉树的中序与后序排列。求出它的先序排列。（约定树结点用不同的大写字母表示，长度<=8）。
*/
/*
前序遍历的过程是这样的：（1）访问根结点
                        （2）前序遍历左子树
                        （3）前序遍历右子树
中序遍历的过程是这样的：（1）中序遍历左子树。
                        （2）访问根结点。
                        （3）中序遍历右子树。
后序遍历的过程是这样的：（1）后序遍历左子树
                        （2）后序遍历右子树
                        （3）访问根结点
*/
char lnode[10], rnode[10];

char build(char *str1, char *str2, int lstart, int lend, int rstart, int rend)
{
	if(lend < lstart)
		return 0;
	if(!(lend - lstart))
		return str1[lstart];
	int i;
	for(i = 0; str2[rend] != str1[lend-i]; ++i)
		;
	lnode[str2[rend]-'\0'] = build(str1, str2, lstart, lend-i-1, rstart, rend-i-1);
	rnode[str2[rend]-'\0'] = build(str1, str2, lend-i+1, lend, rend-i, rend-1);
	return str2[rend];
}

void dir(int node)
{
	printf("%c", node+'A'-1);
	if(lnode[node])
		dir(lnode[node]);
	if(rnode[node])
		dir(rnode[node]);
}

int main(int argc, char **argv)
{
	int len = 0;
	char str1[10] = {'\0'}, str2[10] = {'\0'};
	scanf("%s %s", str1, str2);
	while(str1[len])
	{
		str1[len] -= ('A'-1);
		str2[len] -= ('A'-1);
		len++;
	}

	char root = build(str1, str2, 0, len-1, 0, len-1);
	dir(root);

	return 0;
}
/*
输入描述 Input Description
两个字符串，分别是中序和后序（每行一个）
输出描述 Output Description
一个字符串，先序
样例输入 Sample Input
BADC
BDCA
样例输出 Sample Output
ABCD
*/