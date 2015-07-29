# include <stdio.h>
# include <string.h>
/*
题目描述 Description
一个朋友网络，如果a认识b，那么如果a第一次收到某个消息，那么会把这个消息传给b，以及所有a认识的人。
如果a认识b，b不一定认识a。
所有人从1到n编号，给出所有“认识”关系，问如果i发布一条新消息，那么会不会经过若干次传话后，这个消息传回给了i，1<=i<=n。
*/
int rela[1001][1001], f[1001], flag;       //rela[][]用来存储两人之间的关系，f[] 用来记录此人是否已经知道

void find(int i, int p, int n)
{
	int j;
	if(rela[i][p] == 1)
	{
		flag = 1;
		return;
	}
	for(j = 1; j <= n; j++)
	{
		if(rela[i][j] == 1 && f[j] == 0)        //传给不知道的人，以防止进入死循环
		{
			f[j] = 1;
			find(j, p, n);
		}
	}
}

int main()
{
	int n, m, i, temp1, temp2;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++)
	{
		scanf("%d %d", &temp1, &temp2);
		rela[temp1][temp2] = 1;
	}
	for(i = 1; i <= n; i++)
	{
		memset(f, 0, sizeof(f));
		flag = 0;
		find(i, i, n);
		if(flag == 1)
			printf("T\n");
		else
			printf("F\n");
	}
	
	return 0;
}

/*
输入描述 Input Description
第一行是n和m，表示人数和认识关系数。
接下来的m行，每行两个数a和b，表示a认识b。1<=a, b<=n。认识关系可能会重复给出，但一行的两个数不会相同。
输出描述 Output Description
一共n行，每行一个字符T或F。第i行如果是T，表示i发出一条新消息会传回给i；如果是F，表示i发出一条新消息不会传回给i。
样例输入 Sample Input
4 6
1 2
2 3
4 1
3 1
1 3
2 3
样例输出 Sample Output
T
T
T
F
数据范围及提示 Data Size & Hint
n<=1000
1<=a, b<=n
*/
