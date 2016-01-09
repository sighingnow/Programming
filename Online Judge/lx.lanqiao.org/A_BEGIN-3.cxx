#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
    int r;
    scanf("%d", &r);
    double pi = atan(1.0) * 4;
    printf("%.7lf", pi * (double) r * (double) r );
    return 0;
}

