# include <stdio.h>

int main()
{
	long long int sum=0, n, i, k, flag;
	scanf("%lld", &n);
	for(i = 1; i <= n; i++)
	{
		flag = 0;
		if(i % 3 == 0 || i % 5 == 0)
			flag = 1;
		else
		{
			k = i;
			while(k > 0)
			{
				if(k % 10 == 3 || k % 10 == 5)
				{
					flag = 1;
					break;
				}
				k /= 10;
			}
		}
		if(!flag)
			sum += i * i;
	}
	printf("%lld", sum);
	
	return 0;
}
