# include <stdio.h>
# include <string.h>
/*
题目描述 Description       1517 求一次函数解析式
相信大家都做过练习册上的这种题吧：
已知一个一次函数的图像经过点（x1,y1）、（x2,y2）,求该函数的解析式。
这种题用计算机算是再好不过了！
现在告诉你两个点的坐标，请求出这个一次函数的解析式。
设这个解析式为y=kx+b，你需要输出k和b的值。
*/
int main()
{
	int x1, x2, y1, y2;
	double k, b;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	if(x1 == x2)
	{
		printf("nonono~\n");
	}
	else
	{
		k = ((double)y1 - y2) / (x1 - x2);
		b = (double)y1 - k * (double)x1;
		printf("%.2lf %.2lf\n", k, b);
	}

	return 0;
}

/*
输入描述 Input Description
输入共两行，每一行是一个点的坐标。
输出描述 Output Description
输出共一行，即k,b的值。
样例输入 Sample Input
样例1：
1 2
2 4
样例2：
3 4
-4 5
样例3：
3 100
3 100
样例输出 Sample Output
样例1：
2.00 0.00
样例2:
-0.14 4.43
样例3:
nonono~
数据范围及提示 Data Size & Hint
数据范围：
坐标的数据在integer范围内。（保留2位小数）
若函数解析式不唯一或无解，那么输出'nonono~'。
*/
