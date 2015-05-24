#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

//二分图最大匹配

bool map[205][205];
int n, m;
int flagx[205], flagy[205];
bool used[205];
int dx[205], dy[205];
int dis;
const int INF = 0x3fffffff;

bool find_path() {
    queue<int>Q;
    dis = INF;
    memset(dx, 0xff, sizeof(dx));
    memset(dy, 0xff, sizeof(dy));
    for(int i = 1; i <= n; ++i) {
        if(flagx[i] == -1) {
            Q.push(i);
            dx[i] = 0;
        }
    }
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if(dx[u] > dis) {
            break;
        }
        for(int v = 1; v <= m; ++v) {
            if(map[u][v] && dy[v] == -1) {
                dy[v] = dx[u]+1;
                if(flagy[v] == -1) {
                    dis = 1;
                }
                else {
                    dx[flagy[v]] = dy[v]+1;
                    Q.push(flagy[v]);
                }
            }
        }
    }
    return (dis != INF);
}

bool dfs(int u) {
    for(int v = 1; v <= m; ++v) {
        if(map[u][v] && !used[v] && dy[v] == dx[u]+1) {
            used[v] = true;
            if(flagy[v] == -1 || dfs(flagy[v])) {
                flagy[v] = u;
                flagx[u] = v;
                return true;
            }
        }
    }
    return false;
}

int Hopcroft_Karp() {
    int ans = 0;
    memset(flagx, 0xff, sizeof(flagx));
    memset(flagy, 0xff, sizeof(flagy));
    while(find_path()) {
        memset(used, 0x00, sizeof(used));
        for(int u = 1; u <= n; ++u) {
            if(!(~flagx[u]) && dfs(u)) {
                ans++;
            }
        }
    }
    return ans;
}

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    int tmp, j;
    while(scanf("%d %d", &n, &m) != EOF) {
        memset(map, 0, sizeof(map));
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &tmp);
            while(tmp--) {
                scanf("%d", &j);
                map[i][j] = true;
            }
        }
        printf("%d\n", Hopcroft_Karp());
    }

    return 0;
}
