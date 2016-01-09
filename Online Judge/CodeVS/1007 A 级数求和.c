# include <stdio.h>

int main()
{
    double s=0.0,i=1.0;
    int k;
    scanf("%d",&k);
    while(s <= k)
    {
        s += 1/i;
        i ++;
    }
    printf("%.0lf",i-1);

    return 0;
}
