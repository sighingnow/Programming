#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

const int maxn = 1e3+5, maxm = 5e3+5;

list<int> edge[maxn];
int k, n, m, a, b, odd = 0, degree[maxn] = {0};
int path[2*maxm], top = 0;

void dfs(int s) {
    while(!edge[s].empty()) {
        int t = edge[s].front();
        edge[s].pop_front();
        edge[t].erase(find(edge[t].begin(), edge[t].end(), s));
        dfs(t);
    }
    path[top++] = s;
}

int main(int argc, char **argv) {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b); edge[b].push_back(a);
        degree[a]++; degree[b]++;
    }
    int start = 1;
    for(int i = 1; i <= n; ++i) {
        if(degree[i] % 2) { start = i; k++; }
    }
    if(!(k == 0 || k == 2)) { return 0; } // no euler path.
    dfs(start);
    for(int i = 0; i < top; ++i) {
        printf("%d ", path[i]);
    }
    return 0;
}

