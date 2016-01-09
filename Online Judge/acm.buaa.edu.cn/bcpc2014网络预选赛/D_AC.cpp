#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m;
int p[11] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

int main(int argc, char **argv) {
    while(~scanf("%d %d", &n, &m)) {
        if(n > m) {
            swap(n, m);
        }
        printf("%d\n", p[n] * (p[m]-1));
    }

    return 0;
}

