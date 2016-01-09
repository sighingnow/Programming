#include <iostream>
using namespace std;

const long long MOD = 12357;

long long N;
long long a[5];

void solve() {
    a[0] = 0;
    a[1] = 2;
    a[2] = 3;
    for (int i = 3; i <= N; ++i) {
        if (i & 1) {
            a[i%5] = (2*a[(i-1+5)%5] + a[(i-2+5)%5]) % MOD;
        } else {
            a[i%5] = (3*a[(i-2+5)%5] + a[(i-3+5)%5]) % MOD;
        }
    }
    cout << a[N%5] << endl;
}

int main(int argc, char **argv) {
    while (cin >> N) {
        if (N & 1) {
            cout << "0" << endl;
        } else {
            solve();
        }
    }
    return 0;
}
