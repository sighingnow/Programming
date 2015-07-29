#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

//wikioi 1226

const int MAXN = 110;
int a, b, z, f[MAXN][MAXN];
struct cup
{
    int x, y;
    int sol; //量出的水量
    int step; //到水的次数
}first, now;
queue<cup>Q;

void extend(cup in)
{
    if(f[in.x][in.y] != 0)
        return;
    f[in.x][in.y]++;
    in.step++;
    
    cup p = in;
    p.x = a;
    Q.push(p);
    
    p = in;
    p.y = b;
    Q.push(p);
    
    p = in;
    p.x = 0;
    Q.push(p);
    
    p = in;
    p.y = 0;
    Q.push(p);
    
    p = in;
    if(in.x + in.y <= a)
    {
        p.x = in.x + in.y;
        p.y = 0;
        Q.push(p);
    }
    else
    {
        p.x = a;
        p.y = in.x + in.y - a;
        Q.push(p);
    }
    
    p = in;
    
    if(in.x + in.y <= b)
    {
        p.y = in.x + in.y;
        p.x = 0;
        Q.push(p);
    }
    else
    {
        p.y = b;
        p.x = in.x + in.y - b;
        Q.push(p);
    }
}

void bfs()
{
    Q.push(first);
    while(!Q.empty())
    {
        now = Q.front();
        Q.pop();
        if(now.x == z || now.y == z)
        {
            printf("%d\n", now.step);
            return;
        }
        extend(now);
    }
    printf("impossible\n");
}

int main(int argc, char **argv)
{
    cin >> a >> b >> z;
    first.step = 0;
    first.x = first.y = 0;
    bfs();
    return 0;
}
