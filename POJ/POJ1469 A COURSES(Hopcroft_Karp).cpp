#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

//二分图最大匹配

bool map[105][305];
int p, n;
int flagx[105], flagy[305];
bool used[305];
int dx[105], dy[305];
int dis;
const int INF = 0x3fffffff;

bool find_path() {
    queue<int>Q;
    dis = INF;
    memset(dx, 0xff, sizeof(dx));
    memset(dy, 0xff, sizeof(dy));
    for(int i = 1; i <= p; ++i) {
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
        for(int v = 1; v <= n; ++v) {
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
    for(int v = 1; v <= n; ++v) {
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
        for(int u = 1; u <= p; ++u) {
            if(!(~flagx[u]) && dfs(u)) {
                ans++;
            }
        }
    }
    return ans;
}

int main(int argc, char **argv) {
    int T = 0, tmp, j;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &p, &n);
        memset(map, 0, sizeof(map));
        for(int i = 1; i <= p; ++i) {
            scanf("%d", &tmp);
            while(tmp--) {
                scanf("%d", &j);
                map[i][j] = true;
            }
        }
        puts(Hopcroft_Karp() == p ? "YES" : "NO");
    }

    return 0;
}
