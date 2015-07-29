#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int max_n = 1005;

struct Node {
    double x, y;    
} node[max_n];

int n, first;
double len;
int stack[max_n], top = 0;

inline int cross_product(Node src, Node a, Node b) {
    int xa = a.x - src.x, xb = b.x - src.x;
    int ya = a.y - src.y, yb = b.y - src.y;
    return xa*yb - xb*ya;
}

inline int dist(Node src, Node a, Node b) {
    int xa = a.x - src.x, xb = b.x - src.x;
    int ya = a.y - src.y, yb = b.y - src.y;
    return (xa*xa+ya*ya) - (xb*xb+yb*yb);
} 

bool comp(Node a, Node b) {
    int product = cross_product(node[1], a, b);
    if(product > 0) {
        return true;
    }
    else if(product == 0){
        if(dist(node[1], a, b) < 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void graham_scan() {
    swap(node[first], node[1]);
    sort(node+2, node+n+1, comp);
    node[n+1].x = node[1].x, node[n+1].y = node[1].y; //append start point

    stack[top++] = 1;
    stack[top++] = 2;
    for(int index = 3; index <= n; ++index) {
        while(index <= n && cross_product(node[stack[top-2]], node[stack[top-1]], node[index]) < 0) {
            top--;
        }
        stack[top++] = index;
    }
    stack[top++] = n+1;
}

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    while(scanf("%d", &n)) {
        if(n == 0) {
            break;
        }
        memset(node, 0, sizeof(node));
        len = 0.0, top = 0, first = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%lf %lf", &node[i].x, &node[i].y);
            if(first == 0 || node[i].x < node[first].x 
                    || (node[i].x == node[first].x && node[i].y < node[first].y)) {
                first = i;
            }
        }
        
        if(n == 1) {
            printf("0.00\n");
            continue;
        }
        if(n == 2) {
            printf("%.2lf\n", 2*sqrt((node[1].x-node[2].x)*(node[1].x-node[2].x)
                        +(node[1].y-node[2].y)*(node[1].y-node[2].y)));
            continue;
        }

        graham_scan();
        
        for(int i = 1; i < top; ++i) {
            len += sqrt((node[stack[i-1]].x-node[stack[i]].x)*(node[stack[i-1]].x-node[stack[i]].x)
                    + (node[stack[i-1]].y-node[stack[i]].y)*(node[stack[i-1]].y-node[stack[i]].y));
        }
        printf("%.2lf\n", len);
    }
}

