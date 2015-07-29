#include<stdio.h>

int main()
{
    int n,i,s=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        s+=i*(1+i)/2;
    printf("%d",s);
    return 0;
}
