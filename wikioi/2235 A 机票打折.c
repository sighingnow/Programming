# include <stdio.h>

int main()
{
    float barg,price;
    scanf("%f %f",&price,&barg);
    price = price * barg * 0.01;
    printf("%.0f0\n",price);    //已知最后一位为零，故可以直接输出最后一位： 0

    return 0;
}
