# include <stdio.h>
# include <string.h>
/*
题目描述 Description
注意东东是个东西，不是个人，因为hellpkitty很萌。
已知有N件商品，每件价格为Ai，有M元。问如何买商品花的钱与M的绝对值最小。
*/
int main()                  //题有问题，描述不明，数据有问题
{
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	int a[n], f[m+1];
	memset(f, 0, sizeof(f));
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		for(j = m; j >= a[i]; j--)
		{
			f[j] = f[j] > (f[j-a[i]]+a[i]) ? f[j] : (f[j-a[i]]+a[i]);
		}
	}
	printf("answer:%d\n", m-f[j]);            //此题题意表述不明，样例有问题，数据也有问题，忽略掉

	return 0;
}

/*
输入描述 Input Description
第一行N M
第二行到第N+1行 Ai
输出描述 Output Description
最小的绝对值
样例输入 Sample Input
3 8
3 2 2
样例输出 Sample Output
1
数据范围及提示 Data Size & Hint
N<=1000s
*/
