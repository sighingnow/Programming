#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main(int argc, char **argv) {
    int a, b, k;
    double p=(1+sqrt(5.0))/2;
    while(scanf("%d%d",&a,&b)==2) {
        if(a>b) {
            swap(a,b);
        }
        k = a / p;
        if((a==int(k*p)&&b==a+k) || (a==int((k+1)*p)&&b==a+k+1)) { 
            printf("0\n");
        }
        else { 
            printf("1\n");
        }
    }
    return 0;
}

