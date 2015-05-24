/* 1330 Nearest Common Ancestors 
 * LCA 在线算法 DFS + ST(RMQ)
 * 鉴于此题的实际情况，也可以采用O(n)的朴素算法
 ************/

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <list>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 20010;

/* 朴素算法 Accept
void init(int &n, int father [], int &s, int &t) {
    int u, v;
    scanf("%d", &n);
    memset(father, 0xff, sizeof(father[0]) * MAXN);
    for(int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        father[v] = u;
    }
    scanf("%d %d", &s, &t);
}

int compute(int father [], int s, int t, bool flag []) {
    memset(flag, 0, sizeof(flag[0]) * MAXN);
    flag[s] = true;
    while(father[s] != -1) {
        s = father[s];
        flag[s] = true;
    }
    if(flag[t]) {
        return t;
    }
    while(father[t] != -1) {
        t = father[t];
        if(flag[t]) {
            return t;
        }
    }
}

int main(int argc, char **argv) {
    // 朴素算法
    int T, n, s, t;
    int father[MAXN];
    bool flag[MAXN];
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        init(n, father, s, t);
        printf("%d\n", compute(father, s, t, flag));
    }
    return 0;
}
*/

// RMQ的ST算法 Accept
void init(int & n, list <int> node[], int &root, int parent[]) {
    scanf("%d", &n);
    for(int i = 0; i < MAXN; ++i) {
        node[i].clear();
    }
    memset(parent, 0xff, sizeof(parent[0]) * MAXN);
    int s, t;
    for(int i = 1; i < n; ++i) {
        scanf("%d %d", &s, &t);
        node[s].push_back(t);
        parent[t] = s;
    }
    // 获取根节点
    for(int i = 1; i <= n; ++i) {
        if(parent[i] == -1) {
            root = i;
            return;
        }
    }
}

void dp_rmq(int n, int depth[], int rmq[], int min_val_index[][16], int top) {
    // memset(min_val_index, 0, sizeof(min_val_index[0][0]) * MAXN * 16);
    for(int i = 1; i < top; ++i) {
        min_val_index[i][0] = i; // 索引
    }
    for(int j = 1; (1<<j) < top; ++j) {
        for(int i = 1; i+(1<<j)-1 < top; ++i) {
            if(depth[rmq[min_val_index[i][j-1]]] <= depth[rmq[min_val_index[i+(1<<(j-1))][j-1]]]) {
                min_val_index[i][j] = min_val_index[i][j-1];
            }
            else {
                min_val_index[i][j] = min_val_index[i+(1<<(j-1))][j-1];
            }
        }
    }
}

int query_lca(int u, int v, int first_pos[], int min_val_index[][16], int rmq[], int depth[]) {
    int s = first_pos[u], t = first_pos[v];
    if(s > t) {
        swap(s, t);
    }
    int k = log(t-s+1.0)/log(2.0);
    if(depth[rmq[min_val_index[s][k]]] <= depth[rmq[min_val_index[t+1-(1<<k)][k]]]) {
        return rmq[min_val_index[s][k]];
    }
    else {
        return rmq[min_val_index[t+1-(1<<k)][k]];
    }
}

void dfs(int current, int n, list <int> node[], int depth[], int rmq[], int first_pos[], bool flag[], int & top, int parent[]) {
    
    if(!node[current].empty()) {
        for(list<int>::iterator iter = node[current].begin(); iter != node[current].end(); ++iter) {
            rmq[top++] = *iter;
            if(!flag[*iter]) {
                flag[*iter] = true;
                first_pos[*iter] = top-1;
            }
            depth[*iter] = depth[current] + 1;
            dfs(*iter, n, node, depth, rmq, first_pos, flag, top, parent);
        }
        rmq[top++] = parent[current];
    } 
    else { 
        rmq[top++] = parent[current];
    }
}

int main(int argc, char **argv) {
    
    int T, n, u, v, root, top;
    list <int> node[MAXN]; // 记录每个节点的子节点
    int rmq[2*MAXN];
    int depth[MAXN];
    int parent[MAXN];
    int first_pos[MAXN];
    int min_val_index[MAXN][16];
    bool flag[MAXN];
    scanf("%d", &T);
    while(T--) {
        init(n, node, root, parent);
        
        top = 1;
        depth[root] = 0;
        rmq[top++] = root;
        memset(flag, 0, sizeof(flag[0]) * MAXN);
        flag[root] = true;
        first_pos[root] = top-1;
        
        dfs(root, n, node, depth, rmq, first_pos, flag, top, parent);
        
        dp_rmq(n, depth, rmq, min_val_index, top-1);
        scanf("%d %d", &u, &v);
        printf("%d\n", query_lca(u, v, first_pos, min_val_index, rmq, depth));
    }
}

/* Sample Input
2
16
1 14
8 5
10 16
5 9
4 6
8 4
4 10
1 13
6 15
10 11
6 7
10 2
16 3
8 1
16 12
16 7
5
2 3
3 4
3 1
1 5
3 5

Sample Output
4
3
*/
