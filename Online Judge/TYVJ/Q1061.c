#include<stdio.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    long int a[n];
    for(i=0;i<n;i++)
        scanf("%ld",&a[i]);
    for(i=0;i<n;i++)
        printf("%ld ",a[i]);
    return 0;
}
