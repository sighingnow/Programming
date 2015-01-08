#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int max_n = 100005;
const int max_m = 1000005;
int n, m, start, end;

struct Edge {
    int next;
    int weight;
    Edge() {    }
    Edge(int next, int weight) {
        this->next = next;
        this->weight = weight;
    }
};

vector <Edge> links[max_n];
int dist[max_n];
bool vis[max_n];

const int INF = 0x3fffffff;

int spfa() {
    for(int i = 0; i <= n; ++i) {
        dist[i] = INF;
        vis[i] = false;
    }
    dist[start] = 0;
    vis[start] = true;
    queue <int> Q;
    Q.push(start);
    while(!Q.empty()) {
        int tmp = Q.front();
        Q.pop();
        int s = links[tmp].size();
        if(s > 0) {
            for(int i = 0; i < s; ++i) {
                int len = links[tmp][i].weight;
                int t = links[tmp][i].next;
                if(dist[tmp] + len < dist[t]) {
                    dist[t] = dist[tmp] + len;
                    if(!vis[t]) {
                        Q.push(t);
                        vis[t] = true;
                    }
                }
            }
        }
        vis[tmp] = false;
    }

    return dist[end];
}

int main(int argc, char **argv) {
    int x, y, len;
    scanf("%d %d %d %d", &n, &m, &start, &end);
    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &len);
        links[x].push_back(Edge(y, len));
        links[y].push_back(Edge(x, len));
    }

    printf("%d", spfa());

    return 0;
}
