#include <cstdio>
using namespace std;

/**
 * 离散函数 f(f(x)) = x 的解的个数。
 *
 * s[0] = s[1] = 1;
 * s[i] = s[i-1]+(i-1)*s[i-2]
 */

const int maxn = 1e6+5, mod = 1e9+7;
long long s[maxn] = {1L, 1L};

int main(int argc, char **argv) {
    int T, t = 0, n;
    // Initial.
    for(int i = 2; i <= 1e6; ++i) {
        s[i] = (s[i-1]+(i-1)*s[i-2])%mod;
    }
    scanf("%d", &T);
    while(++t <= T) {
        printf("Case #%d:\n", t);
        scanf("%d", &n);
        printf("%d\n", s[n]);
    }

    return 0;
}

