#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
/**
 * Author: buaahetao@gmail.com
 */

struct NODE {
    int value;
    int count;
} x[100005], y[100005];

int cmp(const NODE & a, const NODE & b) {
    if(a.value < b.value) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(int argc, char **argv) 
{
    int T, n, m;
    scanf("%d", &T);
    while(T--) {
        memset(x, 0x00, sizeof(x[0])*100005);
        memset(y, 0x00, sizeof(y[0])*100005);
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &x[i].value, &x[i].count);
        }
        for(int i = 0; i < m; ++i) {
            scanf("%d %d", &y[i].value, &y[i].count);
        }

        sort(x, x+n, cmp); sort(y, y+m, cmp);

        long long ans = 0, cnt = 0; 
        
        for(int i = 0, j = 0; i < n; ++i) {
            while(x[i].value > y[j].value && j < m) {
                cnt += y[j].count;
                ++j;
            }
            ans += cnt*x[i].count;
        }

        printf("%lld\n", ans);
    }

    return 0;
}

/* vim: set ts=4, sw = 4 */

