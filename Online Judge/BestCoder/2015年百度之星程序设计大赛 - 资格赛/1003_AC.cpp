#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

const int maxm = 1005;
unsigned int ip[maxm] = {0};
map<unsigned int, bool> ADDR;

int main(int argc, char **argv) {
    int T, t = 0, m, n;
    unsigned int a, b, c, d;
    scanf("%d", &T);
    while(++t <= T) {
        printf("Case #%d:\n", t);
        scanf("%d %d", &m, &n);
        for(int i = 1; i <= m; ++i) {
            scanf("%u.%u.%u.%u", &a, &b, &c, &d);
            ip[i] = a<<24|b<<16|c<<8|d;
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%u.%u.%u.%u", &a, &b, &c, &d);
            ADDR.clear();
            for(int j = 1; j <= m; ++j) {
                ADDR[(a<<24|b<<16|c<<8|d)&ip[j]] = true;
            }
            printf("%d\n", ADDR.size());
        }
    }
    return 0;
}

