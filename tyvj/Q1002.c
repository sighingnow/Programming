#include<stdio.h>

int main()
{
    long long a,b;
    long long c;
    scanf("%lld %lld",&a,&b);
    if(a >= 1 && a <=100000 && b>=1 && b<=100000)
    {
        printf("%lld\n",a+b);
        printf("%lld\n",a-b);
        printf("%lld\n",c);
        printf("%lld\n",a/b);
    }
    return 0;
}
