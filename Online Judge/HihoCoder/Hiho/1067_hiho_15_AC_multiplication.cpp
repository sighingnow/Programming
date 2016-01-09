#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

map<string, int> people;
map<int, string> p;
int n, m, cnt = 0, parent[100005][21] = {{0}}, depth[100005] = {0};
bool flag[100005] = {false};
vector<int> links[100005];

void dfs(int a) {
    if(links[a].size() > 0) {
        for (int i = 0; i < links[a].size(); ++i) {
            int b = links[a][i];
            depth[b] = depth[a] + 1;
            dfs(b);
        }
    }
}

int query(int a, int b) {
    if(depth[a] > depth[b]) {
        swap(a, b);
    }
    for(int i = 20; i >= 0; --i) {
        if(depth[parent[b][i]] >= depth[a]) {
            b = parent[b][i];
        }
    }
    if(a == b) {
        return a;
    } 
    for(int i = 20; i >= 0; --i) {
        if(parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
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
        parent[people[son]][0] = people[father];
    }
    for(int i = 1; i <= 20; ++i) {
        for(int j = 1; j <= cnt; ++j) {
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        if(!flag[i]) {
            depth[i] = 1;
            dfs(i);
            break;
        }
    }
    /* for(map<string, int>::iterator iter = people.begin(); iter != people.end(); iter ++ ) {
        cout << iter->first << iter -> second << endl;
    } */
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i) {
        cin >> father >> son;
        cout << p[query(people[father], people[son])] << endl;
    }

    /* for(map<string, int>::iterator iter = people.begin(); iter != people.end(); iter ++ ) {
        cout << iter->first << iter -> second << endl;
    } */
    return 0;
}

