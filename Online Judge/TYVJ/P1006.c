# include <stdio.h>

int main()
{
    char b[13];
    int i,a[13],t;
    scanf("%s",&b);
    for(i = 0;i < 13;i++)
        a[i] = b[i] - '0';
    t = (a[0]*1 + a[2]*2 + a[3]*3 + a[4]*4 + a[6]*5 + a[7]*6 + a[8]*7 + a[9]*8 + a[10]*9)%11;
    if ((t == a[12]) ||(t==10&&b[12]=='X'))
        printf("Right");
    else
    {
        for(i = 0;i < 12; i++)
            printf("%c",b[i]);
        if(t <= 9)
            printf("%d",t);
        else
            printf("X");
    }
    return 0;
}
