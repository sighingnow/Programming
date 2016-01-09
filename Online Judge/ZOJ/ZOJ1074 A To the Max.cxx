#include <cstdio>
#include <cstring>
using namespace std;

//将二维问题转化为一维DP，减小时间复杂度

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    
    int ans = -0x3ffffff;
    int n;
    int num[110][110];
    int dp[110]; // i-j 行对应列元素的和
    memset(num, 0, sizeof(num));

    scanf("%d", &n);
    for(int i = 1;i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &num[i][j]);
        }
    }

    for(int i = 1; i <= n; ++i) {
        memset(dp, 0, sizeof(dp));
        for(int j = i; j <= n; ++j) {
            int sum = 0;
            for(int k = 1; k <= n; ++k) {
                dp[k] += num[j][k];
                sum += dp[k];
                if(sum < 0) {
                    sum = dp[k];
                }
                if(sum > ans) {
                    ans = sum;
                }
            }
        }
    }

    printf("%d", ans);

    return 0;
}
