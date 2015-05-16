#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

struct Edge {
    int x, y;
    int len;
} e[1000100];

int root[1005], rank[1005];
int n, cnt = 0;

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
    int len;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &len);
            if(i > j) {
                e[cnt].x = i;
                e[cnt].y = j;
                e[cnt++].len = len;
            }
        }
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

