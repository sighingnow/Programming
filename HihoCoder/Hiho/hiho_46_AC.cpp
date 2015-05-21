#include <cstdio>
using namespace std;

int SG[20005];

int main(int argc, char **argv) {
    int n, k, ans = 0;
    // Initial SG.
    for(int i = 1; i < 20005; ++i) {
        switch (i%4) {
            case 0:
                SG[i] = i/4*4-1; break;
            case 1:
                SG[i] = i/4*4+1; break;
            case 2:
                SG[i] = i/4*4+2; break;
            case 3:
                SG[i] = i/4*4+4; break;
            default:
                break;
        }
    }
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &k);
        ans ^= SG[k];
    }

    if(ans == 0) {
        printf("Bob");
    }
    else {
        printf("Alice");
    }

    return 0;
}

