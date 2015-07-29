#include <iostream>
#include <cstdio>
using namespace std;

//wikioi 2800

int n;
int dis[16][16];
int dp[1 << 16][16];
const int INF = 0x3fffffff;

void init()
{
    scanf("%d", &n);
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= n; ++j)
            scanf("%d", &dis[i][j]);
    }
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 0; j <= n; ++j)
        {
            for(int k = 0; k <= n; ++k)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        }
    }
}

int pow_2(int t)
{
    if(t == 0)
        return 0;
    else
        return 1 << t;
}

int tsp_dp()
{
    for(int i = 0; i <= n; ++i)
    {
        for(int s = 0; s < pow_2(n+1); s++)
            dp[s][i] = INF;
        dp[pow_2(i)][i] = dis[i][0];
    }
    for(int s = 0; s < pow_2(n+1); s += 2)
    {
        for(int now = 1; now <= n; ++now)
        {
            for(int pre = 1; pre <= n; ++pre)
                if(now != pre && ((s >> pre) & 1) && (s >> now) & 1)
                    dp[s][now] = min(dp[s][now], (dp[s-pow_2(now)][pre] + dis[now][pre]));
        }
    }
    int ans = INF, s = pow_2(n+1) - 2;
    for(int i = 1; i <= n; ++i)
        ans = min(ans, dp[s][i] + dis[0][i]);
    return ans;
}
//先floyd，再进行状态压缩的DP，枚举每个状态和当前城市以及上一个城市即可。
//dp[S][now]=min(dp[S][now],dp[S-(1<<now)][next]+fl[next][now]);
int main()
{
    init();
    printf("%d", tsp_dp());
    return 0;
}
