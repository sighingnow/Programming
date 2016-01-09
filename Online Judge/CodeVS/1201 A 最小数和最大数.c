# include <stdio.h>

int main()
{
    int n,max,min,i,j;
    scanf("%d",&n);
    int f[n];
    for(i=0;i<n;i++)
        scanf("%d",&f[i]);
    max = f[0];
    min = f[0];
    for(i=0;i<n;i++)
    {
        if(f[i]>max)
            max = f[i];
        if(f[i]<min)
            min = f[i];
    }
    printf("%d %d",min,max);

    return 0;
}
