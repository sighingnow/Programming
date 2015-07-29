#include <cstdio>
using namespace std;

// segment tree.

int sum[120010];

void build(int l, int r, int rt) {
    if(l == r) {
        sum[rt] = 1;
        return;
    }
    int m = (l+r) >> 1;
    build(l, m, rt << 1);
    build(m+1, r, rt << 1 | 1);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int p, int l, int r, int rt) {
    sum[rt]--;
    if(l == r) {
        printf("%d ", l);
        return;
    }
    int m = (l+r) >> 1;
    if(p <= sum[rt << 1]) {
        update(p, l, m, rt << 1);
    }
    else {
        update(p-sum[rt<<1], m+1, r, rt << 1 | 1);
    }
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

int main(int argc, char **argv) {
    int n, m;
    scanf("%d %d", &n, &m);
    build(1, n, 1);
    int seq = 1;
    for(int i = 1; i <= n; ++i) {
        seq = (seq+m-1) % sum[1]; // get the relative postion.
        if(seq == 0) {
            seq = sum[1];
        }
        update(seq, 1, n, 1);
    }

    return 0;
}

