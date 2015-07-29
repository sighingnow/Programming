#include <cstdio>
using namespace std;

int main(int argc, char **argv) {
    int a = 1, b = 1, c = 1;
    int n;
    scanf("%d", &n);
    n--;
    while(n--) {
        c = (a + b) % 10007;
        a = b;
        b = c;
    }
    printf("%d", a);

    return 0;
}

