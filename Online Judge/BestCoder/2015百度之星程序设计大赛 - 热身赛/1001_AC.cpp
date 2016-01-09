#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 105, MAX_M = 10005;

int n, m, x, y, mat[MAX_N][MAX_N], in[MAX_N];

bool bfs() {
    queue<int>Q;
    for(int i = 1; i <= n; ++i) {
        if(in[i] == 0) {
            Q.push(i);
        }
    }
    while(!Q.empty()) {
        int k = Q.front(); Q.pop();
        for(int i = 1; i <= n; ++i) {
            if(mat[k][i] > 0) {
                in[i] -= 1;
                if(in[i] == 0) {
                    Q.push(i);
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(in[i] > 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    while(scanf("%d%d",&n,&m) == 2) {
        memset(mat, 0x00, sizeof(mat));
        memset(in, 0x00, sizeof(in));
        for(int i = 1; i <= m; ++i) {
            scanf("%d %d", &x, &y);
            if(mat[y][x] == 0) {
                mat[y][x] = 1; in[x] += 1;
            }
        }
        if(bfs()) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}

