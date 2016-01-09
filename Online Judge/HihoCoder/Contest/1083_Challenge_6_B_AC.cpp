#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node {
    int x, y;
};

float abs(double a) {
    if(a > 0) {
        return a;
    }
    else {
        return (-a);
    }
}

int main(int argc, char **argv) {
    Node a, b, c;
    int n, T;
    double ans, sums, s, x1, x2, y1, y2;
    scanf("%d", &T);
    while(T--) {
        ans = 0.0, sums = 0.0;
        scanf("%d%d%d%d%d", &n, &a.x, &a.y, &b.x, &b.y);
        for(int i = 3; i <= n; ++i) {
            scanf("%d%d", &c.x, &c.y);
            x1 = b.x - a.x;
            x2 = c.x - a.x;
            y1 = b.y - a.y;
            y2 = c.y - a.y;
            s = (x1*y2-x2*y1)/2;
            sums += s;
            double p = (a.x+b.x+c.x) * 1.0 / 3;
            double q = (a.y+b.y+c.y) * 1.0 / 3;
            ans += s * p + s * q; // 重心的性质
            b = c;
        }
        printf("%.2f\n", sums < 0 ? -ans : ans);
    }

    return 0;
}

