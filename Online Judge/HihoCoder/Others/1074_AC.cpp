#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/**
 * Author: buaahetao@gmail.com, SCSE, BUAA
 * Datatime: 2015/1/10 8:56:25
 */

int num[100100];
bool flag[100100] = {false};

int main(int argc, char *argv[])
{
    int n, ans = 0, p, q;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", num+i);
    }
    if(n == 1) { printf("1\n1"); return 0; }
    if(n == 2) { printf("2\n1 2"); return 0; }
    for(int i = 2; i < n; ++i) {
        p = i, q = i;
        if(num[i-1] <= num[i]) {
            for(p = i; p < n; ++p) {
                if(num[p+1] >= num[i-1]) {
                    if(num[p+1] >= num[q]) {
                        q = p+1;
                    }
                }
                else {
                    break;
                }
            }
            if(q > i) {
                for(int j = i; j < q; ++j) {
                    flag[j] = true;
                }
                ans += (q-i);
                i = q;
            }
        }
        else if(num[i-1] >= num[i]) {
            for(p = i; p < n; ++p) {
                if(num[p+1] <= num[i-1]) {
                    if(num[p+1] <= num[q]) {
                        q = p + 1;
                    }
                }
                else {
                    break;
                }
            }
            if(q > i) {
                for(int j = i; j < q; ++j) {
                    flag[j] = true;
                }
                ans += (q-i);
                i = q;
            }
        }
    }
    printf("%d\n", n - ans);
    for(int i = 1; i <= n; ++i) {
        if(!flag[i]) {
            printf("%d ", i);
        }
    }
	return 0;
}

/* vim: set ts=4, sw = 4 */

