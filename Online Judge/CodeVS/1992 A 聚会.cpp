#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//wikioi:1992

#define INF 0x3fffffff

int n;
int map[1005][1005];

void init(int m)
{
    for(int i = 0; i < 1005; ++i)
    {
        for(int j = 0; j < 1005; j++)
            map[i][j] = INF;
        map[i][i] = 0;
    }
    for(int i = 1; i <= m; ++i)
    {
        int u, v, len;
        scanf("%d %d %d", &u, &v, &len);
        if(map[u][v] >= len)
        {
            map[u][v] = len;
        }
    }
}

void floyd()
{
    for(int k = 1; k <= n; ++k)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
}

int main(int argc, char **argv)
{
    int m, k;
    scanf("%d %d %d", &n, &m, &k);
    init(m);
    floyd();
    int max = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(map[i][k] + map[k][i] < INF && max < map[i][k] + map[k][i])
            max = map[i][k] + map[k][i];
    }
    printf("%d\n", max);
    return 0;
}

