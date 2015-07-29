#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

//wikioi 3285

int quickpow(int x, int y, int n)
{
    int tem = 1, ret = x;
    while(y > 0)
    {
        if(y & 1)
            tem = ((tem % n) * (ret % n)) % n;
        ret = ((ret % n) * (ret % n)) % n;
        y >>= 1;
    }
    return tem;
}

int main(int argc, char **argv)
{
    int n, m, k, x;
    long long ans;
    cin >> n >> m >> k >> x;
    ans = (((quickpow(10, k, n) * m) % n) + x) % n;
    cout << ans;
    
    return 0;
}
