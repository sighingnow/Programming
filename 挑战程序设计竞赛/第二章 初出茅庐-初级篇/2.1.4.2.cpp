#include <cstdio>
using namespace std;

/**
 * POJ 2386
 *
 * DFS, 小岛着色。
 */

int n, m, ans = 0;
char mat[105][105];

void dfs(int i, int j) {
    mat[i][j] = '.';
    if(mat[i-1][j-1] == 'W') dfs(i-1, j-1);
    if(mat[i-1][j] == 'W') dfs(i-1, j);
    if(mat[i-1][j+1] == 'W') dfs(i-1, j+1);
    if(mat[i][j-1] == 'W') dfs(i, j-1);
    if(mat[i][j+1] == 'W') dfs(i, j+1);
    if(mat[i+1][j-1] == 'W') dfs(i+1, j-1);
    if(mat[i+1][j] == 'W') dfs(i+1, j);
    if(mat[i+1][j+1] == 'W') dfs(i+1, j+1);
}

int main(int argc, char **argv) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", mat[i]+1);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(mat[i][j] == 'W') {
                ans++; dfs(i, j);
            }
        }
    }
    printf("%d", ans);

    return 0;
}

