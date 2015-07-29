#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char **argv) {
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        if(m > n / 2) {
            printf("Wonderful Contest!\n");
        }
        else {
            printf("_(:3_|Z)_\n");
        }
    }

    return 0;
}

