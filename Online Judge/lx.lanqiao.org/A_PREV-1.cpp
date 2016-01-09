#include <cstdio>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;        
    }
    return gcd(b, a%b);
}

int main(int argc, char **argv) {
    int a, b, c, d;
    scanf("%d%d%d",&a,&b,&c);
    d = a*b/gcd(a, b);
    printf("%d", d*c/gcd(d,c));

    return 0;
}

