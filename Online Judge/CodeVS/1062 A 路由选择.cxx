#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//wikioi:1062

int n, s, t, M;
int map[35][35];

void init()
{
    scanf("%d %d %d %d", &n, &s, &t, &M);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; j++)
            scanf("%d", &map[i][j]);
    }
}

void dijkstra(int path[], int & len)
{
    bool isVisit[35];
    int prev[35] = {0};
    int d[35] = {0};
    for(int i = 1; i <= n; ++i)
    {
        d[i] = map[s][i];
        isVisit[i] = false;
        if(map[s][i] == M)
            prev[i] = 0;
        else
            prev[i] = s;
    }
    d[s] = 0;
    isVisit[s] = true;
    for(int i = 2; i <= n; ++i)
    {
        int u = s;
        int min = M;
        for(int j = 1; j <= n; j++)
        {
            if(!isVisit[j] && d[j] <= min)
            {
                u = j;
                min = d[j];
            }
        }
        isVisit[u] = true;
        for(int j = 1; j <= n; ++j)
        {
            if(!isVisit[j] && map[u][j] <= M)
            {
                if(map[u][j] + d[u] <= d[j])
                {
                    d[j] = map[u][j] + d[u];
                    prev[j] = u;
                }
            }
        }
    }
    int i = t;
    while(prev[i] != s)
    {
        path[++path[0]] = i;
        i = prev[i];
    }
    path[++path[0]] = i;
    path[++path[0]] = s;
    len = d[t];
}

void showPath(int num, int len[], int path[][35])
{
    for(int i = 1; i <= num; ++i)
    {
        printf("%d ", len[i]);
        for(int j = path[i][0]; j >= 1; --j)
            printf("%d ", path[i][j]);
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    init();
    int path[4][35] = {{0}};
    int len[4] = {0};
    dijkstra(path[1], len[1]);
    len[2] = M;
    for(int i = path[1][0]; i > 1; --i)
    {
        int tmpPath[35];
        int tmpLen;
        int tmp = map[path[1][i]][path[1][i-1]];
        map[path[1][i]][path[1][i-1]] = M;
        memset(tmpPath, 0, sizeof(tmpPath));
        dijkstra(tmpPath, tmpLen);
        if(tmpLen < len[2])
        {
            len[2] = tmpLen;
            for(int i = 0; i <= tmpPath[0]; ++i)
                path[2][i] = tmpPath[i];
        }
        map[path[1][i]][path[1][i-1]] = tmp;
    }
    
    len[3] = M;
    for(int i = path[1][0]; i > 1; --i)
    {
        int tmp1 = map[path[1][i]][path[1][i-1]];
        map[path[1][i]][path[1][i-1]] = M;
        for(int j = path[2][0]; j > 1; --j)
        {
            int tmpPath[35];
            int tmpLen;
            int tmp2 = map[path[2][j]][path[2][j-1]];
            map[path[2][j]][path[2][j-1]] = M;
            memset(tmpPath, 0, sizeof(tmpPath));
            dijkstra(tmpPath, tmpLen);
            if(tmpLen < len[3])
            {
                len[3] = tmpLen;
                for(int i = 0; i <= tmpPath[0]; ++i)
                    path[3][i] = tmpPath[i];
            }
            map[path[2][j]][path[2][j-1]] = tmp2;
        }
        map[path[1][i]][path[1][i-1]] = tmp1;
    }
    
    showPath(3, len, path);
    
    return 0;
}
