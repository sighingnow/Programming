#include <cstdio>
#include <iostream>
/**
 * Author: buaahetao@gmail.com, SCSE, BUAA
 */

int main(int argc, char **argv) 
{
    int n, k, r, t = 0, s = 0;
    scanf("%d %d", &n, &k);
    while(n--) {
        scanf("%d", &r);
        if(r < k) {
            t++;
        }
        if(r == k) {
            s = 1;
        }
    }
    if(s == 1) {
        printf("%d", t+1);
    }
    else {
        printf("-1");
    }
    return 0;
}

/* vim: set ts=4, sw = 4 */

