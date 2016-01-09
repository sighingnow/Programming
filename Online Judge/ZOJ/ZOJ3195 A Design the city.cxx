#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int max_n = 250000;

typedef struct Node {
    int y, z;
    int len;
} node;

struct Answer {
    int x, y, z;
    int resx, resy, resz;
} ans[max_n];

vector <node> tree[max_n], query[max_n];
int dist[max_n];
int ancestor[max_n];
bool vis[max_n];

int n, q;

void init() {
    memset(dist, 0, sizeof(dist));
    memset(ans, 0, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; ++i) {
        ancestor[i] = i;
        tree[i].clear();
        query[i].clear();
    }
}

int find(int x) {
    if(ancestor[x] != x) {
        ancestor[x] = find(ancestor[x]);
    }
    return ancestor[x];
}

void LCA(int u, int dis) {
    ancestor[u] = u;
    dist[u] = dis;
    vis[u] = true;

    int size = tree[u].size();
    for(int i = 0; i < size; ++i) {
        node current = tree[u][i];
        if(!vis[current.y]) {
            LCA(current.y, dis+current.len);
            ancestor[current.y] = u;
        }
    }

    size = query[u].size();
    for(int i = 0; i < size; ++i) {
        node current = query[u][i];
        if(!vis[current.y]) {
            continue;
        }

        int index = current.len;
        int parent = find(current.y);
        if((u == ans[index].x && current.y == ans[index].y) 
                || (u == ans[index].y && current.y == ans[index].x)) {
            ans[index].resx = dist[u] + dist[current.y] - 2 * dist[parent];
        }
        if((u == ans[index].y && current.y == ans[index].z) 
                || (u == ans[index].z && current.y == ans[index].y)) {
            ans[index].resy = dist[u] + dist[current.y] - 2 * dist[parent];
        }
        if((u == ans[index].x && current.y == ans[index].z) 
                || (u == ans[index].z && current.y == ans[index].x)) {
            ans[index].resz = dist[u] + dist[current.y] - 2 * dist[parent];
        }
    }
}

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);

    bool flag = false;
    int a, b, c;
    node current;
    while(scanf("%d", &n) != EOF) {
        if(flag) {
            printf("\n");
        }
        init();
        flag = true;

        for(int i = 1; i < n; ++i) {
            scanf("%d %d %d", &a, &b,&c);
            current.y = b, current.len = c;
            tree[a].push_back(current);
            current.y = a;
            tree[b].push_back(current);
        }

        scanf("%d", &q);
        for(int i = 1; i <= q; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            current.len = i;
            ans[i].x = a, ans[i].y = b, ans[i].z = c;

            current.y = a, query[b].push_back(current);
            current.y = a, query[c].push_back(current);
            current.y = b, query[a].push_back(current);
            current.y = b, query[c].push_back(current);
            current.y = c, query[a].push_back(current);
            current.y = c, query[b].push_back(current);
        }

        LCA(0, 0);

        for(int i = 1; i <= q; ++i) {
            printf("%d\n", (ans[i].resx + ans[i].resy + ans[i].resz) / 2);
        }
    }
    
    return 0;
}

