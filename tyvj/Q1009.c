#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int a,i,s;
	scanf("%llu",&a);
	if(a==1)
		printf("No");
	else
	{
	i=2;
	s=sqrt(a);
	for(i=2;i<=s;i++)
	{
		if(a%i==0)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	}
	return 0;
}