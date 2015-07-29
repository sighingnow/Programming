#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x7fffffff;
const int max_m = 205;
int map[max_m][max_m];
int m, n;
int path[max_m];
int flow[max_m]; //标记从源点到当前节点实际还剩多少流量可用

int bfs(int start, int end) {
    queue <int> Q;
    memset(path, 0xff, sizeof(path));
    path[start] = 0; // previrous node.
    flow[start] = INF;
    Q.push(start);
    while(!Q.empty()) {
        int t = Q.front();
        Q.pop();
        if(t == end) {
            break;
        }
        for(int i = 1; i <= m; ++i) {
            if(i != start && path[i] == -1 && map[t][i]) {
                flow[i] = flow[t] < map[t][i] ? flow[t] : map[t][i];
                Q.push(i);
                path[i] = t;
            }
        }
    }
    if(path[end] == -1) { // No augmenting path. 
        return -1;
    }
    else {
        return flow[end];
    } 
}

int Edmonds_Karp(int start, int end) {
    int max_flow = 0;
    int step; //每一步bfs得到的流量
    int now, pre;
    while((step = bfs(start, end)) != -1) {
        max_flow += step;
        now = end;
        while(now != start) {
            pre = path[now];
            map[pre][now] -= step;
            map[now][pre] += step;
            now = pre;
        }
    }
    return max_flow;
}

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    int a, b, cost;
    while(~scanf("%d %d", &n, &m)) {
        memset(map, 0x00, sizeof(map));
        for(int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &a, &b, &cost);
            map[a][b] += cost;
        }
        printf("%d\n", Edmonds_Karp(1, m));
    }
    
    return 0;
}

