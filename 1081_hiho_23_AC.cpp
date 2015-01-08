#include <cstdio>
#include <vector>
using namespace std;

struct Edge {
    int next, weight;
    Edge() {    }
    Edge(int next, int weight) {
        this->next = next;
        this->weight = weight;
    }
};

vector <Edge> links[1005];
int n, m, start, end;
int dist[1005];
bool vis[1005];
const int INF = 0x3fffffff;

int dijkstra() {
    for(int i = 0; i < 1005; ++i) {
        vis[i] = false;
        dist[i] = INF;
    }
    dist[start] = 0;
    for(int i = 1; i <= n; ++i) {
        int k = INF, u = start;
        for(int j = 1; j <= n; ++j) {
            if(!vis[j] && dist[j] < k) {
                k = dist[j];
                u = j;
            }
        }
        int s = links[u].size();
        if(s > 0) {
            for(int j = 0; j < s; ++j) {
                Edge v = links[u][j];
                if(dist[v.next] > dist[u] + v.weight) {
                    dist[v.next] = dist[u] + v.weight;
                }
            }
        }
        vis[u] = true;
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
    printf("%d", dijkstra());

    return 0;
}

