#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int max_n = 1001;
bool edge[max_n][max_n];
bool vis[max_n];
int dfn[max_n], low[max_n];
int subnet[max_n];

int node; //记录节点数
int tmpdfn; //用于dfs中记录当前深度优先数
int son; //记录节点的连通分量个数

void dfs(int u) {
    for(int v = 1; v <= node; ++v) {
        if(edge[u][v]) {
            if(!vis[v]) {
                vis[v] = true;
                dfn[v] = low[v] = ++tmpdfn;
                dfs(v);
                low[u] = min(low[u], low[v]);
                
                if(low[v] >= dfn[u]) {
                    if(u != 1) {
                        subnet[u]++;
                    }
                    else { //根节点没有入的边，单独处理
                        son++;
                    }
                }
            }
            else {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
}

inline int max(int a, int b, int c) {
    int tmp = -0x3fffffff;
    tmp = a > b ? a : b;
    tmp = tmp > c ? tmp : c;
    return tmp;
}

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    
    int T = 0, u, v;
    while(~scanf("%d", &u) && u) { // EOF = -1, ~(-1) = 0;
        memset(edge, 0, sizeof(edge));
        node = 0;

        scanf("%d", &v);
        node = max(node, u, v);
        edge[u][v] = edge[v][u] = true;
        while(scanf("%d", &u) && u) {
            scanf("%d", &v);
            node = max(node, u, v);
            edge[u][v] = edge[v][u] = true;
        }

        dfn[1] = low[1] = tmpdfn = 1;
        son = 0;
        memset(vis, 0, sizeof(vis));
        memset(subnet, 0, sizeof(subnet));
        
        vis[1] = true;
        dfs(1);

        if(son > 1) { // 处理根节点
            subnet[1] = son-1;
        }

        int find = 0;
        if(T > 0) {
            printf("\n");
        }
        printf("Network #%d\n", ++T);
    
        for(int i = 1; i <= node; ++i) {
            if(subnet[i]) {
                find = 1;
                printf("  SPF node %d leaves %d subnets\n", i, subnet[i] + 1);
            }
        }
        if(find == 0) {
            printf("  No SPF nodes\n");
        }
    }

    return 0;
}

