#include <cstdio>
#include <iostream>
using namespace std;

int need[510], value[510];
int dp[510][100010];

int main(int argc, char **argv) {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d", need+i, value+i);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(j >= need[i]) {    
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-need[i]] + value[i]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("%d", dp[n][m]);

    return 0;
}

