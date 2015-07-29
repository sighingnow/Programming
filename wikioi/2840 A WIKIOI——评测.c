# include <stdio.h>
# include <string.h>
char s[10000], ans[10000];
int k, t, n;
int main()
{
	scanf("%d %d", &n, &k);
	while(n--)
	{
		scanf("%s %s %d", s, ans, &t);
		if(strcmp(s, ans) != 0)
		{
			printf("WA");
			break;
		}
		else
		{
			if(t > k)
			{
				printf("TLE\n");
				break;
			}
		}
	}
	if(n < 0)
		printf("AC\n");
	
	return 0;
}

