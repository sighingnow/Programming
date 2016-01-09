#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node {
    int x;
    int t;
    Node() {    }
    Node(int x, int t) {
        this->x = x;
        this->t = t;
    }
};

vector<Node> a[1000100];
int n,m;
int in[1000100],out[1000100],end[1000100];
int price[1000100];
queue<int> q;
//找关键路径长度

int main(int argc, char **argv) {
    while(scanf("%d %d", &n, &m)==2) {
        int ans=0;
        for(int i=1;i<=n;i++) {
            a[i].clear();
            in[i]=0;
            out[i] = 0;
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &price[i]);
        }
        while(m--) {
            int u, t;
            scanf("%d%d",&u,&t);
            a[u].push_back(Node(t, price[u]));
            in[t]++;
            out[u]++;
        }
        for(int i = 1; i <= n; ++i) {
            if(in[i] != 0 && out[i] == 0) {
                a[i].push_back(Node(n+1, price[i]));
                in[n+1]++;
                out[i]++;
            }
        }
        while(!q.empty()) {
            q.pop();
        }

        memset(end,0,sizeof(end));

        for(int i = 1; i <= n; i++) {
            if(in[i]==0) {
                if(out[i] != 0) {
                    end[i] = 0;
                    q.push(i);
                }
                else {
                    ans = max(ans, price[i]);
                }
            }
        }
        while(!q.empty()) {
            int u=q.front();q.pop();
            for(int i=0;i<a[u].size();i++) {
                int x=a[u][i].x,t=a[u][i].t;
                end[x]=max(end[x],end[u]+t);
                in[x]--;
                if(in[x]==0) {
                    q.push(x);
                }
            }
        }
        for(int i=1;i<=n+1;i++) {
            ans=max(ans,end[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}