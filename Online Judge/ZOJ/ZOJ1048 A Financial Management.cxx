#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

//ZOJ 1048

int main(int argc, char **argv)
{
    double sum = 0, tmp;
    for(int i = 1; i <= 12; ++i)
    {
        scanf("%lf", &tmp);
        sum += tmp;
    }
    printf("$%.2lf", sum / 12.0);
    
    return 0;
}
