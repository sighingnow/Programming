#include <cstdio>
#include <cstring>
using namespace std;

const int maxh = 11, maxw = 11;

int h, w, edge[(1<<maxw)*11+1][2], top = 0;
long long dp[2][1<<maxw] = {{0}};

void dfs(int l, int now, int pre) {
    if(l > w) { return; }
    if(l == w) { edge[top][0] = pre; edge[top++][1] = now; return; }
    dfs(l+1, now<<1, (pre<<1)|1);
    dfs(l+1, (now<<1)|1, pre<<1);
    dfs(l+2, (now<<2)|3, (pre<<2)|3);
}

int main(int argc, char **argv) {
    while(scanf("%d %d", &h, &w) && h+w) {
        top = 0; dfs(0, 0, 0);
        memset(dp, 0x00, sizeof(dp));
        dp[0][(1<<w)-1] = 1;
        for(int i = 0; i < h; ++i) {
            memset(dp[(i+1)%2], 0x00, sizeof(dp[0][0])*(1<<maxw));
            for(int j = 0; j < top; ++j) {
                dp[(i+1)%2][edge[j][1]] += dp[i%2][edge[j][0]];
            }
        }
        printf("%lld\n", dp[h%2][(1<<w)-1]);
    }
    return 0;
}

