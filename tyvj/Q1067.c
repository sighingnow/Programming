# include <stdio.h>

int main()
{
    int n;
    double s=0.0,i=1.0;
    scanf("%d",&n);
    while(s<n)
    {
        s += 1/i;
        i++;
    }
    printf("%.0f",i-1);
    return 0;
}
