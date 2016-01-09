#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxn = 36000;
int n, mod, ans, prim[35000];
bool flag[maxn + 20];

void get_prim() {
    memset(flag, 0x00, sizeof (flag));
    for(int i = 2; i <= 1000; i++) {
        if(!flag[i]) {
            for(int j = i * i; j <= maxn; j += i) {
                flag[j] = true;
            }
        }
    }
    for(int i = 2, k = 0; i <= maxn; i++) {
        if(!flag[i]) {
            prim[k++] = i;
        }
    }
}

int eular(int n) { // phi function.
    int i = 0, ans = 1;
    for(i = 0; prim[i] * prim[i] <= n; i++) {
        if(n % prim[i] != 0) {
            continue;
        }
        ans *= prim[i] - 1; n /= prim[i];
        while(n % prim[i] == 0) {
            ans *= prim[i]; n /= prim[i];
        }
    }
    if(n > 1) {
        ans *= n - 1;
    }
    return ans % mod;
}

int pow_mod(int c, int k, int mod) {
    int ans = 1;
    c = c % mod;
    while(k) {
        if(k & 1) {
            ans = (c * ans) % mod;
        }
        k >>= 1;
        c = (c * c) % mod;
    }
    return ans;
}

int main() {
    get_prim();
    int i, T;
    scanf("%d", &T);
    while(T-- && scanf("%d%d", &n, &mod)) {
        ans = 0;
        for(i = 1; i * i <= n; i++) {
            if (i * i == n) { //枚举循环长度l，找出相应的i的个数：gcd(i,n)=n/l.
                ans = (ans + pow_mod(n, i - 1, mod) * eular(i)) % mod;
            }
            else if(n % i == 0) { //有长度为l的循环，就会有长度为n/l的循环。
                ans = (ans + pow_mod(n, n / i - 1, mod) * eular(i) + 
                        eular(n / i) * pow_mod(n, i - 1, mod)) % mod;
            }
        }
        printf("%d\n", ans);
    }
}

