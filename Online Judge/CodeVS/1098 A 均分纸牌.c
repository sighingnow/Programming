//filename:
# include <stdio.h>
/*
题目描述 Description
有 N 堆纸牌，编号分别为 1，2，…, N。每堆上有若干张，但纸牌总数必为 N 的倍数。可以在任一堆上取若于张纸牌，然后移动。
　　移牌规则为：在编号为 1 堆上取的纸牌，只能移到编号为 2 的堆上；在编号为 N 的堆上取的纸牌，只能移到编号为 N-1 的堆上；
其他堆上取的纸牌，可以移到相邻左边或右边的堆上。
　　现在要求找出一种移动方法，用最少的移动次数使每堆上纸牌数都一样多。

　　例如 N=4，4 堆纸牌数分别为：
　　①　9　②　8　③　17　④　6
　　移动3次可达到目的：
　　从 ③ 取 4 张牌放到 ④ （9 8 13 10） -> 从 ③ 取 3 张牌放到 ②（9 11 10 10）-> 从 ② 取 1 张牌放到①（10 10 10 10）。
*/
int main(void)
{
	int i, n, sum = 0, avg, t = 0;
	scanf("%d", &n);
	int card[n];
	for(i = 0; i < n; i++)
	{
		scanf("%d", &card[i]);
		sum += card[i];
	}
	avg = sum / n;
	/*
	不用考虑后一堆纸牌不足以将前一堆补满，为什么？？
	题中纸牌总量是足够的，不考虑这种情况也可以达到等效的结果
	*/
	for(i = 0; i < n-1; i++)
	{
		card[i] -= avg;              
		if(card[i] != 0)
		{
			card[i+1] += card[i];
			t ++;
		}
	}
	printf("%d\n", t);

	return 0;
}

/*
输入描述 Input Description
第一行N（N 堆纸牌，1 <= N <= 100）
第二行A1 A2 … An （N 堆纸牌，每堆纸牌初始数，l<= Ai <=10000）
输出描述 Output Description
输出至屏幕。格式为：
所有堆均达到相等时的最少移动次数。‘
样例输入 Sample Input
4
9 8 17 6
样例输出 Sample Output
3
数据范围及提示 Data Size & Hint
e
*/
