#include <cstdio>
#include <algorithm>
using namespace std;

/**
 * Sort.
 *
 * Complexity: Space: O(n), Time: O(n*lg(n))
 */

int n, len[1e3+5];

int solve() {
    sort(len, len+n);
    for(int i = n-1; i >= 2; --i) {
        if(len[i]<len[i-1]+len[i-2]) {
            return len[i]+len[i-1]+len[i-2];
        }
    }
    return 0;
}

int main(int argc, char **argv) {
    scanf("%d", &n);
    for(int i = 0; i <= n; ++i) {
        scanf("%d", n+i);
    }
    printf("%d", solve());

    return 0;
}

