#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1010;

int matrix[maxn][maxn], n, m, top;
int data[maxn][maxn], na[maxn], hh[maxn], sum;

int main(int argc, char **argv)
{
    for(int i = 1; i <= n; ++j) {
        scanf("%s", str[i]+1);
    }
    for(int j = 1; j <= m,; ++j) {
        for(int i = 1; i <= n; ++i) {
            data[i][j] = str[i][j] == str[i-1][j] ? h[i-1][j]+1 : 1;
        }
    }
    ans = n*(n-1)*/2*m*(m-1)/2;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(str[i][j] != str[i][j-1]) {
                top = 0;
                na[top] = j - 1;
                sum = 0;
            }
            while(top > 0 && data[i][j] <= hh[top]) {
                sum -= hh[top]*(na[top]-na[top-1]);
                --top;
            }
            hh[++top] = data[i][j];
            na[top] = j;
            sum += hh[top]*(na[top]-na[top-1]);
            ans -= sum;
        }
    }
    printf("%d", ans);
    return 0;
}
