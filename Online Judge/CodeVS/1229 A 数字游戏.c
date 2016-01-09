# include <stdio.h>
# include <string.h>
/*
题目描述 Description
Lele 最近上课的时候都很无聊，所以他发明了一个数字游戏来打发时间。  这个游戏是这样的，首先，他拿出几张纸片，分别写上0到9之间的任意
数字(可重复写某个数字)，然后，他叫同学随便写两个数字X和K。Lele要做的事情就是重新拼这些纸牌，组成数字 T ，并且 T + X 是 K 的正整数倍。 
有时候，当纸片很多的时候，Lele经常不能在一节课之内拼出来，但是他又想知道答案，所以，他想请你帮忙写一个程序来计算答案。
*/
int card[10], x, k, n, flag[10], buf[10], t, mark;   //DFS

void func(int m)
{
	int i;
	if(m == n)
	{
		t = 0;
		for(i = 0; i < n; i++)
			t = t * 10 + buf[i];
		if((t + x) % k == 0)
		{
			if(mark == 0)
				printf("%d\n", t);
			mark ++;
		}
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			buf[m] = card[i];
			if(flag[i] == 0)
			{
				flag[i] = 1;
				func(m+1);
				flag[i] = 0;
			}
		}
	}
}

int main()
{
	int m, i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &card[i]);
	}
	for(i = 0; i < m; i++)
	{
		mark = 0;
		scanf("%d %d", &x, &k);
		func(0);
		if(mark == 0)
			printf("None\n");
	}

	return 0;
}

/*
输入描述 Input Description
第一行包含两个整数 N和M(0<N<9,0<M<2000)，分别代表纸片的数目和询问的数目。  
第二行包含N个整数分别代表纸片上写的数字，每个数字可能取0～9。  
接下来有M行询问，每个询问给出两个整数X和K(0<=x<10^9,0<K<100)。 
输出描述 Output Description
对于每次询问，如果能够用这些纸片拼出符合答案的T，就输出结果T。如果有多个结果，就输出符合要求的最小的T。  
如果不能拼出，就输出"None"。  
样例输入 Sample Input
4 3
1 2 3 4
5 7
33 6
12 8
样例输出 Sample Output
1234
None
1324
数据范围及提示 Data Size & Hint
*/
