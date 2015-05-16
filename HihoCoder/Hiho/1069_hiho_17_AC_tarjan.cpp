#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int v, lca;
    Node() {this->lca = -1;}
    Node(int v, int lca = -1) {
        this->v = v;
        this->lca = lca;
    } 
};

map<string, int> people;
map<int, string> p;
int n, m, cnt = 0, ancestor[100005], root[100005], rank[100005] = {0};
bool flag[100005] = {false};
vector<int> links[100005];
vector<Node> query[100005];
vector<pair<int, int> > Q;

int findset(int x) {
    if(x != root[x]) {
        root[x] = findset(root[x]);
    }
    return root[x];
}

void unionset(int a, int b) {
    if((a = findset(a)) == (b = findset(b))) {
        return;
    }
    if(rank[a] > rank[b]) {
        root[b] = a;
    }
    else {
        root[a] = b;
    }
    if(rank[a] == rank[b]) {
        rank[b]++;
    }
}

void tarjan(int u) {
    root[u] = u;
    ancestor[findset(u)] = u;
    if(links[u].size() > 0) {
        for(int i = 0; i < links[u].size(); ++i) {
            int v = links[u][i];
            tarjan(v);
            unionset(u, v);
            ancestor[findset(u)] = u;
        }
    }
    flag[u] = true;
    if(query[u].size() > 0) {
        for(int i = 0; i < query[u].size(); ++i) {
            if(flag[query[u][i].v]) {
                query[u][i].lca = ancestor[findset(query[u][i].v)];
            }
        }
    }
}

int main(int argc, char **argv) {
    string father, son;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        cin >> father >> son;
        if(people[father] == 0) {
            people[father] = ++cnt;
            p[cnt] = father;
        }
        if(people[son] == 0) {
            people[son] = ++cnt;
            p[cnt] = son;
        }
        links[people[father]].push_back(people[son]);
        flag[people[son]] = true;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        cin >> father >> son;
        Q.push_back(pair<int, int>(people[father], people[son]));
        query[people[father]].push_back(Node(people[son]));
        query[people[son]].push_back(Node(people[father]));
    }
    int u = 0;
    for(int i = 1; i <= cnt; ++i) {
        if(!flag[i]) {
            u = i;
            break;
        }
    }
    memset(flag, 0x00, sizeof(flag));
    tarjan(u);
    for(int j = 0; j < m; ++j) {
        int a = Q[j].first, b = Q[j].second, mark = 0;
        for(int i = 0; i < query[a].size(); ++i) {
            if(query[a][i].v == b && query[a][i].lca != -1) {
                cout << p[query[a][i].lca] << endl;
                mark = 1;
                break;
            }
        }
        if(mark == 1) {
            continue;
        }
        for(int i = 0; i < query[b].size(); ++i) {
            if(mark == 0 && query[b][i].v == a && query[b][i].lca != -1) {
                cout << p[query[b][i].lca] << endl;
                break;
            }
        }
    }
    return 0;
}

