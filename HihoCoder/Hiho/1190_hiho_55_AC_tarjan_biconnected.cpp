#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/**
 * 对于一个无向图的子图，当删除其中任意一个点后，不改变图内点的连通性，
 * 这样的子图叫做点的双连通子图。而当子图的边数达到最大时，叫做点的
 * 双连通分量。
 */

const int N = 2e4+5, M = 2e5+5;

int dfn[N], low[N], id[M>>1], idn = 0, stk[M>>1], stn = 0;
int _head[N], _next[M], _to[M], num = 0;

void conn(int u, int v)
{
    _next[num] = _head[u];
    _to[num] = v;
    _head[u] = num++;
}

void group(int _top)
{
    int r = M;
    for(int i = _top; i < stn; ++i) {
        r = min(r, stk[i]);
    }
    for(int i = _top; i < stn; ++i) {
        id[stk[i]] = r;
    }
    stn = _top; // pop
    idn++;
}

void tarjan(int u, int parent = -1)
{
    static int cnt = 0;
    dfn[u] = low[u] = cnt++;
    for(int i = _head[u]; ~i; i = _next[i]) {
        int v = _to[i];
        if(dfn[v] < 0) {
            int _top = stn;
            stk[stn++] = i >> 1; // push
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]) {
                group(_top);
            }
        }
        else if(dfn[v] < dfn[u] && v != parent) {
            stk[stn++] = i >> 1; // push
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main()
{
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    memset(_head, 0xff, sizeof(_head));
    memset(dfn, 0xff, sizeof(dfn));
    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        u--; v--;
        conn(u, v); conn(v, u);
    }
    tarjan(3);
    printf("%d\n", idn);
    for(int i = 0; i < m; ++i) {
        printf("%d ", id[i]+1);
    }

    return 0;
}



