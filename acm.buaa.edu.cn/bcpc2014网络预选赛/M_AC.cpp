#include <cstdio>
using namespace std;

int main(int argc, char **argv) {
    int n, k, h, h_next;
    long long ans = 0;
    while(~scanf("%d %d %d", &n, &k, &h)) {
        ans = 0;
        for(int i = 1; i < n; ++i) {
            scanf("%d", &h_next);
            if(h != h_next) {
                ans += k;
            }
            h = h_next;
        }
        printf("%lld\n", ans);
    }

    return 0;
}

