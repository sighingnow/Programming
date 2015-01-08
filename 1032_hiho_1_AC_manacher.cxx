#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

// manacher.

int len, f[2000010];
char str[2000010];

int solve() {
    int id = 0, mx = 0, ans = 0; // mx = id + f[id]
    memset(f, 0x00, sizeof(f));
    for(int i = 1; i <= 2 * len; ++i) {
        if(mx > i) {
            f[i] = min(f[2 * id - i], f[id] + id - i);
        }
        else {
            f[i] = 1;
        }
        while(i-f[i] >= 0 && i+f[i] <= 2*len && str[i+f[i]] == str[i-f[i]]) {
            f[i]++;
        }
        if(f[i] + i > mx) {
            mx = f[i] + i;
            id = i;
        }
        if(str[i] == '#') {
            ans = max(ans, ((f[i]-1)/2) * 2);
        }
        else {
            ans = max(ans, ((f[i]-1)/2) * 2 + 1);
        }
    }

    return ans;
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", str);
        len = strlen(str);
        for(int i =len-1; i >= 0; --i) {
            str[2*i+1] = str[i];
            str[2*i+2] = '#';
        }
        str[0] = '#';
        printf("%d\n", solve());
    }

    return 0;
}

