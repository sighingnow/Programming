#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int y1[3][10010], y2[10010], y3[10];
int x1, x2, x3;
int n, m, q;
double ans = 0;

void find

void prim() {
    int cnt = n + m + q;
    memset(flag, 0x00, sizeof(flag));
    flag[]
}

int main(int argc, char **argv) {
    while(~scanf("%d %d %d", &n, &m, &q)) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &x1, y1[i]);
        }
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &x2, y2[i]);
        }
        for(int i = 0; i < q; ++i) {
            scanf("%d %d", &x3, y3[i]);
        }
        prim();
        printf("%.6llf\n", ans);
    }

    return 0;
}

