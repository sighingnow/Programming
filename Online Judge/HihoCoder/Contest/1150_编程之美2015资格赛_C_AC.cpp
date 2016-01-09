#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int a, b, A[1005][2], B[105][2];

inline long long fabs(long long n) {
    return n >= 0 ? n : (-n);
}

long long dist, xx, yy, ans;

long long calc(long long x, long long y) {
    long long result = 0L, minb = 1000000000000000000LL;
    for(int i = 1; i <= a; ++i) {
        result += (long long)(A[i][0]-x)*(A[i][0]-x);
        result += (long long)(A[i][1]-y)*(A[i][1]-y);
    }
    for(int j = 1; j <= b; ++j) {
        minb = min(minb, (fabs(B[j][0]-x)+fabs(B[j][1]-y)));
    }
    return result+minb;
}

int main(int argc, char** args) {
    int T, t = 0, n, m;
    long long u, v, r, s;
    scanf("%d", &T);
    while(++t <= T) {
        scanf("%d%d%d%d", &n, &m, &a, &b);
        xx = 0, yy = 0;
        for(int i = 1; i <= a; ++i) {
            scanf("%d%d", &A[i][0], &A[i][1]);
            xx += A[i][0], yy+= A[i][1];
        }
        for(int j = 1; j <= b; ++j) {
            scanf("%d%d", &B[j][0], &B[j][1]);
        }
        
        u = calc(xx/a, yy/a);
        v = calc(xx/a, yy/a+1);
        r = calc(xx/a+1, yy/a);
        s = calc(xx/a+1, yy/a+1);
        ans=min(u, v); ans=min(ans,r); ans=min(ans,s);
        printf("Case #%d: %lld\n", t, ans);
    }

    return 0;
}

