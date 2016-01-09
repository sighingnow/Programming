#include <cstdio>
using namespace std;

/**
 * DFS.
 *
 * Complexity: Time: O(2^n). n: 20
 *
 * 一个有用的优化：先数据分组，前十个一组，后一个一组，然后排序，再来找需要的和。
 * Time Complexity: O(2^{n/2}*log(2^{n/2}))
 */

int n, k, a[25];

bool dfs(int m, int sum) {
    if(m > n) {
        return sum == k;
    }
    if(dfs(m+1, sum)) return true;
    if(dfs(m+1, sum+a[m])) return true;
    return false;
}

int main(int argc, char **argv) {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
    }
    scanf("%d", &k);
    if(dfs(1, 0)) {
        printf("Yes");
    }
    else {
        printf("No");
    }

    return 0;
}

