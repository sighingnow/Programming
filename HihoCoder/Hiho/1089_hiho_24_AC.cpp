#include <cstdio>
using namespace std;

int dist[105][105];

int main(int argc, char **argv) {
    
    int n, m, x, y, len;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            dist[i][j] = 0x3fffffff;
        }
        dist[i][i] = 0;
    }
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &len);
        dist[x][y] = dist[y][x] = len < dist[x][y] ? len : dist[x][y];
    }
    for(int k = 1; k <= n; ++k) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

