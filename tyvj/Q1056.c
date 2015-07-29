#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	if((a%100!=0&&a%4==0)||a%400==0)
		printf("TRUE");
	else
		printf("FALSE");
	system("pause");
	return 0;
} 