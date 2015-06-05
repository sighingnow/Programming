#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

/**
 * POJ 1932.
 * SPFA 求解最长路
 *
 * spfa求最长路，判断dist[n] > 0，需要注意的是有正环存在，如果有环存在，那么
 * 就要判断这个环上的某一点是否能够到达n点,如果能，就说明可以到达，否则，就
 * 说明不能。
 */

const int maxn = 1e2+5;
const int INF = 0x3fffffff;
int n, st, energy[maxn];
int dp[maxn], cnt[maxn];
vector<int> g[maxn];
bool mark[maxn];

bool spfa() {
    for(int i = 1; i <= n; ++i) { dp[i] = -INF; }
    memset(mark, 0x00, sizeof(mark)); memset(cnt, 0x00, sizeof(cnt));
    queue<int>Q; Q.push(1); dp[1] = 100;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop(); mark[u] = false;
        if(cnt[u]++ > n || u == n) {
            st = u;
            return true;
        }
        for(int i = 0; i < (int)g[u].size(); ++i) {
            int v = g[u][i];
            if(dp[u]+energy[v]>dp[v] && dp[u]+energy[v]>0) {
                dp[v] = dp[u]+energy[v];
                if(!mark[v]) {
                    mark[v] = true; Q.push(v);
                }
            }
        }
    }
    return false;
}

void dfs(int u) {
    mark[u] = true;
    for(int i = 0; i < (int)g[u].size(); ++i) {
        int v = g[u][i];
        if(!mark[v]) { dfs(v); }
    }
}

int main(int argc, char **argv) {
    int u, k;
    while(cin >> n && n != -1) {
        for(int i = 1; i <= n; ++i) { g[i].clear(); }
        for(int i = 1; i <= n; ++i) {        
            cin >> energy[i] >> k;
            while(k--) {
                cin >> u;
                g[i].push_back(u);
            }
        }
        st = -1;
        if(spfa()) {
            memset(mark, 0x00, sizeof(mark));
            dfs(st);
            if(mark[n]) {
                cout << "winnable" << endl;
            }
            else {
                cout << "hopeless" << endl;
            }
        }
        else {
            if(dp[n] > 0) {
                cout << "winnable" << endl;
            }
            else {
                cout << "hopeless" << endl;
            }
        }
    }

    return 0;
}

