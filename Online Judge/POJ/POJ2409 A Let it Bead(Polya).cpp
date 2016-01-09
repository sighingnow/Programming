#include <cstdio>
using namespace std;

// Polya.

inline long long gcd(long long a, long long b) {
    return b==0?a:gcd(b, a%b);
}

long long llpow(long long a, long long b) {
    return b==0?1:llpow(a, b-1)*a;
}

long long polya(long long n, long long m) {
    long long sum = 0;
    for(int i = 1; i <= m; ++i) {
        sum += llpow(n, gcd(m, i));
    }
    if(m & 1) {
        sum += m*llpow(n, (m>>1)+1);
    }
    else {
        sum += (m>>1)*llpow(n, (m>>1)+1) + (m>>1)*llpow(n, m>>1);
    }
    return sum/2/m; // 去掉翻转和旋转的重复
}

int main(int argc, char **argv) {
    long long n, m;
    while(scanf("%lld%lld", &n, &m) != EOF && m+n > 0) {
        printf("%lld\n", polya(n, m));
    }

    return 0;
}

