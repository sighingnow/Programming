#include<stdio.h>
#include<math.h>

int prime(int a)
{
    int b,i;
    if(a<=1)
        return 0;
    else
    {
    b=(int)sqrt(a);
    for(i=2;i<=b;i++)
        if(a%i==0)
            break;
    if(i>b)
        return 1;
    else
        return 0;
    }
}

int main()
{
    int a,b,i,n=0;
    scanf("%d %d",&a,&b);
    for(i=a;i<=b;i++)
        if(prime(i)==1)
            n+=1;
    printf("%d",n);
    return 0;
}
