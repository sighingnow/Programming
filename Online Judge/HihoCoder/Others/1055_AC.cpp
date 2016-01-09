#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/**
 * Author: buaahetao@gmail.com, SCSE, BUAA
 */

const int max_n = 110;
int v[max_n] = {0};
int edge[max_n][max_n];
int f[max_n][max_n]; // f[t][j]以t为根的包括t在内的j个节点的得分
int n, m;

void dp(int pos, int father) {
    f[pos][1] = v[pos];
    for(int i = 1; i <= n; ++i) {
        if(i != father && edge[pos][i] == 1) {
            for(int mm = m; mm >= 2; --mm) {
                for(int mmc = 1; mmc < mm; mmc++) {
                    f[pos][mm] = max(f[pos][mm], f[pos][mm-mmc] + f[i][mmc]);
                }
            }
        }
    }
}

void post_order(int pos, int father) {
    for(int i = 1; i <= n; ++i) {
        if(i != father && edge[pos][i] == 1) {
            post_order(i, pos);
        }
    }
    dp(pos, father);
}

int main(int argc, char *argv[])
{
	scanf("%d %d", &n, &m);
    int x, y;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", v+i);
    }
    for(int i = 1; i < n; ++i) {
        scanf("%d %d", &x, &y);
        edge[x][y] = edge[y][x] = 1;
    }
    post_order(1, -1);
    printf("%d\n", f[1][m]);
	return 0;
}

/* vim: set ts=4, sw = 4 */


