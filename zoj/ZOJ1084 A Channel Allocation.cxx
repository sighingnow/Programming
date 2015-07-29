#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int ans, n;
int g[26][26];
int flag[27];
int color[26];

void solve() {
    ans = 0;
    memset(color, 0x00, sizeof(color));
    for(int i = 0; i < n; ++i) {
        memset(flag, 0x00, sizeof(flag));
        for(int j = 0; j < i; ++j) { // 注意此处不应该访问后边的点
            if(g[i][j]) {
                flag[color[j]] = true;
            }
        }
        for(int j = 1; ; ++j) {
            if(!flag[j]) {
                color[i] = j;
                ans = ans > j ? ans : j;
                break;
            }
        }
    }
}  

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    char s[50];
    while(scanf("%d", &n) && n) {
        memset(g, 0x00, sizeof(g));
        for(int i = 0; i < n; ++i) {
            scanf("%s", s);
            int j = 2;
            while(j < strlen(s)) {
                g[i][s[j]-'A'] = 1;
                j++;
            }
        }
        
        solve();
        
        if(ans == 1) {
            printf("1 channel needed.\n");
        }
        else {
            printf("%d channels needed.\n", ans);
        }
    }
    
    return 0;
} 
