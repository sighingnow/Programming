#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int max_n = 10500;

struct Node {
    int x, y;
    friend bool operator < (const Node a, const Node b) {
        return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
    }
    friend bool operator > (const Node a, const Node b) {
        return (a.x == b.x) ? (a.y > b.y) : (a.x > b.x);
    }
} node[max_n];

Node hull[max_n];
int top = 0;
int s[max_n] = {0}; // 用于记录叉积值

inline int cross(Node src, Node a, Node b) {
    int xa = a.x-src.x, xb = b.x-src.x;
    int ya = a.y-src.y, yb = b.y-src.y;
    return xa*yb - xb*ya;
}

void quickhull(int u, int v, Node A, Node B) {
    int p = u;
    for(int k = u; k <= v; ++k) {
        if(s[p] < s[k] || (s[p] == s[k] && node[p] < node[k])) {
            p = k;
        }
    }
    Node C = node[p];
    int i = u-1, j = v+1;
    for(int k = u; k <= v; ++k) {
        s[++i] = cross(node[k], A, C);
        if(s[i] > 0) {
            swap(node[i], node[k]);
        }
        else {
            --i;
        }
    }
    for(int k = v; k >= u; --k) {
        s[--j] = cross(node[k], C, B);
        if(s[j] > 0) {
            swap(node[j], node[k]);
        }
        else {
            ++j;
        }
    }
    if(u <= i) {
        quickhull(u, i, A, C);
    }
    hull[top++] = C;
    if(j <= v) { 
        quickhull(j, v, C, B);
    }
}

int main(int argc, char *argv[]) {
    freopen("data.in", "r", stdin);
    int n, first = 0, last = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d", &node[i].x, &node[i].y);
        if(first == 0 || node[i] < node[first]) {
            first = i;
        }
        if(last == 0 || node[i] > node[last]) {
            last = i;
        }
    }
    if(n < 3) {
        printf("0");
        return 0;
    }
    swap(node[1], node[first]);
    swap(node[n], node[last]);
    hull[top++] = node[1];
    quickhull(2, n, node[1], node[1]);
    
    float ans_area = 0.0f;
    for(int a = 0, b = 1, c = 2; c < top; ++b, ++c) {
        float tmp = cross(hull[a], hull[b], hull[c]) / 2.0;
        if(tmp >= 0) {
            ans_area += tmp;
        }
        else {
            ans_area += (-tmp);
        }
    }
    printf("%d", (int)(ans_area/50.0));

    return 0;
}
