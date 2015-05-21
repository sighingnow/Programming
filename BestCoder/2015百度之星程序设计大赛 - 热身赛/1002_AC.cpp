#include <cstdio>
using namespace std;

int main(int argc, char **argv) {
    int n, m;
    while(scanf("%d %d", &n, &m) == 2) {
        printf("%d\n", (m%n-1)>=0?(m%n-1):(n-1));
    }
    
    return 0;
}

