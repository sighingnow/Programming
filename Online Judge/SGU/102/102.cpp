#include <cstdio>
using namespace std;

/**
 * SGU 102. Coprimes.
 * GCD
 */

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

int main(int argc, char **argv) {
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        if(gcd(n, i) == 1) {
            ans++;
        }
    }
    printf("%d", ans);
    return 0;
}

