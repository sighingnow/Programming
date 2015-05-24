#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const float pi = 3.1415926;

typedef struct Node {
    int x, y;
} node;

node castle[1010];
bool vis[1010];
float len = 0.0f;

bool comp(node a, node b) {
    if(a.x < b.x || (a.x == b.x && a.y <= b.y)) {
        return true;
    }
    else {
        return false;
    }
}

inline int cross_product(node src, node a, node b) {
    int ax = a.x - src.x, bx = b.x - src.x;
    int ay = a.y - src.y, by = b.y - src.y;
    return ax*by - bx*ay; // 若为正，则a在外侧(a逆时针转向b)
}

int main(int argc, char **argv) {
    // freopen("data.in", "r", stdin);
    int n, gap;
    scanf("%d %d", &n, &gap);
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d", &castle[i].x, &castle[i].y);
    }
    sort(castle+1, castle+n+1, comp);
    
    int cur_node = 1, index = 2;
    vis[cur_node] = true; 
    int tmp_a, tmp_b;
    while(index < n) { // 寻找下方的点
        for(index = 2; index <= n; ++index) {
            if(!vis[index]) {
                tmp_a = index;
                break;
            }
        }
        for(index = index + 1; index <= n; ++index) {
            if(index <= n && !vis[index]) {
                tmp_b = index;
                int product = cross_product(castle[cur_node], castle[tmp_a], castle[tmp_b]);
                if((product < 0) || (product == 0 && castle[tmp_a].x < castle[tmp_b].x)) {
                    tmp_a = tmp_b;
                }
            }
        }
        len += sqrt((castle[tmp_a].x-castle[cur_node].x) * (castle[tmp_a].x-castle[cur_node].x)
                + (castle[tmp_a].y-castle[cur_node].y)*(castle[tmp_a].y-castle[cur_node].y));
        cur_node = tmp_a;
        vis[cur_node] = true;
        index = cur_node;
    }

    cur_node = 1, index = 2; 
    vis[n] = false;
    while(index < n) { // 寻找上方的点
        for(index = 2; index <= n; ++index) {
            if(!vis[index]) {
                tmp_a = index;
                break;
            }
        }
        for(index = index + 1; index <= n; ++index) {
            if(index <= n && !vis[index]) {
                tmp_b = index;
                int product = cross_product(castle[cur_node], castle[tmp_a], castle[tmp_b]);
                if((product > 0) || (product == 0 && castle[tmp_a].x < castle[tmp_b].x)) {
                    tmp_a = tmp_b;
                }
            }
        }
        len += sqrt((castle[tmp_a].x-castle[cur_node].x) * (castle[tmp_a].x-castle[cur_node].x)
                + (castle[tmp_a].y-castle[cur_node].y)*(castle[tmp_a].y-castle[cur_node].y));
        cur_node = tmp_a;
        vis[cur_node] = true;
        index = cur_node;
    } 

    float len_circle = 2 * pi * gap;

    printf("%d", (int)(len + len_circle + 0.5));

    return 0;
}

