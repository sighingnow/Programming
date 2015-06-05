#include <cstdio>
#include <algorithm>
using namespace std;

/**
 * POJ 1852
 *
 * 分析：两只蚂蚁相遇可以等价地视为仅仅是经过，不用考虑反向的问题。
 *
 * Comlexity: Time: O(n), Space: O(1).
 */

int main(int argc, char **argv) {
    int T, l, n, k, a = 0, b = 0;
    scanf("%d", &T); // cases
    while(T--) {
        scanf("%d%d", &l, &n);
        a = 0; b = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &k);
            a = max(a, k<=l/2?k:l-k);
            b = max(b, k); b = max(b, l-k);
        }
        printf("%d %d\n", a, b);
    }

    return 0;
}

