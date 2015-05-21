#include <cstdio>
using namespace std;

/**
 * NIM Game.
 */

int main(int argc, char **argv) {
    int n, k, result = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        result ^= k;
    }
    if(result != 0) {
        printf("Alice");
    }
    else {
        printf("Bob");
    }

    return 0;
}

