#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/**
 * Author: buaahetao@gmail.com, SCSE, BUAA
 * Datatime: 2015/1/10 8:56:25
 */

int num[1000100];
int st[1000100][20];

int rmq(int n) {
    for(int i = 1; (1<<i) <= n; ++i) {
        for(int j = 1; (j+(1<<i)-1) <= n; ++j) {
            st[j][i] = min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
        }
    }
}

int query(int a, int b) {
    if(a > b) {
        swap(a, b);
    }
    int len = b-a+1, k = 0;
    while(len>>1) {
        k += 1;
        len >>= 1;
    }
    return min(st[a][k], st[b-(1<<k)+1][k]);
}

int main(int argc, char *argv[])
{
    int n, q, x, y;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", num+i);
        st[i][0] = num[i];
    }
    rmq(n);
    scanf("%d", &q);
    for(int i = 1; i <= q; ++i) {
        scanf("%d %d", &x, &y);
        printf("%d\n", query(x, y));
    }
	return 0;
}

/* vim: set ts=4, sw = 4 */


