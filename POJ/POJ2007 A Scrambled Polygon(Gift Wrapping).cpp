#include <stdio.h>

typedef struct Node{
    int x, y;
} node;

node point[100];
int convex_set[100], top = 0;

bool comp(node src, node a, node b) {
    int ax = a.x - src.x, bx = b.x - src.x;
    int ay = a.y - src.y, by = b.y - src.y;
    int product = ax*by - ay*bx;

    if(product < 0) { 
        return true; // 从a顺时针转到b
    }
    else {
        return false;
    }
}

int main(int argc, char *argv[]) {
    freopen("data.in", "r", stdin);

    int n = 0;
    while(scanf("%d %d", &point[n+1].x, &point[n+1].y) == 2) {
        n++;
    }
    int current = 1;
    do {
        convex_set[top++] = current;
        int k = 0;
        for(int i = 1; i <= n; ++i) {
            if((current != i && k == 0) || comp(point[current], point[k], point[i])) {
                k = i;
            }
        }
        current = k;
    } while (current != 1);

    for(int i = 0; i < top; ++i) {
        printf("(%d,%d)\n", point[convex_set[i]].x, point[convex_set[i]].y);
    }

    return 0;
}
