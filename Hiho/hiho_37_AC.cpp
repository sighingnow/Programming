#include <cstdio>
#include <iostream>
/**
 * Author: buaahetao@gmail.com, SCSE, BUAA
 */

int num[1000005];
int n, k;

int k_find(int l, int r, int k)
{
    int i = l, j = r, m = (l+r)>>1; 
    int x = num[m];
    while (i != j) {
        while (j > m && num[j] > x) {
            j--;
        }
        num[m] = num[j]; m = j;
        while (i < m && num[i] < x) {
            i++;
        }
        num[m] = num[i]; m = i;
    }
    num[i] = x;
    if (i < k) {
        return k_find(i+1, r, k);
    } else if (i > k) {
        return k_find(l, i-1, k);
    } else {
        return num[i];
    }
}

int main(int argc, char **argv) 
{
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", num+i);
    }
    if(k <= 0 || k > n) {
        printf("-1");
    }
    else {
        printf("%d", k_find(1, n, k));
    }
    return 0;
}

/* vim: set ts=4, sw = 4 */

