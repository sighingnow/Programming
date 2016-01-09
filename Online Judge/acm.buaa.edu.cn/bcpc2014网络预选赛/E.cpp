#include <cmath>
#include <cstdio>

int main(int argc, char **argv) {
    int n, p, k, f1, f2;
    long double p1, p2, p3, ans;
    while(~scanf("%d %d %d %d %d", &n, &p, &k, &f1, &f2)) {
        p1 = (long double)(p+1-f1) / (p+1);
        p2 = (long double)(p+1-f2) / (p+1);
        p3 = (long double)f2 / (p+1);
        ans = 0;
        if(f1 < f2) {
            ans += pow(p1, n);
        }
        for(int i = k; i <= n; ++i) {
            ans += (long double) (n+1-i) * pow(p2, i) * pow(p3, n-i);
        }

        printf("%.3llf\n", ans);
    }
}

