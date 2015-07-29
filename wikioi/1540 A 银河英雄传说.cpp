#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
//wikioi: 1540

const int MAXN = 30010;

int root[MAXN]; // 队首
int before[MAXN]; // 到队首之间的战舰数量（包括队首）
int after[MAXN]; // 其后到队尾的战舰数量（包括自身）

inline int abs(int a) {
    return a >= 0 ? a : (-a);   
}

int find_root(int n) {
    // 在压缩路径的同时更新计数
    if(n == root[n]) {
        return n;
    }
    int current_root = root[n]; // 预存当前跟节点
    root[n] = find_root(root[n]);
    before[n] += before[current_root];
    return root[n];
}

int main(int argc, char **argv) {
    
    int k, u, v;
    char command;
    for(int i = 0; i < MAXN; ++i) {
        root[i] = i;
        before[i] = 0;
        after[i] = 1;
    }
    scanf("%d", &k);
    while(k--) {
        scanf("\n%c %d %d", &command, &u, &v);
        int ru = find_root(u);
        int rv = find_root(v);
        switch (command) {
            case ('M'): {
                if(ru != rv) {
                    root[ru] = rv;
                    before[ru] = after[rv];
                    after[rv] += after[ru];
                }
                break;
            }
            case ('C'): {
                if(ru != rv) {
                    printf("-1\n");    
                }
                else {
                    printf("%d\n", abs(before[u] - before[v]) - 1);
                }
                break;
            }
            default: {
                break;
            }
        }
    }
    return 0;
}

/* 
样例输入 Sample Input
4
M 2 3
C 1 2
M 2 4
C 4 2
样例输出 Sample Output
-1
1
*/
