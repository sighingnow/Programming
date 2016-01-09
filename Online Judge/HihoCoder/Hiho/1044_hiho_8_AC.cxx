#include <cstdio>
#include <iostream>
using namespace std;

int n, m, q, dp[2][1100], w[1100];

/*
 * calculate how many ones in x.
 **/
inline int clo(int x) {
    int ans = 0;
    while(x) {
        ans += x % 2;
        x /= 2;
    }
    return ans;
}

int solve() {
    int flag = 1, k = (1 << m) - 1, ans = -1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < (1 << m); ++j) {
            dp[flag][(j<<1|0) & k] = max(dp[flag][(j<<1|0) & k], dp[flag^1][j]);
            if(clo(j & (k >> 1)) < q) {
                dp[flag][(j<<1|1) & k] = max(dp[flag][(j<<1|1) & k], dp[flag^1][j] + w[i]);
            }
        }
        flag ^= 1;
    }
    for(int i = 0; i < (1<<m); ++i) {
        ans = max(dp[flag^1][i], ans);
    }
    return ans;
}

int main(int argc, char **argv) {
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", w+i);
    }
    printf("%d", solve());

    return 0;
}

