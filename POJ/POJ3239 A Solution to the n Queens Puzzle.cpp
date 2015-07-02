#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

void queens_puzzle(int n)//n>=8
{
    if(n%6!=2 && n%6!=3)
    {
        printf("2");
        for(int i=4;i<=n;i+=2)
            printf(" %d",i);
        for(int i=1;i<=n;i+=2)
            printf(" %d",i);
        printf("\n");
    }
    else
    {
        int k=n/2;
        if(n%2==0 && k%2==0)
        {
            printf("%d",k);
            for(int i=k+2;i<=n;i+=2)
                printf(" %d",i);
            for(int i=2;i<=k-2;i+=2)
                printf(" %d",i);
            for(int i=k+3;i<=n-1;i+=2)
                printf(" %d",i);
            for(int i=1;i<=k+1;i+=2)
                printf(" %d",i);
        }
        else if(n%2==1 && k%2==0)
        {
            printf("%d",k);
            for(int i=k+2;i<=n-1;i+=2)
                printf(" %d",i);
            for(int i=2;i<=k-2;i+=2)
                printf(" %d",i);
            for(int i=k+3;i<=n-2;i+=2)
                printf(" %d",i);
            for(int i=1;i<=k+1;i+=2)
                printf(" %d",i);
            printf(" %d",n);
        }
        else if(n%2==0 && k%2==1)
        {
            printf("%d",k);
            for(int i=k+2;i<=n-1;i+=2)
                printf(" %d",i);
            for(int i=1;i<=k-2;i+=2)
                printf(" %d",i);
            for(int i=k+3;i<=n;i+=2)
                printf(" %d",i);
            for(int i=2;i<=k+1;i+=2)
                printf(" %d",i);
        }
        else
        {
            printf("%d",k);
            for(int i=k+2;i<=n-2;i+=2)
                printf(" %d",i);
            for(int i=1;i<=k-2;i+=2)
                printf(" %d",i);
            for(int i=k+3;i<=n-1;i+=2)
                printf(" %d",i);
            for(int i=2;i<=k+1;i+=2)
                printf(" %d",i);
            printf(" %d",n);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    freopen("input.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    while(~scanf("%d",&n))
    {
        if(!n) break;
        queens_puzzle(n);
    }
    return 0;
}