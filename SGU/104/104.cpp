#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

/**
 * SGU 104. Little shop of flowers.
 * 算法：动态规划。
 *
 * 令dp[i][j]表示把前i束花放进前j个花瓶中的value，状态转移方程为：
 *
 *     dp[i][j] = max{dp[i-1][j-1]+mat[i][j], dp[i][j-1]}
 * 
 */

void output(int i, int j, int trace[][105]) {
    if(j == 0) {
        return;
    }
    if(trace[i][j] == 1) {
        output(i-1, j-1, trace);
        printf("%d ", j);
    }
    else {
        output(i, j-1, trace);
    }
}

int main(int argc, char **argv) {

    int F, V, mat[105][105]={{0}}, dp[105][105]={{0}};
    int trace[105][105] = {{0}};
    for(int i = 1; i < 105; ++i) {
        dp[i][i-1] = -0x3fffffff;
    }
    
    scanf("%d%d", &F, &V);
    for(int i = 1; i <= F; ++i) {
        for(int j = 1; j <= V; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    for(int i = 1; i <= F; ++i) {
        for(int j = i; j <= V; ++j) {
            if(dp[i][j-1] > dp[i-1][j-1]+mat[i][j]) {
                dp[i][j] = dp[i][j-1];
            }
            else {
                dp[i][j] = dp[i-1][j-1]+mat[i][j];
                trace[i][j] = 1;
            }
        }
    }
    
    printf("%d\n", dp[F][V]);
    output(F, V, trace);

    return 0;
}

