#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1005, maxm = 2005;
struct Inter {
    int l, r, w;
    bool operator < (const Inter &a) const {
        if(l != a.l) { return l < a.l; }
        return r > a.r;
    }
} p[maxn];

double f[maxn][maxm];
int T, t = 0, n, m;

double calc(double len) {
    if(len < 0) { return 0; }
    return (len/2)*(len/2);
}

int main(int argc, char** args) {
    int x, y, w; scanf("%d", &T);
    while(++t <= T) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            p[i] = (Inter){x-y, x+y, w};
            m = max(m, x+y);  // up bound.
        }
        sort(p+1, p+1+n);
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                f[i][j] = -1e60;
            }
        }
        double ans = 0;
        for(int i = 1; i <= n; ++i) {   // DP.
            for(int j = 0; j <= m; ++j) {
                if(j == p[i].r) {
                    f[i][j] = max(f[i][j], p[i].w-calc(p[i].r-p[i].l));
                }
                f[i][j] = max(f[i][j], f[i-1][j]);
                int q = max(j, p[i].r);
                if(p[i].r <= j) {
                    f[i][j] = max(f[i][j], f[i-1][j]+p[i].w); 
                }
                else {
                    f[i][q] = max(f[i][q], f[i-1][j]+p[i].w+calc(j-p[i].l)-calc(p[i].r-p[i].l));
                }
            }
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                ans = max(ans, f[i][j]);
            }
        }
        printf("Case #%d: %.2f\n", t, ans);
    }
    return 0;
}

