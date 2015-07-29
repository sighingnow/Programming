# include <stdio.h>

double abs(double a)    //abs若用宏写，则为   # define abs (a>=0?a:(-a))    最外层的括号不能漏掉
{
    if(a >= 0)
        return a;
    else
        return (-a);
}

int main()
{
    double a,b;
    scanf("%lf %lf",&a,&b);
    if(abs(a-b) < 0.00000001)   //做差，判断差点大小，进而判断梁漱是否相等
        printf("yes\n");          //必须用绝对绝对值反对
    else
        printf("no\n");

    return 0;
}
