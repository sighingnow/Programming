#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// 三分法

#define f(x) (sqrt(pow(x-px, 2)+pow(a*x*x+b*x+c-py, 2)))

float a, b, c, px, py, l, r, ml, mr, tmp;

int main(int argc, char** argv) {
    scanf("%f%f%f%f%f", &a, &b, &c, &px, &py);
    l = -200, r = 200;

    while (r-l >= 0.001) {
        tmp = (r-l)/3.0;
        ml = l + tmp, mr = l + tmp + tmp;

        if (f(ml) < f(mr)) {
            r = mr;
        }
        else {
            l = ml;
        }
    }

    printf("%.3f", f(ml));
    return 0;
}
