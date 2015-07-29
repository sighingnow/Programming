#include<stdio.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[n][n],b[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(j=0;j<n;j++)
    {
        for(i=n-1;i>=0;i--)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}
