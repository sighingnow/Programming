#include<stdio.h>

int main()
{
    int n,i,j,x,y;
    scanf("%d",&n);
    x=n;
    y=2*n-1;
    char a[x][y];
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
        {
            if(i+j>=n-1 && j-i<=n-1)
                a[i][j]='*';
            else
                a[i][j]=' ';
        }
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
            printf("%c",a[i][j]);
        printf("\n");
    }
    return 0;
}
