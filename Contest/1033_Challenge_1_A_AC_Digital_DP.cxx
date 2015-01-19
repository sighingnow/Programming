#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const long long MOD = 1000000007;

struct Node {
    long long sum, n;
    Node() {
        this->sum = 0;
        this->n = 0;
    }
    Node(long long sum, long long n) {
        this->sum = sum % MOD;
        this->n = n;
    }
} dp[20][400];

long long base[20], p;
int digit[20] = {0}, m = 0, n;

Node dfs(int pos, int current, bool flag) {
    Node t(0, 0), s;
    if(pos == 0) {
        if(current == 0) {
            t.n = 1;
        }
        return t;
    }
    if(!flag && dp[pos][current+200].n != -1) {
        return dp[pos][current+200];
    }
    int start = pos == m ? 1 : 0;
    int end = flag ? digit[pos] : 9;
    int signal = (m-pos)%2 == 0 ? 1 : -1;
    while(start <= end) {
        int aim = current - start * signal;
        s = dfs(pos-1, aim, flag && start == digit[pos]);
        p = s.n % MOD * start % MOD * base[pos] % MOD;
        t.sum = (t.sum + s.sum + p) % MOD;
        t.n += s.n;
        start += 1;
    }
    if(!flag) {
        dp[pos][current+200] = t;
    }
    return t;
}

int solve(long long num, int k) {
    n = 0;
    if(num < 1) {
        return 0;
    }
    while(num) {
        digit[++n] = (num % 10);
        num /= 10;
    }
    long long ans = 0;
    for(m = 1; m <= n; ++m) {
        memset(dp, 0xff, sizeof(dp));
        ans = (ans + dfs(m, k, m == n).sum) % MOD;
    }
    return ans;
}

int main(int argc, char **argv) {
    long long l, r;
    int k;
    cin >> l >> r >> k;
    base[0] = 0;
    base[1] = 1;
    for(int i = 2; i < 20; ++i) {
        base[i] = (base[i-1] * 10) % MOD; 
    }
    cout << (solve(r, k) - solve(l-1, k) + MOD) % MOD;
    return 0;
}

