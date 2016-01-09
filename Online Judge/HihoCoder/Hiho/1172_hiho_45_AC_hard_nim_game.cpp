#include <cstdio>
using namespace std;

int main(int argc, char **argv) {
    int n, k, ans = 0; char c;
    scanf("%d", &n); getchar();
    for(int i = 1; i <= n; ++i) {
        scanf("%c", &c);
        if(c == 'H') {
            ans ^= i;
        }
    }

    if(ans == 0) {
        printf("Bob");
    }
    else {
        printf("Alice");
    }

    return 0;
}

