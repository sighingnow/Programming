#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    int n;
    cin >> n;
    if(n % 400 == 0 || (n % 100 != 0 && n % 4 == 0)) {
        printf("yes");
    }
    else {
        printf("no");
    }
    return 0;
}

