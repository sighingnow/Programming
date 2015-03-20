#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * Author: buaahetao@gmail.com
 */

bool solve() {
    int n, m, s, t, todo;
    vector<int> edge[10005];
    queue<int> Q;
    bool flag[10005] = {false};
    int color[10005] = {0};
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d", &s, &t);
        edge[s].push_back(t); edge[t].push_back(s);
    }
    for(int i = 1; i <= n; ++i) {
        if(!flag[i]) {
            Q.push(i); color[i] = 1; flag[i] = true;
        }
        while(!Q.empty()) {
            int k = Q.front();
            Q.pop(); todo = color[k] * -1;
            if(edge[k].size() > 0) {
                for(int i = 0; i < edge[k].size(); ++i) {
                    int r = edge[k][i];
                    if(!flag[r]) {
                        flag[r] = true;
                        color[r] = todo;
                        Q.push(r);
                    }
                    if (flag[r] && color[r] == todo) {
                        continue;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main(int argc, char **argv) 
{
    int T;
    scanf("%d", &T);
    while(T--) {
        if(solve()) {
            printf("Correct\n");
        }
        else {
            printf("Wrong\n");
        }
    }

    return 0;
}

/* vim: set ts=4, sw = 4 */

