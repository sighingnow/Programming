#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<int> e[100100];
bool flag[100100];
int depth[100100], ans, n;

int bfs(int start) {
    memset(flag, 0x00, sizeof(flag));
    memset(depth, 0x00, sizeof(depth));
    queue<int> Q;
    Q.push(start);
    flag[start] = true;
    while(!Q.empty()) { 
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < e[u].size(); ++i) {
            if(!flag[e[u][i]]) {
                depth[e[u][i]] = depth[u]+1;
                flag[e[u][i]] = true;
                Q.push(e[u][i]);
            }
        }
    }
    int point = -1;
    ans = -1;
    for(int i = 1; i <= n; ++i) {
        if(depth[i] > ans) {
            ans = depth[i];
            point = i;
        }
    }
    return point;
}

int main(int argc, char **argv) {
    int x, y;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        scanf("%d %d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    bfs(bfs(1));
    printf("%d", ans);

    return 0;
}

