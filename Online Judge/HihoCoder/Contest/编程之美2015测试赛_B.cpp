#include <iostream>
#include <cstdio>
using namespace std;

// f[n] = 1/8 n^3 (1 + n)^3 - 1/2 n (1 + n) (-n + n^3)

int main(int argc, char** argv) {
    long long T, n, MOD = 1000000007;
    long long ans, tmp1, tmp2;

    scanf("%lld", &T);

    for(int t = 1; t <= T; ++t) {
        scanf("%lld", &n);
        tmp1 = (((n%MOD)*(n%MOD))%MOD)*(n%MOD)%MOD;
        tmp2 = ((((n+1)%MOD)*((n+1)%MOD))%MOD)*((n+1)%MOD)%MOD;
        ans = (tmp1*tmp2/8)%MOD-((n%MOD)*((n+1)%MOD))/2*(tmp1-(n%MOD))%MOD;

        if (ans < 0) {
            ans += MOD;
        }

        printf("Case #%d: %lld\n", t, ans);
    }

    return 0;
}
