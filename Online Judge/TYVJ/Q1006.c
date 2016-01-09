#include<stdio.h>
int main()
{
	unsigned int a,b,c;
	scanf("%llu %llu %llu",&a,&b,&c);
	if(a+b>c && a+c>b && b+c>a)
		printf("Yes");
	else
		printf("No");
	return 0;
}