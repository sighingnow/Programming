#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

struct Edge {
    int x, y;
    int len;
} e[1000100];

int root[100005], rank[100005];
int n, m, cnt = 0;

int find(int x) {
    if(x != root[x]) {
        root[x] = find(root[x]);
    }
    return root[x];
}

void unionset(int x, int y) {
    if((x = find(x)) == (y = find(y))) {
        return;
    }
    if(rank[x] > rank[y]) {
        root[y] = x;
    }
    else {
        root[x] = y;
        if(rank[x] == rank[y]) {
            rank[y] += 1;
        }
    }
}

bool cmp(const Edge a, const Edge b) {
    return a.len < b.len;
}

int main(int argc, char **argv) {
    int x, y, len;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d %d", &x, &y, &len);
        e[cnt].x = x;
        e[cnt].y = y;
        e[cnt++].len = len;
    }
    sort(e, e+cnt, cmp);
    for(int i = 1; i <= n; ++i) {
        root[i] = i;
        rank[i] = 0;
    }
    int ans = 0, counter = 0;
    for(int i = 0; i < cnt; ++i) {
        int a = find(e[i].x);
        int b = find(e[i].y);
        if(a != b) {
            ans += e[i].len;
            unionset(a, b);
            counter++;
        }
        if(counter == n-1) {
            break;
        }
    }
    printf("%d", ans);

    return 0;
}

