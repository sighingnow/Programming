#include <cstdio>
using namespace std;

/**
 * Complexity: Space: O(n), Time: O(n^4)
 */

bool solve(int n, int m, int k[]) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            for(int s = 1; s <= n; ++s) {
                for(int t = 1; t <= n; ++t) {
                    if(k[i]+k[j]+k[s]+k[t] == m) {
                        return true;
                    }
                }
            }        
        }
    }

    return false;
}

int main(int argc, char **argv) {
    int n, m, k[55];
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &k[i]);
    }
    if(solve(n, m, k)) {
        printf("Yes");
    }
    else {
        printf("No");
    }

    return 0;
}

