# include <stdio.h>
# include <math.h>

int main(int argc, char **argv)
{
	int n, i, k, t = 0;
	scanf("%d", &n);
	if(n == 1)
		t = 1;
	else if(n < 1000000)
	{
		for(i = 1; i <= n; i++)
			if(n % i == 0)
				t++;
	}
	else
	{
		k = sqrt(n);
		for(i = 1; i < k; i++)
		{
			if(n % i == 0)
				t += 2;
		}
		if(k * k == n)
			t ++;
	}
	printf("%d", t);

	return 0;
}
