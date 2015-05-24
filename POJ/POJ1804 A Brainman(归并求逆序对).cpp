#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define N 100010

int a[N], tmp[N];
int T, n;
long long ans;

void merge(int l, int m, int r) {
    int i = l, j = m+1, k = l;

    /**
     * 当a[i]<=a[j]时，并不产生逆序数；当a[i]>a[j]时，在
     * 前半部分中比a[i]大的数都比a[j]大，将a[j]放在a[i]前面的话，逆序数要加上mid+1-i。
     */
    while (i <= m && j <= r) {
        if (a[i] > a[j]) {
            tmp[k++] = a[j++];
            ans += (m-i+1);
        }
        else {
            tmp[k++] = a[i++];
        }
    }

    while (i <= m) {
        tmp[k++] = a[i++];
    }

    while (j <= r) {
        tmp[k++] = a[j++];
    }

    for (int i = l; i <= r; ++i) {
        a[i] = tmp[i];
    }
}

void merge_sort(int l, int r) {
    if (l < r) {
        int m = (l+r) >> 1;
        merge_sort(l, m);
        merge_sort(m+1, r);
        merge(l, m, r);
    }
}

int main(int argc, char** argv) {
    scanf("%d", &T);

    for (int tt = 1; tt <= T; ++tt) {
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", a+i);
        }

        ans = 0;
        merge_sort(0, n-1);
        printf("Scenario #%d:\n%lld\n\n", tt, ans);
    }

    return 0;
}
