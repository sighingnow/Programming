#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

void solve(char a[]) {
    int p = strlen(a), q = 8, i = 0;
    for(i = 0; i + q < p; ++i) {
        if((a[i]=='m' || a[i]=='M') && 
            (a[i+1]=='a' || a[i+1]=='A') && 
            (a[i+2]=='r' || a[i+2]=='R') && 
            (a[i+3]=='s' || a[i+3]=='S') && 
            (a[i+4]=='h' || a[i+4]=='H') && 
            (a[i+5]=='t' || a[i+5]=='T') && 
            (a[i+6]=='o' || a[i+6]=='O') && 
            (a[i+7]=='m' || a[i+7]=='M') && 
            (a[i+8]=='p' || a[i+8]=='P')) { 
            printf("fjxmlhx");
            i += 8;
        }
        else {
            printf("%c", a[i]);
        }
    }
    for(; i < p; ++i) {
        printf("%c", a[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    char a[1000];
    while(gets(a)) {
        solve(a);
    }
    return 0;
}

