#include <cstdio>
#include <cstring>
using namespace std;

/**
 * 贪心。
 *
 * POJ 3617, Best Cow Line
 */

const int maxn = 2e3+5;
char S[maxn], T[maxn];
int n, len, head, tail, top;

int main(int argc, char **argv) {
    scanf("%d", &n);
    scanf("%s", S);
    len = strlen(S); head = 0; top = 0; tail = len-1;
    while(top < len) {
        int k = 0;
        while(head+k<=tail && S[head+k]==S[tail-k]) {
            ++k;
        }
        if(S[head+k] < S[tail-k]) {
            T[top++] = S[head++];
        }
        else {
            T[top++] = S[tail--];
        }
    }
    printf("%s", T);
}


