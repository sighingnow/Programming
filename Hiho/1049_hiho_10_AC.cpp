#include <cstdio>
#include <cstring>
using namespace std;

int top = 0;

void solve(char DLR[], char LDR[], int l, int r) {
    int mid = -1;
    for(int i = l; i <= r; ++i) {
        if(DLR[top] == LDR[i]) {
            mid = i;
            break;
        }
    }
    top++;
    if(l <= mid-1) {
        solve(DLR, LDR, l, mid-1);
    }
    if(mid+1 <= r) {
        solve(DLR, LDR, mid+1, r);
    }
    printf("%c", LDR[mid]);
}

int main(int argc, char **argv) {
    char DLR[27], LDR[27];
    scanf("%s %s", DLR, LDR);
    solve(DLR, LDR, 0, strlen(DLR)-1);
    return 0;
}

