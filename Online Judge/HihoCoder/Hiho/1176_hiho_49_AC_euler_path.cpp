#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1e4+4, maxm = 1e4+4;

vector<int> edge[maxn];
bool reach[maxn] = {false}, isfull = true;
int n, m, a, b, odd = 0, degree[maxn] = {0};

void dfs(int s) {
    reach[s] = true;
    if(edge[s].size()) {
        for(int i = 0; i < edge[s].size(); ++i) {
            if(!reach[edge[s][i]]) { dfs(edge[s][i]); }
        }  
    }
}

int main(int argc, char **argv) {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b); edge[b].push_back(a);
        degree[a] += 1; degree[b] += 1;
    }
    for(int i = 1; i <= n; ++i) {
        if(degree[i] % 2 == 1) { odd += 1; }
    }
    if(odd != 0 && odd != 2) { printf("Part"); }
    else {
        dfs(1);
        for(int i = 1; i <= n; ++i) {
            if(!reach[i]) { isfull = false; break; }
        }
        if(isfull) { printf("Full"); }
        else { printf("Part"); }
    }

    return 0;
}

