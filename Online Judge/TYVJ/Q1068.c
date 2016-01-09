# include <stdio.h>

int main()
{
    int a,b,m=1;
    scanf("%d %d",&a,&b);
    while(a*m <= b)
    {
        m++;
    }
    printf("%d",m);
    return 0;
}
