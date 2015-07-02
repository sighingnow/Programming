#include <cstdio>
using namespace std;

const int maxk = 4;

int n, k = 4, MOD;
long long mat[1<<maxk][1<<maxk];

void dfs(int column, int now, int pre) {
    if(column > k) { return; }
    if(column == k) { mat[pre][now]++; return; }
    dfs(column+1, (now<<1), (pre<<1)|1);
    dfs(column+1, (now<<1)|1, (pre<<1));
    dfs(column+2, (now<<2)|3, (pre<<2)|3);
}

void mat_multi(long long a[][1<<maxk], long long b[][1<<maxk]) {
    long long c[1<<maxk][1<<maxk] = {{0}};
    for(int i = 0; i < 1<<k; ++i) {
        for(int j = 0; j < 1<<k; ++j) {
            for(int kk = 0; kk < 1<<k; ++kk) {
                c[i][j] += a[i][kk]*b[kk][j];
            }
        }
    }
    for(int i = 0; i < 1<<k; ++i) {
        for(int j = 0; j < 1<<k; ++j) {
            a[i][j] = c[i][j]%MOD;
        }
    }
}

int mat_pow_mod() {
    long long result[1<<maxk][1<<maxk] = {{0}}, base[1<<maxk][1<<maxk] = {{0}};
    for(int i = 0; i < 1<<k; ++i) {
        result[i][i] = 1;
    }
    for(int i = 0; i < 1<<k; ++i) {
        for(int j = 0; j < 1<<k; ++j) {
            base[i][j] = mat[i][j];
        }
    }
    while(n) {
        if(n & 1) {
            mat_multi(result, base);
        }
        mat_multi(base, base);
        n >>= 1;
    }
    return result[(1<<k)-1][(1<<k)-1]%MOD;
}

int main(int argc, char **argv) {
    dfs(0, 0, 0);
    while(scanf("%d%d", &n, &MOD) != EOF && n+MOD) {
        printf("%d\n", mat_pow_mod());
    }

    return 0;
}

