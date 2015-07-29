# include <stdio.h>

/*题目描述 Description
一个简单的数学模拟题!
有一座电梯,它的性能如下:
上升一层需要6秒钟,下降一层需要4秒钟,如果要让它停下,它会停5秒钟.
现在告诉你它要按顺序到达然后停靠的N个楼层,求它需要的时间.
电梯开始在0层,楼梯共有100层.
*/
int time(int a,int b)    //每两段用时 
{
	int t;
	if(a < b)
		t = (b - a) * 6 + 5;
	if(a > b)
		t = (a - b) * 4 + 5;
	return t;
}

int main()
{
	int i,n,f[100],t;
	scanf("%d",&n);
	f[0] = 0;
	for(i = 1; i <= n; i++)
		scanf("%d",&f[i]);
	t = 0;
	for(i = 0; i < n; i++)
		t += time(f[i],f[i+1]);
	printf("%d",t);
	
	return 0;
}
/*
输入(elevator.in):第一行为N(N<=50),接下来的N行是它N个停靠的楼层.
输出(elevator.out):只有一行,为所需要的时间.
输入描述 Input Description
输入(elevator.in):第一行为N(N<=50),接下来的N行是它N个停靠的楼层.
输出描述 Output Description
输出(elevator.out):只有一行,为所需要的时间.
样例输入 Sample Input
输入样例1:
1
2
输入样例2:
3
2
3
1
样例输出 Sample Output
输出样例1:
17
输出样例2:
41
*/
