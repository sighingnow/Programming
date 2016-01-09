#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int max_n = 10050;
int n, ans;
int point[2*max_n], cnt, tmp;
bool flag[max_n];

struct Line {
    int l, r;
    int color; //index
} line[max_n];

struct Node {
    int l, r;
    int color;
} tree[8*max_n];

inline void build_tree(int index = 1, int l = 0, int r = cnt-1) {
    tree[index].color = -1;
    tree[index].l = point[l];
    tree[index].r = point[r];
    if(r - l > 1) {
        int mid = (l+r) >> 1;
        build_tree(index<<1, l, mid);
        build_tree(index<<1|1, mid, r);
    }
}

void update(int index, int l, int r, int value) {
    if(l <= tree[index].l && r >= tree[index].r) {
        tree[index].color = value;
        return;
    }
    if(~tree[index].color) {
        tree[index<<1].color = tree[index].color;
        tree[index<<1|1].color = tree[index].color;
        tree[index].color = -1;
    }
    if(l < tree[index<<1].r) {
        update(index<<1, l, r, value);   
    }
    if(r > tree[index<<1|1].l) {
        update(index<<1|1, l, r, value);
    }
}

void query(int index = 1) { // bfs
    if(~tree[index].color) {
        flag[tree[index].color] = true;
        return;
    }
    if(tree[index].r - tree[index].l > 1) {
        query(index<<1);
        query(index<<1|1);
    }
}

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(line, 0x00, sizeof(line));
        memset(point, 0x00, sizeof(point));
        memset(tree, 0x00, sizeof(tree));
        memset(flag, 0x00, sizeof(flag));
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &line[i].l, &line[i].r);
            line[i].l--;
            point[2*i] = line[i].l;
            point[2*i+1] = line[i].r;
        }
        sort(point, point+2*n);
        cnt = tmp = 0;
        point[cnt++] = point[tmp++];
        while(tmp < 2*n) {
            if(point[cnt-1] != point[tmp]) {
                point[cnt++] = point[tmp];
            }
            tmp++;
        }
        build_tree();
        for(int i = 0; i < n; ++i) {
            update(1, line[i].l, line[i].r, i);
        }
        query();
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if(flag[i]) {
                ans++;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}

