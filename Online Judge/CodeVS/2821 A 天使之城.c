# include <stdio.h>
/*
题目描述 Description
天使城有一个火车站，每辆火车都从A方向驶入车站，
再从B方向驶出车站。
 
为了调度火车，火车站设有停放轨道，可存放5辆火车。已知从A进入车站顺序为1、2、3……。现在给你一个调度方案，判断是否可行，
如果可行，输出出站顺序。
有以下几种调度方法：
A. 将A上的头一辆车驶出B方向
B. 将A上的头一辆车停入暂停轨道
C. 将暂停轨道上最外面的车驶出B方向
输入描述 Input Description
输入第一行一个整数N(n<30)表示调度方案步骤数目。
下一行一个字符串，有N个大写字母，表示调度方法。
*/
int main()
{
	int stack[5] = {0}, s_top = 0;
	int car[30] = {0};    //存放火车驶出顺序
	int i, n, k;
	char ch[30];
	int t = 1;     //记录火车编号
	scanf("%d", &n);
	scanf("%s", ch);
	k = 0;
	for(i = 0; i < n; i++)
	{
		if(ch[i] == 'A')
		{
			car[k++] = t ++;
		}
		else if(ch[i] == 'B')
		{
			if(s_top >= 4)    //注意是 4
			{
				printf("No\n");
				return 0;
			}
			else
			{
				stack[s_top ++] = t ++;
			}
		}
		else if(ch[i] == 'C')
		{
			if(s_top <= 0)
			{
				printf("No\n");
				return 0;
			}
			else
			{
				car[k++] = stack[-- s_top];
			}
		}
	}
	printf("Yes\n");
	for(i = 0; i < k; i++)
	{
		printf("%d\n", car[i]);
	}

	return 0;
}

/*
输出描述 Output Description
输出若不可行（暂停站满了还停车、暂停站空了还出车），则输出一行“No”。
若可行，输出一行“Yes”，再输出若干行，每行一个整数，表示车出站序列。
样例输入 Sample Input
[样例输入1]
6
ABBCCA
[样例输入2]
5
BACAC
 
样例输出 Sample Output
[样例输出1]
Yes
1
3
2
4
[样例输出2]
No
数据范围及提示 Data Size & Hint
如题
*/
