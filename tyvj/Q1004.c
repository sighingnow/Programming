#include<stdio.h>
int main()
{
	long int m,n,t,s,i;
	scanf("%ld %ld",&m,&n);
	if(m<=n)
	{
		t=m;
		m=n;
		n=t;	
	}
	s=m-1 + m * (n-1);
	printf("%ld",s);
	return 0;
}