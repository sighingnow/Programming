#include <cstdio>
#include <algorithm>
using namespace std;

int a[100010];
int n, k;

bool isprime(int n) {
    if(n < 2) {
        return false;
    }
    if(n == 2) {
        return true;
    }
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    if(isprime(a[n+1-k]-a[k])) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    printf("%d", a[n+1-k]-a[k]);

    return 0;
}

