#include <cstdio>
#include <queue>
using namespace std;

/**
 * Maze, BFS.
 * 
 * Complexity: Time: O(m*n), Space: O(m*n)
 */

const maxn = 1e2+5, maxm = 1e2+5;
int n, m, sx, sy, gx, gy, ans = 0;
char mat[maxn][maxm];

struct Point {
    int x;
    int y;
    int t;
};

int bfs() {
    queue<Point>Q;
    Q.push((Point){sx, sy, 0}); visited[sx][sy] = true;
    while(!Q.empty()) {
        Point p = Q.front(); Q.pop();
        if(p.x == gx && p.y == gy) {
            return p.t;
        }
        if(p.x-1>0 && mat[p.x-1][p.y] == '.') {
            Q.push((Point){p.x-1, p.y, p.t+1});
            mat[p.x-1][p.y] = '#';
        }
        if(p.y-1>0 && mat[p.x][p.y-1] == '.') {
            Q.push((Point){p.x, p.y-1, p.t+1});
            mat[p.x][p.y-1] = '#';
        }
        if(p.x+1<=n && mat[p.x+1][p.y] == '.') {
            Q.push((Point){p.x+1, p.y, p.t+1});
            mat[p.x+1][p.y] = '#';
        }
        if(p.y+1<=m && mat[p.x][p.y+1] == '.') {
            Q.push((Point){p.x, p.y+1, p.t+1});
            mat[p.x][p.y+1] = '#';
        }
    }
    return -1; // no valid path from S to G.
}

int main(int argc, char **argv) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", mat[i]+1);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(mat[i][j] == 'S') {
                sx = i; sy = j;
            }
            if(mat[i][j] == 'G') {
                gx = i; gy = j;
            }
        }
    }
    
    ans = bfs();
    printf("%d\n", ans);

    return 0;
}

