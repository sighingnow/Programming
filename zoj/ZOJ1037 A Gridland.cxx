#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

//ZOJ 1037

int main(int argc, char **argv)
{
    int t, m, n;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> m >> n;
        printf("Scenario #%d:\n", i);
        if(m % 2 == 0 || n % 2 == 0)
            printf("%.2f\n\n", (float)(m * n));
        else
            printf("%.2f\n\n", (float)(m * n - 1) + sqrt(2));
    }
    
    return 0;
}
