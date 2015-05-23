#include <cstdio>
#include <iostream>
#include <cstring>
#include <list>
using namespace std;

/**
 * SGU 101. Domino
 * Euler path.
 */

struct Edge {
    int x, y;
};
const int maxn = 105;
Edge edge[maxn], path[maxn];
int mat[10][10];
int n, x, y, start = 0, flag = 0, degree[10], p = 0;

void dfs(int s) {
    for(int i = 0; i <= 6; ++i) {
        if(mat[s][i]) {
            mat[s][i]--; mat[i][s]--;
            dfs(i);
            p++; path[p].x = s; path[p].y = i;
        }
    }
}

void output() {
    for(int i = p; i >= 1; --i) {
        for(int j = 1; j <= n; ++j) {
            if(edge[j].x == path[i].x && edge[j].y == path[i].y) {
                edge[j].x = -1; printf("%d +\n", j); break;
            }
            else if(edge[j].x == path[i].y && edge[j].y == path[i].x) {
                edge[j].x = -1; printf("%d -\n", j); break;
            }
        }
    }
}

int main(int argc, char** args) {
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d", &x, &y);
        edge[i].x = x, edge[i].y = y;
        degree[x]++; degree[y]++;
        mat[x][y]++; mat[y][x]++;
    }
    
    for(int i = 0; i <= 6; ++i) {
        if(degree[i]) {
            start = i; break;
        }
    }
    for(int i = 0; i <= 6; ++i) {
        if(degree[i] % 2 == 1) {
            flag++; start = i;
        }
    }

    if(flag!=0 && flag!=2) {
        printf("No solution"); return 0;
    }
    
    dfs(start);
    
    if(p < n) {
        printf("No solution"); return 0;
    }

    output();

    return 0;
}

