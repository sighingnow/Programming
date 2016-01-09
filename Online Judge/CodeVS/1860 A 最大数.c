# include <stdio.h>
# include <string.h>
/*
题目描述 Description
　　设有n个正整数（n≤20），将它们联接成一排，组成一个最大的多位整数。
输入描述 Input Description
　　第一行一个正整数n。
　　第二行n个正整数，空格隔开。
*/
int comp(char *a, char *b)
{
	int len1, len2, i, j, min;
	len1 = strlen(a);
	len2 = strlen(b);
	min = len1 <= len2 ? len1 : len2;
	for(i = 0; i < min; i++)
    {
        if(a[i] != b[i])
            break;
    }
    if(i != min)
    {
        if(a[i] >= b[i])
            return 1;
        else
            return 0;
    }
    else                             //注意排序时想清楚
    { 
        if(len1 > len2)
        {
            for(i = len2, j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++)
            {
                if(a[i] != b[j])
                    break;
            }
            if(a[i] == '\0' || (b[j] != '\0' && a[i] > b[j]) )
                return 1;
            else
                return 0;
        }
        else
        {
            for(i = 0, j = len1; a[i] != '\0' && b[j] != '\0'; i++, j++)
            {
                if(a[i] != b[j])
                    break;
            }
            if(b[j] == '\0' || (a[i] != '\0' && a[i] > b[j]) )
                return 1;
            else
                return 0;
        }
    }
}

int main()
{
	int i, j, n;
	scanf("%d", &n);
	char s[n+1][1000];           //多出来的用于排序
	for(i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(comp(s[i], s[j]) == 1)
			{
				strcpy(s[n], s[i]);
				strcpy(s[i], s[j]);
				strcpy(s[j], s[n]);
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		printf("%s", s[i]);
	}

	return 0;
}

/*
输出描述 Output Description
　　连接成的多位数。
样例输入 Sample Input
Sample 1:
3
13 312 343

Sample 2:
4
7 13 4 246
样例输出 Sample Output
Sample 1:
34331213

Sample 2:
7424613
数据范围及提示 Data Size & Hint
n≤20
*/
