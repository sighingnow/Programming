#include <cstdio>
using namespace std;

/**
 * SGU 105. Div 3
 * 数字技巧题
 */

int main(int argc, char **argv) {
    int n = 0;
    scanf("%d", &n);
    if(n % 3 == 0) {
        printf("%d", n/3*2);
    }
    else {
        printf("%d", n/3*2+n%3-1);
    }

    return 0;
}

