# include <stdio.h>

/*
题目描述 Description
请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。
比如给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现1次，在数20中出现1次，在数21中出现1次，
在数22中出现2次，所以数字2在该范围内一共出现了6次。
数据范围 1 ≤ L ≤ R≤ 10000。
*/
int main()
{
	int x,y,i,t,s;
	scanf("%d %d",&x,&y);
	s = 0;
	for(i = x; i <= y; i++)
	{
		t = i;
		while(t/10 >= 1)
		{
			if(t % 10 == 2)
			{
				s ++;
			}
			t = t / 10;
		}
		if(t == 2)
			s ++;
	}
	printf("%d\n",s);
	
	return 0;
}

/*
输入描述 Input Description
输入共1 行，为两个正整数L 和R，之间用一个空格隔开。
输出描述 Output Description
输出共1 行，表示数字2 出现的次数。
样例输入 Sample Input
2 22
样例输出 Sample Output
6
*/
