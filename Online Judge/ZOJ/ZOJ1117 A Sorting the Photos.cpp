#include <cstdio>
using namespace std;

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    int T, n, ans;
    char ch, current;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        ans = 0;
        for(int i = 1; i <= n; ++i) {
            do {
                ch = getchar();
            } while(ch != 'U' && ch != 'D');
            if(i == 1) {
                current = ch;
                continue;
            }
            if(current != ch) {
                ans += 1;
                current = ch;
            }
        }
        printf("%d\n", ans);
        if(T) {
            printf("\n");
        }
    }
    
    return 0;
}