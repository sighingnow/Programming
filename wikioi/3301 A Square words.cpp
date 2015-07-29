#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//wikioi: 3301,LCS

int main(int argc, char **argv)
{
    int len, ans = 0, dp[510][510];
    char s[510] = {'\0'};
    scanf("%d %s", &len, s);
    for(int r = 1; r < len; ++r)
    {
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= r; ++i)
        {
            for(int j = r + 1; j <= len; ++j)
            {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                if(s[i-1] == s[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                ans = max(ans, dp[i][j]);
            }
        }
    }
    cout << len - 2 * ans;

    return 0;
}
