#include <cstdio>
#include <iostream>
using namespace std;

int dp[205][205], n, ans = 0;
int graph[205][205];

int main(int argc, char **argv) {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + graph[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, dp[n][i]);
    }

    printf("%d", ans);

    return 0;
}

