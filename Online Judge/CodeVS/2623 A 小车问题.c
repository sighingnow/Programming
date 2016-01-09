# include <stdio.h>
# include <string.h>
# include <math.h>
/*
题目描述 Description
甲、乙两人同时从A地出发要尽快同时赶到B地。出发时A地有一辆小车，可是这辆小车除了驾驶员外只能带一人。已知甲、乙两人的步行速度一样，且小于车的速度。问：怎样利用小
车才能使两人尽快同时到达。
*/
int main()
{
	double t, v1, v2, s, tmp;
	scanf("%lf %lf %lf", &s, &v1, &v2);
	tmp = v2 / v1;
	t = (1 + tmp) * s / v2 / (tmp + 3) + 2 * s / (tmp + 3) / v1;
	printf("%.2f", t);
	
	return 0;
}

/*
输入描述 Input Description
仅一行，三个整数，分别表示AB两地的距离s米（s≤2000），人的步行速度a米/秒，车的速度b米/秒，2000>b>a。
输出描述 Output Description
两人同时到达B地需要的最短时间,单位秒，保留2位小数。
样例输入 Sample Input
120  5  25
样例输出 Sample Output
9.60
数据范围及提示 Data Size & Hint
题目已经给出。请注意保留两位小数。
*/
