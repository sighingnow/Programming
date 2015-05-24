#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int max_n = 50050;

struct Node {
    int x, y;
} node[max_n];

inline int cross(Node src, Node a, Node b) {
    return (a.x-src.x)*(b.y-src.y)-(a.y-src.y)*(b.x-src.x);
}

inline int dist(Node a, Node b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool cmp(Node a, Node b) {
    int ans = cross(node[0], a, b);
    if(ans > 0 || (ans == 0 && dist(node[0], a) > dist(node[0], b))) {
        return true;
    }
    else {
        return false;
    }
}

int n;
int convex_set[max_n], top = 0;

void graham_scan() {
    sort(node+1, node+n, cmp);
    convex_set[top++] = 0;
    convex_set[top++] = 1;
    for(int i = 2; i != n; ++i) {
        while(top && i < n && cross(node[convex_set[top-2]], node[convex_set[top-1]], node[i]) < 0) {
            top--;
        }
        convex_set[top++] = i;
    }
}

int rc() {// Rotating Calipers Algorithm, 旋转卡壳
    int q = 1;
    int ans = dist(node[convex_set[0]], node[convex_set[1]]);
    for(int i = 0; i != top; ++i) {
        while(abs(cross(node[convex_set[(i+1)%top]], node[convex_set[(i)%top]], node[convex_set[(q+1)%top]])) >
                abs(cross(node[convex_set[(i+1)%top]], node[convex_set[(i)%top]], node[convex_set[q%top]]))) {
            q = (q+1) % top;
        }
        ans = max(ans, max(dist(node[convex_set[(i+1)%top]], node[convex_set[q]]), 
                    dist(node[convex_set[i%top]], node[convex_set[q]])));
    }
    return ans;
}

int main(int argc, char **argv) {
    // freopen("data.in", "r", stdin);

    scanf("%d", &n);
    int first = -1;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &node[i].x, &node[i].y);
        if(first == -1 || node[i].y < node[first].y || 
                (node[i].y == node[first].y && node[i].x < node[first].x)) {
            first = i;
        }
    }
    swap(node[first], node[0]);
    graham_scan();
    int ans = rc();
    printf("%d", ans);

    return 0;
}
