#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//wikioi:1040

int p, k, m;
char str[250];
int lenS, len[7];
char dict[7][250];
int word[205][205];
int dp[205][205][41];


void solve()
{
    scanf("%d %d", &p, &k);
    memset(str, 0, sizeof(str));
    for(int i = 0; i < p; ++i)
        scanf("%s", str + 20 * i);
    lenS = strlen(str);
    cin >> m;
    for(int i = 1; i <= m; ++i)
    {
        scanf("%s", dict[i]);
        len[i] = strlen(dict[i]);
    }
    for(int i = 0; i <= lenS; ++i)
    {
        for(int j = 0; j <= lenS; ++j)
            word[i][j] = 0;
    }
    for(int i = lenS - 1; i >= 0; --i)
    {
        for(int j = lenS - 1; j >= 0; --j)
        {
            bool yes = false;
            for(int s = 0; s <= m; ++s)
            {
                if(str[j] == dict[s][0] && len[s] <= i-j+1)
                {
                    yes = true;
                    for(int t = 0; t < len[s]; ++t)
                    {
                        if(str[j+t] != dict[s][t])
                        {
                            yes = false;
                            break;
                        }
                    }
                }
                if(yes) 
                    break;
            }
            if(yes)
                word[j][i] = word[j+1][i] + 1;
            else
                word[j][i] = word[j+1][i];
        }
    }
    for(int s = 1; s <= k; ++s)
    {
        for(int i = 0; i < lenS - s + 1; ++i)
        {
            for(int j = i + s - 1; j < lenS; ++j)
            {
                if(s == 1)
                {
                    dp[i][j][s] = word[i][j];
                    continue;
                }
                int max, l;
                for(max = 0, l = i + s - 2; l < j; ++l)
                {
                    if(max < dp[i][l][s-1] + word[l+1][j])
                        max = dp[i][l][s-1] + word[l+1][j];
                }
                dp[i][j][s] = max;
            }
        }
    }
    printf("%d\n", dp[0][lenS-1][k]);
}

int main(int argc, char **argv)
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        solve();
    return 0;
}

