#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int T, n, m, mma[205][205], cap[205][205];
int trace[205], vis[205], dist[205];
const int INF = 0x3fffffff;

bool spfa(int s, int t) {
    memset(vis, 0x00, sizeof(vis));
    memset(trace, 0xff, sizeof(trace));
    queue<int> Q;

    for (int i = 0; i <= n+m+1; ++i) {
        dist[i] = INF;
    }

    dist[s] = 0, vis[s] = 1, Q.push(s), trace[s] = s;

    while (!Q.empty()) {
        int head = Q.front();

        for (int i = 0; i <= n+m+1; ++i) {
            if (cap[head][i] > 0 && dist[head]+mma[head][i] < dist[i]) {
                dist[i] = dist[head] + mma[head][i];
                trace[i] = head;

                if (!vis[i]) {
                    Q.push(i), vis[i] = 1;
                }
            }
        }

        Q.pop(), vis[head] = 0;
    }

    return dist[t] < INF;
}

int costflow(int s, int t) {
    int ans = 0, flow = 0;

    while (spfa(s, t)) {
        int p = t, delta = INF;
        flow += 1;

        while (p != s) {
            cap[trace[p]][p] -= 1;
            ans += mma[trace[p]][p];
            p = trace[p];
        }
    }

    return ans;
}

int main(int argc, char** argv) {
    scanf("%d", &T);

    for(int t = 1; t <= T; ++t) {
        scanf("%d%d", &n, &m);

        for (int i = 0; i <= m+n+1; ++i) {
            for (int j = 0; j <= m+n+1; ++j) {
                mma[i][j] = INF;
            }
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = n+1; j <= m+n; ++j) {
                scanf("%d", &mma[i][j]);
                cap[i][j] = 1;
            }
        }

        for (int i = 1; i <= n; ++i) {
            cap[0][i] = 1, mma[0][i] = 0;
        }

        for (int i = n+1; i <= n+m; ++i) {
            cap[i][n+m+1] = 1, mma[i][n+m+1] = 0;
        }

        printf("Case #%d: %d\n", t, costflow(0, n+m+1));
    }

    return 0;
}
