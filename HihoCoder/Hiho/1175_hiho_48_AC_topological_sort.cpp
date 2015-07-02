#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 1e5+5, maxm = 5e5+5;
const int MOD = 142857;

vector<int> edge[maxn];
queue<int> Q;
int n, m, k, in[maxn] = {0}, virus[maxn] = {0}, a, b, ans = 0;

int main(int argc, char **argv) {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= k; ++i) {
        scanf("%d", &a); virus[a] = 1;
    }
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b); in[b] += 1;
    }
    for(int i = 1; i <= n; ++i) {
        if(!in[i]) { Q.push(i); ans = (ans+virus[i])%MOD; }
    }
    while(!Q.empty()) {
        a = Q.front(); Q.pop();
        if(edge[a].size()) {
            for(int i = 0; i < edge[a].size(); ++i) {
                virus[edge[a][i]] = (virus[edge[a][i]]+virus[a])%MOD;
                in[edge[a][i]] -= 1;
                if(!in[edge[a][i]]) {
                    Q.push(edge[a][i]); ans = (ans+virus[edge[a][i]])%MOD;
                }
            }
        }
    }
    printf("%d", ans);

    return 0;
}

