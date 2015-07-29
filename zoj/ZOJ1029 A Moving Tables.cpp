#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    int T, n, u, v;
    int room[201];
    scanf("%d", &T);
    while(T--) {
        memset(room, 0x00, sizeof(room));
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d %d", &u, &v);
            if(u > v) {
                swap(u, v);
            }
            u = (u+1) / 2;
            v = (v+1) / 2;
            for(int j = u; j <= v; ++j) {
                room[j]++;
            }
        }
        for(int i = 1; i <= 200; ++i) {
            if(room[0] < room[i]) {
                room[0] = room[i];
            }
        }
        printf("%d\n", room[0]*10);
    }

    return 0;
}
