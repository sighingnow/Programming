#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

//wikioi 1225

int grid[362881][3][3];
long long aim = 1 + 2*10 + 3*100 + 8*1000 + 0*10000 +  4*100000 + 7*1000000 + 6*10000000 + 5*100000000;
map<long long, long long>M;
int step[362881];

bool check(int g[][3])
{
    long long num = g[0][0] + g[0][1]*10 + g[0][2]*100 + g[1][0]*1000 + g[1][1]*10000 + 
                g[1][2]*100000 + g[2][0]*1000000 + g[2][1]*10000000 + g[2][2]*100000000;
    if(num == aim)
        return true;
    else
        return false;
}

bool isVisit(int g[][3])
{
    long long num = g[0][0] + g[0][1]*10 + g[0][2]*100 + g[1][0]*1000 + g[1][1]*10000 + 
              g[1][2]*100000 + g[2][0]*1000000 + g[2][1]*10000000 + g[2][2]*100000000;
    map<long long, long long>::iterator it = M.find(num);
    if(it != M.end())
    {
        return true;
    }
    else
    {
        M.insert(map<long long, long long> :: value_type(num, num));
        return false;
    }
}

void find_0(int & x, int & y, int g[][3])
{
    for(x = 0; x < 3; x++)
    {
        for(y = 0; y < 3; ++y)
            if(g[x][y] == 0)
                return;
    }
}

void arrcpy(int des[][3], int src[][3])
{
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
            des[i][j] = src[i][j];
    }
}

int main(int argc, char **argv)
{
    int tail = 0, top = 1;
    char start[10];
    scanf("%s", start);
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            grid[0][i][j] = start[3 * i + j] - '0';
    int x = 0, y = 0;
    int tmp[3][3];
    while(tail < top)
    {   
        if(check(grid[tail]))
        {
            printf("%d", step[tail]);
            return 0;
        }
        find_0(x, y, grid[tail]);
        if(x > 0)
        {
            arrcpy(tmp, grid[tail]);
            swap(tmp[x][y], tmp[x-1][y]);
            if(!isVisit(tmp))
            {
                arrcpy(grid[top++], tmp);
                step[top-1] = step[tail] + 1;
            }
        }
        if(x < 2)
        {
            arrcpy(tmp, grid[tail]);
            swap(tmp[x][y], tmp[x+1][y]);
            if(!isVisit(tmp))
            {
                arrcpy(grid[top++], tmp);
                step[top-1] = step[tail] + 1;
            }
        }
        if(y > 0)
        {
            arrcpy(tmp, grid[tail]);
            swap(tmp[x][y], tmp[x][y-1]);
            if(!isVisit(tmp))
            {
                arrcpy(grid[top++], tmp);
                step[top-1] = step[tail] + 1;
            }
        }
        if(y < 2)
        {
            arrcpy(tmp, grid[tail]);
            swap(tmp[x][y], tmp[x][y+1]);
            if(!isVisit(tmp))
            {
                arrcpy(grid[top++], tmp);
                step[top-1] = step[tail] + 1;
            }
        }
        tail ++;
    }
    
    return 0;
}

