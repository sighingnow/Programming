#include<stdio.h>
#include<math.h>
int main()
{
	unsigned long long a,b;
	int s;
	scanf("%llu %llu",&a,&b);
	s=log10(a)+log10(b)+1;
	printf("%d",s);
	system("pause");
	return 0;
}
//Êý¾Ý·¶Î§£º0ÖÁ2^64 