#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//wikioi:2755

int main(int argc, char **argv)
{
    int n, i, j, x;
    int ans = 0;
    double y;
    cin >> n;
    for(i = 1; i <= n; ++i)
    {
        cin >> y >> x;
        for(j = 1; j <= x; ++j)
        {
            ans ^= (int)(y * j);
        }
    }
    printf("%d", ans);
    return 0;
}
