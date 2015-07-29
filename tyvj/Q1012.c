#include<stdio.h>
#include<math.h>

int main()
{
	long long int n,i,m=0,x,s,t,a;
	scanf("%lld",&n);
	if(n==1)
		printf("0");
	else
	{
		for(s=2;s<=(long long int)sqrt(n);s++)
		{
			a=(long long int)sqrt(s);
			for(t=2;t<=a;t++)
				if(s%t==0)
					break;
			if(t>a)
				m=m+1;
		}
		printf("%lld",m);
	}
	return 0;
}
