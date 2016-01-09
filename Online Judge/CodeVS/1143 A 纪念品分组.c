# include <stdio.h>
# include <stdlib.h>

/*
题目描述 Description
元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。为使得参加晚会的同学所获得的纪念品价值相对均衡，
他要把购来的纪念品根据价格进行分组，但每组最多只能包括两件纪念品，并且每组纪念品的价格之和不能超过一个给定的整数。
为了保证在尽量短的时间内发完所有纪念品，乐乐希望分组的数目最少。你的任务是写一个程序，找出所有分组方案中分组数
最少的一种，输出最少的分组数目。
*/

int comp(const void *a,const void *b)
{
	return *(int *) a - *(int *) b;     //由小到大排序 
}
int main()
{
	int n,max,i,j,k,time;
	scanf("%d %d",&max,&n);
	int prize[n],flag[n],mark;
	for(i = 0; i < n; i++)
	{
		scanf("%d",&prize[i]);
		flag[i] = 0;
	}
	qsort(prize,n,sizeof(int),comp);
	time = 0;
	for(i = n-1; i >= 0; i--)
	{
		if(flag[i] == 0)
		{
			mark = 0;
			if(prize[i] < max)
			{
				for(j = i-1; j >= 0; j--)
				{
					if(flag[j] == 0 && (prize[i] + prize[j] <= max))
					{
						flag[j] = 1;
						mark = 1;
						time ++;
						break;
					}
				}
			}
			if(mark == 0)
				time ++;
		}
	}
	printf("%d\n",time);
	
	return 0;
}

/*
输入描述 Input Description
包含n+2行：
第1行包括一个整数w，为每组纪念品价格之和的上限。
第2行为一个整数n，表示购来的纪念品的总件数。
第3~n+2行每行包含一个正整数pi (5 <= pi <= w)，表示所对应纪念品的价格。
输出描述 Output Description
仅一行，包含一个整数，即最少的分组数目。
样例输入 Sample Input
100
9
90
20
20
30
50
60
70
80
90
样例输出 Sample Output
6
数据范围及提示 Data Size & Hint
50%的数据满足：1 <= n <= 15
100%的数据满足：1 <= n <= 30000, 80 <= w <= 200
*/
