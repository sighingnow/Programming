#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int max_n = 55;

int n;
int dim[max_n];
int value[max_n][max_n];
int ans[max_n][max_n];

int dp() {
    memset(value, 0xff, sizeof(value));
    memset(ans, 0xff, sizeof(ans));
    for(int i = 1; i <= n; ++i) {
        value[i][i+1] = 0;
    }
    for(int i = 3; i <= n+1; ++i) {
        for(int j = i-2; j >= 1; --j) {
            for(int k = i-1; k > j; --k) {
                int tmp = value[j][k] + value[k][i]+ dim[j]*dim[k]*dim[i];
                if(value[j][i] == -1 || tmp < value[j][i]) {
                    value[j][i] = tmp;
                    ans[j][i] = k;
                }
            }
        }
    }
}

void output(int i, int j) {
    if(j - i == 1) {
        printf("A%d", i);
    }
    else {
        printf("(");
        output(i, ans[i][j]);
        printf(" x ");
        output(ans[i][j], j);
        printf(")");
    }
}

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    int T = 0;
    while(cin >> n && n) {
        T++;
        for(int i = 1; i <= n; ++i) {
            scanf("%d %d", &dim[i], &dim[i+1]);
        }
        dp();
        printf("Case %d: ", T);
        output(1, n+1);
        printf("\n");
    }

    return 0;
}

