#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/**
 * 状态压缩DP
 **/
int h, w;
long long int ans[13][2100];
int tran[20000][2], nTran = 0;

/**
 * void dfs(int n, int from, int to) 表示当前从左往右有n块砖，from表示前n块砖在这一层的编码，to表示下一层。
 **/
void dfs(int n, int from, int to) {
    if(n > w) {
        return;
    }
    if(n == w) {
        tran[nTran][0] = from;
        tran[nTran++][1] = to;
        return;
    }
    dfs(n+2, (from<<2)+3, (to<<2)+3);
    dfs(n+1, (from<<1)+1, (to<<1));
    dfs(n+1, (from<<1), (to<<1)+1);
}

/**
 * ans[i][j]中存第i行摆放状态为j时的方法数，边界是要全放满的，ans[0][(1<<w)-1]=1，最后要求的是ans[h][(1<<w)-1];
 **/
void dp() {
    memset(ans, 0x00, sizeof(ans));
    ans[0][(1<<w)-1] = 1;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < nTran; ++j) {
            ans[i+1][tran[j][1]] += ans[i][tran[j][0]];
        }
    }
}

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    while(scanf("%d %d", &h, &w)) {
        if(h == 0 && w == 0) {
            break;
        }
        if(h < w) {
            swap(h, w);
        }
        nTran = 0;
        dfs(0, 0, 0);
        dp();
        printf("%I64d\n", ans[h][(1<<w)-1]);
    }

    return 0;
}
