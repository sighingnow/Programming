# include <stdio.h>
# include <string.h>

int main()
{
	int i, n, x=0, y=0, k;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		k = i;
		while(k % 5 == 0)
		{
			k /= 5;
			x ++;
		}
		while(k % 2 == 0)
		{
			k /= 2;
			y++;
		}
	}
	printf("%d\n", x < y ? x : y);
	
	return 0;
}

