#include <cstdio>
using namespace std;

int array[1010], n, ans = 0;
int dp[1001][2001] = {0};

int main(int argc, char **argv) {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", array+i);
    }
    ans = n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i-1; ++j) {
            int d = 1000 + (array[i]-array[j]);
            dp[i][d] += (dp[j][d] + 1);
            ans += (dp[j][d]+1);
            ans %= 9901;
        }
    }
    printf("%d", ans);
    
    return 0;
}

