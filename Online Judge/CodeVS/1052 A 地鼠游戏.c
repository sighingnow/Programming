# include <stdio.h>
# include <stdlib.h>
/*
题目描述 Description
地鼠游戏是一项需要反应速度和敏捷判断力的游戏。游戏开始时，会在地板上一下子冒出很多地鼠来，然后等你用榔头去敲击这些地鼠，
每个地鼠被敲击后，将会增加相应的游戏分值。问题是这些地鼠不会傻傻地等你去敲击，它总会在冒出一会时间后又钻到地板下面去（而
且再也不上来），每个地鼠冒出后停留的时间可能是不同的，而且每个地鼠被敲击后增加的游戏分值也可能是不同，为了胜出，游戏参与
者就必须根据每个地鼠的特性，有选择地尽快敲击一些地鼠，使得总的得分最大。
这个极具挑战性的游戏王钢特别喜欢，最近他经常在星期天上午玩这个游戏，慢慢地他不但敲击速度越来越快（敲击每个地鼠所需要的耗
时是1秒），而且他还发现了游戏的一些特征，那就是每次游戏重新开始后，某个地鼠冒出来后停留的时间都是固定的，而且他记录了每个
地鼠被敲击后将会增加的分值。于是，他在每次游戏开始后总能有次序地选择敲击不同的地鼠，保证每次得到最大的总分值。
*/
struct mouse
{
	int time, scord;
} mice[101];
int cmp(const void *a, const void *b)
{
	return ((struct mouse *)a)->time - ((struct mouse *)b)->time;
}
int main()               //排序加 DP(N*T 的时间), 可以不用堆(N*logN 的时间)
{
	int n, i, t, sum = 0, tmp;
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
		scanf("%d", &mice[i].time);
	for(i = 0; i < n; ++i)
		scanf("%d", &mice[i].scord);
	qsort(mice, n, sizeof(mice[0]), cmp);
	for(t = mice[n-1].time; t >= 1; t--)
	{
		tmp = n - 1;
		for(i = n - 1; i >= 0; i--)
		{
			if(mice[i].time >= t && mice[tmp].scord < mice[i].scord)
				tmp = i;
		}
		sum += mice[tmp].scord;
		mice[tmp].scord = 0;
	}
	printf("%d\n", sum);
	
	return 0;
}

/*
输入描述 Input Description
输入包含3行，第一行包含一个整数n（1<=n<=100）表示有n个地鼠从地上冒出来，第二行n个用空格分隔的整数表示每个地鼠冒出后停留
的时间，第三行n个用空格分隔的整数表示每个地鼠被敲击后会增加的分值（<=100）。每行中第i个数都表示第i个地鼠的信息。
输出描述 Output Description
输出只有一行一个整数，表示王钢所能获得的最大游戏总分值。
样例输入 Sample Input
5
5  3  6  1  4
7  9  2  1  5
样例输出 Sample Output
24
*/
