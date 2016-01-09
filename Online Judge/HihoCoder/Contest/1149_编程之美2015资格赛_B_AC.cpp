#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int f[1005][1005], MOD = 100007;
char s[1005];

int dp(char s[], int len) {
    memset(f, 0x00, sizeof(int)*1005*1005);
    for(int i = 0; i < len; ++i) {
        f[i][i] = 1;
    }
    for(int k = 1; k < len; ++k) {
        for(int i = 0; i + k < len; ++i) {
            f[i][i+k] = (f[i][i+k]+f[i+1][i+k]+f[i][i+k-1]-f[i+1][i+k-1]+MOD)%MOD;
            if(s[i] == s[i+k]) {
                f[i][i+k] = (f[i][i+k]+f[i+1][i+k-1]+1)%MOD;
            }
        }
    } 
    return f[0][len-1]%MOD;
}

int main(int argc, char** argv) {
    int T, t = 0, n, ans;
    scanf("%d", &T);
    while(++t <= T) {
        scanf("%s", s);
        printf("Case #%d: %d\n", t, dp(s, strlen(s)));
    }
    return 0;
}
