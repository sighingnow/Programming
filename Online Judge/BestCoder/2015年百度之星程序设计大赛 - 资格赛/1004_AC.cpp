#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
    int T, t = 0;
    double n, a, r;
    scanf("%d", &T);
    while(++t <= T) {
        printf("Case #%d:\n", t);
        scanf("%lf %lf %lf", &n, &a, &r);
        if(a >= r * 2 * tan(3.1415926/n)) {
            printf("Give me a kiss!\n");
        }
        else {
            printf("I want to kiss you!\n");
        }
    }

    return 0;
}

