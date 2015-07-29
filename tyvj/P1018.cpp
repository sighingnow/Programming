#include <cstdio>
using namespace std;

int main(int argc, char **argv) {
    long long ans = 1;
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        ans *= i;
        if(ans % 10 == 0) {
            ans /= 10;
        }
    }
    int out[20] = {0}, top = 0;
    for(int i = 1; i <= k; ++i) {
        out[top++] = ans % 10;
        ans /= 10;
        if(ans == 0) {
            break;
        }
    }
    while(top--) {
        printf("%d", out[top]);
    }

    return 0;
}
