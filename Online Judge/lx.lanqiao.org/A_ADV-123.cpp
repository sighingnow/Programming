#include<iostream>
#include<cstdio>
using namespace std;
double dp[110][100010] = {{0.0}};

int main(int argc, char **argv)
{
    int n, a, b, x;
    scanf("%d%d%d%d", &n, &a, &b, &x);
    double p = 1.0/(b-a+1);
    for(int i = 1; i <= n; ++i) {
        for(int j = a*i; j <= b*i && j <= x; ++j) {
            if (i == 1) {
                dp[i][j] = p;
                continue;
            }
            double pp = 0;
            for(int z = a; z <= b; ++z) {
                if(j >= z) {
                    pp += dp[i-1][j-z]*p;
                }
            }
            dp[i][j] = pp;
        }
    }
    printf("%.4f", dp[n][x]);

    return 0;
}
