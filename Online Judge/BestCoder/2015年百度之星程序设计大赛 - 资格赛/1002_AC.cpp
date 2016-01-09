#include <cstdio>
using namespace std;

int main(int argc, char **argv) {
    int T, t = 0, k, len, bound, index, x, y;
    char c, str[100005];
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(++t <= T) {
        printf("Case #%d:\n", t);
        getchar(); len = 0; k = 0;
        while((c = getchar()) != '\n') {
            str[++len] = c;
        }
        scanf("%d", &k);
        x = len % k; y = len / k;
        if(x != 0) { y += 1; }
        else { x = k; }
        for(int i = 1; i <= y; ++i) {
            if(i == y) { bound = x; }
            else { bound = k; }
            for(int j = 1; j <= bound; ++j) {
                if(j <= x) {
                    index = (j-1)*y+i;
                }
                else {
                    index = x*y+(j-x-1)*(y-1)+i;
                }
                printf("%c", str[index]);
            }
        }
        printf("\n");
    }
    return 0;
}

