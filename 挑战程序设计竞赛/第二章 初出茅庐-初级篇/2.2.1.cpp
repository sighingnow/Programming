#include <cstdio>
#include <iostream>
using namespace std;

/**
 * Greedy.
 */
int A, B[7] = {0, 1, 5, 10, 50, 100, 500}, C[7] = {0};

int main(int argc, char **argv) {
    int t, ans = 0;
    scanf("%d", &A);
    for(int i = 1; i <= 6; ++i) {
        scanf("%d", C+i);
    }
    for(int i = 6; i >= 1 && A > 0; --i) {
        t = min(C[i], A/B[i]);
        ans += t;
        A -= (t*B[i]);
    }
    printf("%d", ans);

    return 0;
}

