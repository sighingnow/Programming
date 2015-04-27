#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxp = 500005;

bool map[1005][1005], primes[500010] = {true, true, false, false, true};
int number[1005];

void initialprimes() {
    for(int i = 2; i < maxp; ++i) {
        if(primes[i]) {
            continue;
        }
        for(int j = i+i; j < maxp; j += i) {
            primes[j] = true;
        }
    }
}

bool isrelative(int a, int b) {
    if(a > b) {
        swap(a, b);
    }
    int t = b / a;
    if(a*t == b && !primes[t]) {
        return true;
    }
    return false;
}

bool dfs(int t, int m, bool *isVisit, int *link) { //dfs算法寻找增广路径
    for(int i = 1; i <= m; ++i) {
        if(!isVisit[i] && map[t][i]) {
            isVisit[i] = 1;
            if(link[i] == -1 || dfs(link[i], m, isVisit, link)) {
                link[i] = t;
                return true;
            }
        }
    }
    return false;
}

int Hungarian(int n, int m) {
    bool isVisit[m+1];
    int link[m+1], ans = 0;
    memset(link, 0xff, sizeof(link));
    memset(isVisit, 0, sizeof(isVisit));
    for(int i = 1; i <= n; ++i) {
        memset(isVisit, 0, sizeof(isVisit));
        if(dfs(i, m, isVisit, link))
            ++ans;
    }
    return ans/2;
}

int main(int argc, char **argv) { //Hungarian算法，max_match
    int T, t = 0, n, ans;
    scanf("%d", &T);
    initialprimes();
    while(++t <= T) {
        scanf("%d", &n);
        memset(map, 0x00, sizeof(map));
        memset(number, 0x00, sizeof(number));
        for(int i = 1; i <= n; ++i) {
            scanf("%d", number+i);
            for(int j = 1; j <= i; ++j) {
                if(isrelative(number[i], number[j])) {
                    map[i][j] = map[j][i] = true;
                }
            }
            map[i][i] = false;
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                printf("%d ", map[i][j]); 
            }
            printf("\n");
        }
        ans = Hungarian(n, n);
        printf("%d\n", ans);
        printf("Case #%d: %d\n", t, n-ans);
    }
    return 0;
}

