#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

// 树的直径(树上的最长路径)
// DFS/BFS

const int maxn = 1000005;

int n, x, y, v, ans = 0, vertex;
vector<pair<int, int> > next[maxn];
bool flag[maxn] = {false};

void dfs(int k, int sum) {
    for(int i = 0; i < next[k].size(); ++i) {
        if(!flag[next[k][i].first]) {
            if(sum+next[k][i].second > ans) {
                ans = sum+next[k][i].second;
                vertex = next[k][i].first;
            }
            flag[next[k][i].first] = true;
            dfs(next[k][i].first, sum+next[k][i].second);
        }
    }
}

int main(int argc, char **argv) {
    int x, y, v;
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        scanf("%d%d%d", &x, &y, &v);
        next[x].push_back(pair<int,int>(y, v));
        next[y].push_back(pair<int,int>(x, v));
    }
    ans = 0; memset(flag, 0x00, sizeof(flag)); flag[1] = true;
    dfs(1, 0);
    ans = 0; memset(flag, 0x00, sizeof(flag)); flag[vertex] = true;
    dfs(vertex, 0);
    printf("%d", (1+ans)*ans/2+ans*10);

    return 0;
}

