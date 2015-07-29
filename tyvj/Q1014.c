#include<stdio.h>
int main()
{
	long long n,s,i,t;
	s=0;
	t=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		t=t+i;
		s=s+t;
	}
	printf("%lld",s);
	return 0;
}