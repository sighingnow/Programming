#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int max_n = 105;
const int INF = 0x3ffffff;
int n, et;
bool link[max_n][max_n];
int dist[max_n];
int vis[max_n];

void bfs() {
    for(int i = 0; i < n; ++i) {
        dist[i] = INF;
    }
    dist[et] = 0;
    queue <int> Q;
    Q.push(et);
    while(!Q.empty()) {
        int y = Q.front();
        Q.pop();
        for(int i = 0; i < n; ++i) {
            if(link[i][y] && dist[y]+1 < dist[i]) {
                Q.push(i);
                dist[i] = dist[y] + 1;
            }
        }
    }
} 

bool dfs(int id) {
    if(id == et) {
        return true;
    }
    vis[id] = true;
    for(int i = 0; i < n; ++i) {
        if(!vis[i] && link[id][i]) {
            if(dfs(i)) {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);

    char input[10];
    int T, u, v;
    scanf("%d", &T);
    while(T--) {
        memset(link, 0x00, sizeof(link));
        scanf("%d %d\n", &n, &et);
        while(gets(input)) {
            if(!strcmp(input, "")) {
                break;
            }
            sscanf(input, "%d %d", &u, &v);
            link[u][v] = true;
        }
        bfs();

        int min_d = dist[0], room = 0;
        for(int i = 1; i < n; ++i) {
            if(i == et) {
                continue;
            }
            memset(vis, 0x00, sizeof(vis));
            vis[i] = true;
            if(!dfs(0) && dist[i] < min_d) {
                room = i;
                min_d = dist[i];
            }
        }

        printf("Put guards in room %d.", room);
        if(T) {
            printf("\n\n");
        }
    }
}

