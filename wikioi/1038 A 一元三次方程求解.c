# include <stdio.h>
# include <math.h>
/*
题目描述 Description
有形如：ax3+bx2+cx+d=0  这样的一个一元三次方程。给出该方程中各项的系数(a，b，c，d  均为实数)，并约定该方程存在三个不同实根
(根的范围在-100至100之间)，且根与根之差的绝对值>=1。要求由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确
到小数点后2位。
提示：记方程f(x)=0，若存在2个数x1和x2，且x1<x2，f(x1)*f(x2)<0，则在(x1，x2)之间一定有一个 根。
*/
float a, b, c, d;
float f(float x)
{
	return a * x * x * x + b * x * x + c * x + d;
}
float abs(float x)
{
	return x >= 0 ? x : (-x);
}
int main()
{
	float mid, min, max, x[6];
	int i, t=0;
	scanf("%f %f %f %f", &a, &b, &c, &d);
	for(i = -100; i < 100; i++)
	{
		if(f((float)i) * f((float)i+1) <= 0)
		{
			min = (float)i, max = (float)i + 1, mid = (min + max) / 2;
			while(abs(f(mid)) >= 0.01)
			{
				if(f(mid) * f(min) <= 0)
					max = mid, mid = (min + max) / 2;
				else
					min = mid, mid = (min + max) / 2;
			}
			x[t++] = mid;
		}
		if(t >= 6)
			break;
	}
	printf("%.2f ", x[0]);
	for(i = 1, t = 1; t < 3; i++)
	{
		if(abs(x[i]-x[i-1]) >= 0.01)
		{
			printf("%.2f ", x[i]);
			t++;
		}
	}
	return 0;
}

/*
输入描述 Input Description
一个三次方程的各项系数
输出描述 Output Description
三个解
样例输入 Sample Input
1   -5   -4   20
样例输出 Sample Output
-2.00   2.00   5.00
数据范围及提示 Data Size & Hint
*/
