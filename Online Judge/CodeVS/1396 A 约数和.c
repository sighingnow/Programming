# include <stdio.h>
int f[5000001];
int main()
{
	long long t, n, i, sum;
	scanf("%lld", &t);
	while(t--)
	{
		sum = 0;
		scanf("%lld", &n);
		if(!f[n])
		{
			for(i = 1; i * i < n; i++)
			{
				if(n % i == 0)
					sum += (i + n / i);
			}
			if(i * i == n)
				sum += i;
			f[n] = sum;
 		}
 		printf("%lld\n", f[n]);
	}
	
	return 0;
}

