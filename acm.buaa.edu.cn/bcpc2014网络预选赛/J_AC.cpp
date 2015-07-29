#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// http://oeis.org/search?q=0%2C1%2C7%2C46%2C326%2C2556%2C&language=english&go=search

const long long MOD = 1000000007;

long long fact[1000010] = {1, 1, 2, 6};
long long ans[1000010] = {0, 0, 1, 7};

int main(int argc, char **argv) {
    long long n, T = 0, current = 3;
    while(~scanf("%lld", &n)) {
        T++;
        if(n > current) {
            for(int i = current + 1; i <= n; ++i) {
                fact[i] = (fact[i-1] * i) % MOD;
                ans[i] = (i * ans[i-1] + (i-1) * fact[i-1]) % MOD;
            }
        }
        current = n;
        printf("Case #%lld: %lld\n", T, ans[n]);
    }

    return 0;
}

