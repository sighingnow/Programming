#include <cstdio>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int n, m;
int num[20];
int vis[6005];

struct Item {
    int mod;
    string ans;
};

string bfs() {
    queue <Item> Q;
    for(int i = 1; i <= m; ++i) {
        Item ss;
        ss.ans += char('0'+num[i]);
        ss.mod = num[i];
        Q.push(ss);
    }
    while(!Q.empty()) {
        Item it = Q.front();
        Q.pop();
        if(it.ans == "0") {
            continue;
        }
        if(it.mod == 0) {
            return it.ans;
        }
        if(vis[it.mod] == 1) {
            continue;
        }
        vis[it.mod] = 1;

        for(int i = 1; i <= m; ++i) {
            Item t;
            t.ans = it.ans + char('0'+num[i]);
            t.mod = (it.mod * 10 + num[i]) % n;
            if(vis[t.mod]) {
                continue;
            }
            Q.push(t);
        }
    }
    return "0";
}

int main(int argc, char **argv) {

    while(scanf("%d %d", &n, &m) == 2) {
        memset(vis, 0x00, sizeof(vis));
        for(int i = 1; i <= m; ++i) {
            scanf("%d", &num[i]);
        }
        if(n == 0) {
            printf("0\n");
            continue;
        }
        sort(num+1, num+1+m);
        cout << bfs() << endl;
    }

    return 0;
}
