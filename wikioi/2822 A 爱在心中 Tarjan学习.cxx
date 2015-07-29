#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
//wikioi:2822

const int MAXN = 1010, MAXE = 10010;
int ans = 0, nn = 0;
int p[MAXN];//p[i]表示第i个节点所在的强连通分量 
int sum[MAXN];
int DFN[MAXN], LOW[MAXN], FT = 0;//定义DFN(u)为节点u搜索的次序编号(时间戳)，Low(u)为u或u的子树能够追溯到的最早的栈中节点的次序号。
int head[MAXN], u[MAXN], v[MAXE], next[MAXE];
bool map[MAXN][MAXN];
int n, m;

stack<int>S;
bool vis[MAXN];

void Tarjan(int r)
{
    DFN[r] = LOW[r] = ++FT;
    S.push(r);
    vis[r] = true;
    for(int i = head[r]; i; i = next[i])
    {
        if(!DFN[v[i]])
        {
            Tarjan(v[i]);
            LOW[r] = min(LOW[r], LOW[v[i]]);
        }
        else if(vis[v[i]])
            LOW[r] = min(LOW[r], DFN[v[i]]);
    }
    if(DFN[r] == LOW[r])
    {
        int t = S.top();
        S.pop();
        p[t] = ++nn;
        sum[nn] = 1;
        vis[t] = 0;
        if(t != r)//不是本节点，即有连通的
        {
            ans++;
            while(r != t)
            {
                t = S.top();
                S.pop();
                sum[nn]++;
                p[t] = nn;
                vis[t] = 0;
            }
        }
    }
}

int main(int argc, char **argv)
{
    cin >> n >> m;
    //此题中图的实现使用的是链式前向星
    for(int i = 1; i <= m; ++i)
    {
        cin >> u[i] >> v[i];
        next[i] = head[u[i]];
        head[u[i]] = i;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!DFN[i])
            Tarjan(i);
    }
    cout << ans << endl;//输出天使的数目
    
    for(int i = 1; i <= m; ++i)
        map[p[u[i]]][p[v[i]]] = 1;
    
    //Floyd，判断连通图（数据小，能过）
    for(int k = 1; k <= nn; k++)
        for(int i = 1; i <= nn; i++)
            for(int j = 1; j <= nn; j++)
                if(i != j && map[i][k] && map[k][j]) //此处必须2条路都通，即i->k && k->j
                    map[i][j] = 1;
    int ok = 1, no = 1;
    for(int i = 1; i <= nn; i++)
    {
        if(sum[i] == 1) 
            continue;
        ok = 1;
        for(int j = 1; j <= nn; j++) //看看每一个节点是否通i，因为前面初始化边时有本身，所以不用判断是否一条边
            if(!map[j][i])
                ok = 0;
        if(ok)
        {
            no = 0;
            for(int j = 1; j <= n; j++)
                if(p[j] == i)
                    cout << j << ' ';
            cout << endl;
        }
    }
    if(no) 
        cout << "-1\n";

    return 0;
}

