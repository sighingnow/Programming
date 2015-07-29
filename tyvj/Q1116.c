# include <stdio.h>
# include <string.h>
/*
题目描述 Description
回文数是指从左向右念和从右像做念都一样的数。如12321就是一个典型的回文数。
给定一个进制B(2<=B<=20十进制)，输出所有的大于等于1小于等于300且它的平方用B进制表示时是回文数的数。用’A’,’B’……表示10，11等等。
*/
int main()
{
	int n, i, j, top, mid, k, flag, top1;
	int s[10000], ch[10000];
	scanf("%d", &n);
	for(k = 1; k <= 300; k++)
	{
		top = 0, i = k * k, flag = 0;
		while(i > 0)
		{
			s[top++] = i % n;
			i /= n;
		}
		mid = top / 2;
		for(j = 0; j <= mid; j++)
		{
			if(s[j] != s[top-1-j])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			i = k, top1 = 0;
			while(i > 0)
			{
				ch[top1++] = i % n;
				i /= n;
			}
			while(top1--)
			{
				if(ch[top1] < 10)
					printf("%d", ch[top1]);
				else
					printf("%c", 'A' + ch[top1] - 10);
			}
			printf(" ");      //第一个数也以 B 进制形式输出
			while(top--)
			{
				if(s[top] < 10)
					printf("%d", s[top]);
				else
					printf("%c", 'A' + s[top] - 10);
			}
			printf("\n");
		}
	}

	return 0;
}

/*
输入描述 Input Description
共一行，一个单独的整数B(B用十进制表示)。
输出描述 Output Description
每行两个数字，第二个数是第一个数的平方，且第二个数是回文数。
样例输入 Sample Input
10
样例输出 Sample Output
1 1
2 4
3 9
11 121
22 484
26 676
101 10201
111 12321
121 14641
202 40804
212 44944
264 69696
数据范围及提示 Data Size & Hint
*/
