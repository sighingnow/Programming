# include <iostream>
# include <cstdlib>
# define abs(a) (a) >= 0 ? (a) : -(a);
using namespace std;
/*
描述 Description
给出2个序列A={a[1]，a[2]，…，a[n]}，B={b[1]，b[2]，…，b[n]}，从A、B中各选出n个元素进行一一配对（可以不按照原来在序列中的顺序），
并使得所有配对元素差的绝对值之和最大。
*/
int num[100001];
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main(int argc, char **argv)
{
	int n, sum = 0, i;
	cin >> n;
	int x[n], y[n];
	i = n;
	while(i--)
	{
		cin >> x[i];
	}
	i = n;
	while(i--)
	{
		cin >> y[i];
	}
	qsort(x, n, sizeof(int), cmp);
	qsort(y, n, sizeof(int), cmp);
	for(i = 0; i < n; i++)
	{
		sum += abs(x[i] - y[n-1-i]);
	}
	cout << sum;

	return 0;
}

/*
输入格式 InputFormat
输入的第1行为1个正整数n
第2行包含n个正整数，题目中的A序列。 
第3行包含n个正整数，题目中的B序列。 
输出格式 OutputFormat
一个数，最大配对
样例输入 SampleInput [复制数据]
4
2 5 6 3
1 4 6 7
样例输出 SampleOutput [复制数据]
14
*/
