#include <cstdio>
#include <cstring>
using namespace std;

char s[1000010], t[1000010];
int next[1000010];

// KMP.

int getNext() {
    int i = 0, j = -1;
    next[0] = -1; // NOTE!!!
    int len = strlen(s);
    while(i < len) {
        if(j == -1 || s[i] == s[j]) {
            ++i;
            ++j;
            if(s[i] != s[j]) {
                next[i] = j;
            }
            else {
                next[i] = next[j];
            }
        }
        else {
            j = next[j];
        }
    }
}

int kmp() {
    int ans = 0;
    int i = 0, j = 0;
    int len_s = strlen(s), len_t = strlen(t);
    if(len_t == 1 && len_s == 1) {
        if(s[0] == t[0]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    getNext();
    for(i = 0; i < len_t; ++i) {
        while(j > 0 && t[i] != s[j]) {
            j = next[j];
        }
        if(s[j] == t[i]) {
            j++;
        }
        if(j == len_s) {
            ans++;
            j = next[j];
        }
    }
    return ans;
}

int main(int argc, char **argv) {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s %s", s, t);
        printf("%d\n", kmp());
    }

    return 0;
}

