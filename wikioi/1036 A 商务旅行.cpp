#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

//wikioi: 1036, LCA

const int size = 30005;
vector<int> node[size], que[size];
int n, m, root[size]; //并查集直接合并，不考虑秩
//DFN(u)为节点u搜索的次序编号(时间戳)，Low(u)为u或u的子树能够追溯到的最早的栈中节点的次序号。
int low[size], dfn[size], father[size];
int depth[size];
int dfsclock, cut; //dfsclock:dfs深度

int find(int x)//路径压缩查找
{
    if(root[x] != x)
        root[x] = find(root[x]);
    return x;
}

int unionSet(int x, int y)
{
    int a = find(x);
    int b = find(y);
    if(a != b)
    {
        root[y] = x;
        return 1;
    }
    return 0;
}

void init()
{
    cin >> n;
    for(int i = 0; i <= n; ++i)
        root[i] = i;
    int s, e;
    for(int i = 1; i < n; ++i)
    {
        scanf("%d %d", &s, &e);
        node[s].push_back(e);
        node[e].push_back(s);
    }
}

void tarjan(int u, int per, int deep)
{
    dfn[u] = low[u] = ++dfsclock;
    depth[u] = deep;
    for(int i = 0; i < (int)node[u].size(); ++i)
    {
        int v = node[u][i];
        if(!dfn[v])
        {
            tarjan(v, u, deep+1);
            father[v] = u;
            low[u] = min(low[v], low[u]);
            if(low[v] > dfn[u])
                cut++;
            else
                unionSet(u, v);
        }
        else if(v != per)
            low[u] = min(low[u], dfn[v]);
    }
}

int lca(int u, int v)
{
    while(u != v)
    {
        while(dfn[u] >= dfn[v] && u != v)
        {
            if(unionSet(u, father[u]))
                cut--;
            u = father[u];
        }
        while(dfn[u] <= dfn[v] && u != v)
        {
            if(unionSet(v, father[v]))
                cut--;
            v = father[v];
        }
    }
    return u;
}

int main(int argc, char **argv)
{
    init();
    tarjan(1, -1, 0);
    int v, u = 1;//题中的首都，起始点
    int ans = 0;
    cin >> m;
    while(m--)
    {
        scanf("%d", &v);
        int f = lca(u, v);
        ans += depth[u] + depth[v] - 2 * depth[f];
        u = v;
    }
    cout << ans;

    return 0;
}
