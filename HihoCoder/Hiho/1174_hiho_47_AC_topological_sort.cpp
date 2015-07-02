#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 1e5+5, maxm = 5e5+5;

vector<int> edge[maxn];
queue<int> Q;
int n, m, in[maxn] = {0}, a, b, start;
bool flag[maxn] = {false};
int T = 0, t = 0;

int main(int argc, char **argv) {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m); start = 0;
        memset(flag, 0x00, sizeof(flag));
        memset(in, 0x00, sizeof(in));
        for(int i = 1; i <= n; ++i) { edge[i].clear(); }
        while(!Q.empty()) { Q.pop(); }
        for(int i = 1; i <= m; ++i) {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b); in[b] += 1;
        }
        for(int i = 1; i <= n; ++i) {
            if(!in[i]) { Q.push(i); flag[i] = true; }
        }
        if(Q.empty()) { printf("Wrong\n"); continue; }
        while(!Q.empty()) {
            a = Q.front(); Q.pop();
            if(edge[a].size()) {
                for(int i = 0; i < edge[a].size(); ++i) {
                    in[edge[a][i]] -= 1;
                    if(!in[edge[a][i]]) {
                        Q.push(edge[a][i]); flag[edge[a][i]] = true;
                    }
                }
            }
        }
        start = 0;
        for(int i = 1; i <= n; ++i) {
            if(!flag[i]) { start = -1; break; }
        }
        if(start == -1) { printf("Wrong\n"); }
        else { printf("Correct\n"); }
    }
}

