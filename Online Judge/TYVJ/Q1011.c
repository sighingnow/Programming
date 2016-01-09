# include <stdio.h>
# include <string.h>

int main()
{
	int a, b, c;
	while(scanf("%d %d", &a, &b) == 2)
	{
		while(a % b != 0)
		{
			c = a % b;
			a = b;
			b = c;
		}
		printf("%d\n", b);
	}

	return 0;
}