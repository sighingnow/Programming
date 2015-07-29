#include <cstdio>
#include <algorithm>
using namespace std;

int a[10010];
int b[100000];
int n = 0;
const int inf = 0x7fffffff;
int out = 0;

inline void select(int & ans, int & p, int & tail, int & head) {
    int k = inf, t = inf, s = inf;
    if(p <= n && tail < head) {
        k = a[p] + b[tail];
    }
    if(p < n) {
        t = a[p] + a[p+1];
    }
    if(tail + 1 < head) {
        s = b[tail] + b[tail+1];
    }
    if(k <= t && k <= s) {
        ans = k;
        p++;
        tail++;
        return;
    }
    if(t <= k && t <= s) {
        ans = t;
        p += 2;
        return;
    }
    ans = s;
    tail += 2;
    return;
}

int main(int argc, char **argv) {
    scanf("%d", &n);
    int p = 1, tail = 0, head = 0, x, y, tmp;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    if(n == 1) {
        printf("%d", a[1]);
        return 0;
    }
    while(p <= n) {
        select(tmp, p, tail, head);
        out += tmp;
        b[head++] = tmp;
    }
    while(tail+1 < head) {
        b[head++] = b[tail] + b[tail+1];
        out += b[head-1];
        tail += 2;
    }
    printf("%d", out);

    return 0;
}
