#include <cstdio>
using namespace std;

/**
 * SGU 107. 987654321 problem 
 * n < 9: ans = 0.
 * n = 9: ans = 8
 * n > 9: ans = 8*9*(10^(n-10))
 */

int main(int argc, char **argv) {
    int n = 0;
    scanf("%d", &n);
    if(n < 9) {
        printf("0");
    }
    else if(n == 9) {
        printf("8");
    }
    else {
        printf("72");
        for(int i = 0; i < n-10; ++i) {
            printf("0");
        }
    }

    return 0;
}

