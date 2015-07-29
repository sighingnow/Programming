#include <cstdio>
#include <cstring>
using namespace std;

int buf[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
bool cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int ans = 0;
int l, r, x;

void dfs() {
    
}

void solve() {
    if(x % 10 == 0) {
        ans = 0;
        return;
    }
    long long tmp = x;
    for(int i = 1; i < 9; ++i) {
        while(tmp % buf[i] == 0) {
            tmp /= buf[i];
            cnt[buf[i]]++;
        }
    }
    if(tmp > 9) {
        ans = 0;
        return;
    }
    dfs();
}

int main(int argc, char **argv) {
    while(~scanf("%lld %lld %lld", &l, &r, &x)) {
        memset(cnt, 0x00, sizeof(cnt));
        ans = 0;
        solve();
        printf("%d\n", ans);
    }

    return 0;
}

