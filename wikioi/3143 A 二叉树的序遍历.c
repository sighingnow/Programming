# include <stdio.h>
# include <string.h>
/*
题目描述 Description
求一棵二叉树的前序遍历，中序遍历和后序遍历
*/
/*
前序： 根  左  右
中序： 左  根  右
后序： 左  右  根

首先我们应该知道什么是序遍历
前序遍历的过程是这样的：（1）访问根结点
                        （2）前序遍历左子树
                        （3）前序遍历右子树
中序遍历的过程是这样的：（1）中序遍历左子树。
                        （2）访问根结点。
                        （3）中序遍历右子树。
后序遍历的过程是这样的：（1）后序遍历左子树
                        （2）后序遍历右子树
                        （3）访问根结点
所以我们可以看出应用  递归
*/
struct tree
{
	int num;
	struct tree *pl, *pr;
} s[17];

void q_bianli(int i)
{
	printf("%d ", s[i].num);
	if(s[i].pl != NULL)
		q_bianli(s[i].pl -> num);
	if(s[i].pr != NULL)
		q_bianli(s[i].pr -> num);
}

void z_bianli(int i)
{
	if(s[i].pl != NULL)
		z_bianli(s[i].pl -> num);
	printf("%d ", s[i].num);
	if(s[i].pr != NULL)
		z_bianli(s[i].pr -> num);
}

void h_bianli(int i)
{
	if(s[i].pl != NULL)
		h_bianli(s[i].pl -> num);
	if(s[i].pr != NULL)
		h_bianli(s[i].pr -> num);
	printf("%d ", s[i].num);
}

int main()
{
	int n, i, temp1, temp2;
	scanf("%d", &n);
	memset(s, 0, sizeof(struct tree) * n);
	for(i = 1; i <= n; i++)
	{
		s[i].num = i;
		scanf("%d %d", &temp1, &temp2);
		if(temp1 != 0)
		{
			s[i].pl = &s[temp1];
		}
		if(temp2 != 0)
		{
			s[i].pr = &s[temp2];
		}
	}
	q_bianli(1);
	printf("\n");
	z_bianli(1);
	printf("\n");
	h_bianli(1);
	
	return 0;
}

/*
输入描述 Input Description
第一行一个整数n，表示这棵树的节点个数。
接下来n行每行2个整数L和R。第i行的两个整数Li和Ri代表编号为i的节点的左儿子编号和右儿子编号。
输出描述 Output Description
输出一共三行，分别为前序遍历，中序遍历和后序遍历。编号之间用空格隔开。
样例输入 Sample Input
5
2 3
4 5
0 0
0 0
0 0
样例输出 Sample Output
1 2 4 5 3
4 2 5 1 3
4 5 2 3 1
数据范围及提示 Data Size & Hint
n <= 16
*/
