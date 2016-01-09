#include<stdio.h>
#include<math.h>

int prime(long long int a)
{
    long long int b;
    int i;
    if(a<=1)
        return 0;
    else
    {
    b=(long long int)sqrt(a);
    for(i=2;i<=b;i++)
        if(a%i==0)
            break;
    if(i>=b)
        return 1;
    else
        return 0;
    }
}

int main()
{
    int i,j,k,n;
    scanf("%d %d",&n,&k);
    long long int a[n],t,min,max,m;
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(i = 0;i < n;i ++)
        for(j = i;j < n;j ++)
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
    min=a[k-1];
    max=a[n-k];
    m=max-min;
    if(prime(m)==1)
        printf("YES\n");
    else if(prime(m)==0)
        printf("NO\n");
    printf("%lld",m);
    return 0;
}
