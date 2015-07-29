#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 2e4+5, maxm = 1e5+5;

int dfn[maxn] = {0}; // depth-first n, 记录节点在DFS过程中被遍历到的次序号
int low[maxn] = {0}; // low, 记录节点u或u的子树通过非父子边追溯到最早的祖先节点（即DFS次序号最小）

vector<int> cutv;
vector< pair<int, int> > cute;
vector<int>edge[maxn];
bool vis[maxn] = {false};
bool flag[maxn] = {false};
int parent[maxn] = {0};

void tarjan(int u) {
    static int count = 0; // number.
    int child = 0, v;
    dfn[u] = low[u] = ++count;
    vis[u] = true;
    for(int i = 0; i < edge[u].size(); ++i) {
        v = edge[u][i];
        if(!vis[v]) {
            child++;
            parent[v] = u;
            tarjan(v);
            low[u] = min(low[u], low[v]);

            if(parent[u] == 0 && child >= 2) {
                flag[u] = true;
            }
            else if(parent[u] != 0 && low[v] >= dfn[u]) {
                flag[u] = true;
            }

            if(low[v] > dfn[u]) {
                if(v > u) { cute.push_back(make_pair(u, v)); }
                else { cute.push_back(make_pair(v, u)); }
            }
        }
        else if(v != parent[u]){
            low[u] = min(low[u], dfn[v]);
        }
    }
}

bool cmpe(const pair<int, int> & a, const pair<int, int> & b) {
    return (a.first==b.first)?(a.second<b.second):(a.first<b.first);
}

int main(int argc, char **argv) {
    int n, m, startp, x, y;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d", &x, &y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    tarjan(1);
    for(int i = 1; i <= n; ++i) {
        if(flag[i]) { cutv.push_back(i); }
    }
    if(cutv.size() > 0) {
        sort(cutv.begin(), cutv.end());
        for(int i = 0; i < cutv.size(); ++i) {
            printf("%d ", cutv[i]);
        }
    }
    else {
        printf("Null");
    }
    if(cute.size() > 0) {
        printf("\n");
        sort(cute.begin(), cute.end(), cmpe);
        for(int i = 0; i < cute.size(); ++i) {
            printf("%d %d\n", cute[i].first, cute[i].second);
        }
    }

    return 0;
}

