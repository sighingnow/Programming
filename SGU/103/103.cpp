#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

/**
 * SGU 103. Traffic Lights
 * Dijstra, 边权动态变化，但仍符合Dijstra算法的greedy的思想。
 * 要点：分析等待时间。
 */

const int maxn = 305, maxm = 14005;
const int INF = 0x3fffffff;
int mat[maxn][maxn];
char ch;
int n, m, s, t, ans, x, y, v, top = 0;
int c[maxn], r[maxn], t1[maxn], t2[maxn];
int dist[maxn], vis[maxn], previous[maxn], path[maxn];

inline int getcolor(int i, int k, int & tt) {
    if(k < r[i]) {
        tt = r[i] - k; return c[i];
    }
    int x = (k-r[i])%(t1[i]+t2[i]);
    if(x < t2[i]) {
        tt = t2[i]-x; return 1-c[i];
    }
    else {
        tt = t2[i]+t1[i]-x; return c[i];
    }
}

inline int getwait(int time, int a, int b) {
    int wait = 0, tta, ttb;
    for(int i = 1; i <= 3; ++i) {
        if(getcolor(a,time,tta) == getcolor(b,time,ttb)) {
            return wait;
        }
        wait+=min(tta,ttb); time+=min(tta,ttb);
    }
    return INF;
}

void dijstra() {
    for(int i = 1; i <= n; ++i) {  // initial.
        dist[i] = getwait(0,s,i)+mat[s][i]; 
        previous[i] = s;
    }
    dist[s] = 0; vis[s] = 1;
    for(int i = 2; i <= n; ++i) {
        int u = s, bound = INF;
        for(int j = 1; j <= n; ++j) {  // find
            if(!vis[j] && bound>dist[j]) {
                u = j; bound = dist[j];
            }
        }
        vis[u] ^= 1;
        for(int j = 1; j <= n; ++j) {  // update
            if(!vis[j] && mat[u][j]<INF) {
                int tt=getwait(dist[u],u,j);
                if(dist[j]>dist[u]+tt+mat[u][j]) {
                    dist[j] = dist[u]+tt+mat[u][j]; 
                    previous[j] = u;
                }
            }
        }
    }
    if(dist[t] == INF) {
        ans = 0; return;
    }
    // roll back, get path.
    ans = dist[t]; int end = t;
    while(previous[end] != end) {
        path[++top] = end;
        end = previous[end];
    }
    path[++top] = end;
}

int main(int argc, char **argv) {
    scanf("%d%d%d%d", &s, &t, &n, &m);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            mat[i][j] = INF;
        }
        mat[i][i] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        scanf("\n%c%d", &ch, r+i);
        if(ch == 'B') { c[i] = 0; scanf("%d%d",t1+i,t2+i); }
        if(ch == 'P') { c[i] = 1; scanf("%d%d",t2+i,t1+i); }
        mat[i][i] = 0;
    }
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &x, &y, &v);
        mat[x][y] = mat[y][x] = v;
    }
    dijstra();
    printf("%d\n", ans);
    if(ans == 0) { return 0; }
    for(int i = top; i >= 1; --i) {
        printf("%d ", path[i]);
    }
    return 0;
}

