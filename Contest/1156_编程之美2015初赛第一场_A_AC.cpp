#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int maxn = 100005;
map<int, int> M[maxn];  //使用map，O(lg n)，降低时间复杂度。
vector<int> E[maxn];
int T, t = 0, col[maxn], fa[maxn], n, q;

void dfs(int x, int ff) {
    fa[x] = ff;
    for(int i = 0; i < E[x].size(); ++i) {
        if(E[x][i] != ff) { dfs(E[x][i],x); }
    }
}

int main(int argc, char** args) {
    int x, y; scanf("%d", &T);
    while(++t <= T) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            E[i].clear(); M[i].clear(); col[i]=0;
        }
        for(int i = 2; i <= n; ++i) {
            scanf("%d%d", &x, &y);
            E[x].push_back(y); E[y].push_back(x);
        }
        dfs(1, 0); int ans = 1;
        for(int i = 2; i <= n; ++i) {
            M[fa[i]][0]++;
        }

        scanf("%d", &q); int type;
        printf("Case #%d:\n", t);
        for(int i = 1; i <= q; ++i) {
            scanf("%d", &type);
            if(type == 1) { printf("%d\n",ans); }
            else {
                scanf("%d %d", &x, &y);
                if(x != 1) {
                    ans += (col[x]==col[fa[x]]);
                    M[fa[x]][col[x]]--;
                }
                ans += M[x][col[x]];
                col[x] = y;
                if(x != 1) {
                    ans -= (col[x]==col[fa[x]]);
                    M[fa[x]][col[x]]++;
                }
                ans -= M[x][col[x]];
            }
        }
    }

    return 0;
}

