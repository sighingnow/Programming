#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
/**
 * 边的双连通分量: 对于一个无向图的子图，当删除其中任意一条边后，不改变图内
 * 点的连通性，这样的子图叫做边的双连通子图。而当子图的边数达到最大时，叫做
 * 边的双连通分量。
 */

const int maxn = 2e4+5, maxm = 1e5+5;

int dfn[maxn], low[maxn], stk[maxn], top = 0, block = 0, belong[maxn], s[maxn];
vector<int> edge[maxn];

void tarjan(int u, int pre) {
    static int counter = 0;
    dfn[u] = low[u] = ++counter;
    stk[++top] = u;
    for(size_t i = 0; i < edge[u].size(); ++i) {
        int v = edge[u][i];
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(v != pre) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) { // bridge.
        block++;
        int d, minn = 0x3fffffff, len = 0;
        while(true) {
            d = stk[top--];
            s[++len] = d;
            minn = min(minn, d);
            if(d == u) break;
        }
        for(int i = 1; i <= len; ++i) {
            belong[s[i]] = minn;
        }
    }
}

int main(int argc, char **argv)
{
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    while(m--)
    {
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    tarjan(1, -1);
    printf("%d\n", block);
    for(int i = 1; i <= n; ++i) {
        printf("%d ", belong[i]);
    }
    return 0;
}

