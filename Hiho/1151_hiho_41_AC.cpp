#include <stdio.h>

void multi(long long int n, long long int m[][2], long long int tem[][2]) {
    long long int ret[2][2] = {{m[0][0], m[0][1]}, {m[1][0], m[1][1]}};
    long long int tmp[2][2];
    tem[0][0] = tem[1][1] = 1;
    tem[0][1] = tem[1][0] = 0;

    while (n) {
        if (n & 1) {
            tmp[0][0] = tem[0][0] * ret[0][0] + tem[0][1] * ret[1][0];
            tmp[0][1] = tem[0][0] * ret[0][1] + tem[0][1] * ret[1][1];
            tmp[1][0] = tem[1][0] * ret[0][0] + tem[1][1] * ret[1][0];
            tmp[1][1] = tem[1][0] * ret[0][1] + tem[1][1] * ret[1][1];
            tem[0][0] = tmp[0][0] % 19999997;
            tem[0][1] = tmp[0][1] % 19999997;
            tem[1][0] = tmp[1][0] % 19999997;
            tem[1][1] = tmp[1][1] % 19999997;
        }

        tmp[0][0] = ret[0][0] * ret[0][0] + ret[0][1] * ret[1][0];
        tmp[0][1] = ret[0][0] * ret[0][1] + ret[0][1] * ret[1][1];
        tmp[1][0] = ret[1][0] * ret[0][0] + ret[1][1] * ret[1][0];
        tmp[1][1] = ret[1][0] * ret[0][1] + ret[1][1] * ret[1][1];
        ret[0][0] = tmp[0][0] % 19999997;
        ret[0][1] = tmp[0][1] % 19999997;
        ret[1][0] = tmp[1][0] % 19999997;
        ret[1][1] = tmp[1][1] % 19999997;
        n >>= 1;
    }
}

int main(int argc, char** argv) {
    long long int n;
    long long ans[2][2];
    long long matrix[2][2];

    scanf("%lld", &n);
    matrix[0][0] = 0;
    matrix[0][1] = matrix[1][0] = matrix[1][1] = 1;
    multi(n+1, matrix, ans);
    printf("%lld\n", ans[0][1] % 19999997);

    return 0;
}
