#include <iostream>
#include <cstdio>
using namespace std;

// wikioi: 1312

void solve(int n) {
    int sum = 0, head = 0, tail = 0;
    for(int i = 0; i < n; ++i) {
        tail = i;
        sum += tail;
        if(sum >= n) {
            break;
        }
    }
    while(tail < n) {
        if(sum == n) {
            printf("%d %d\n", head, tail);
            sum -= head;
            head++;
            continue;
        }
        if(sum < n) {
            tail++;
            sum += tail;
        }
        else {
            sum -= head;
            head++;
        }
    }
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    solve(n);

    return 0;
}

