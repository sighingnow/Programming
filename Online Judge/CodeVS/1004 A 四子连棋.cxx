#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//wikioi:1004

char map[100000][5][5];
int step[100000];
bool order[100000];
int head, tail;

bool judge(char s[][5])
{
    for(int i = 1; i <= 4; ++i)
    {
        if(s[i][1] == s[i][2] && s[i][2] == s[i][3] && s[i][3] == s[i][4])
            return true;
        if(s[1][i] == s[2][i] && s[2][i] == s[3][i] && s[3][i] == s[4][i])
            return true;
    }
    if(s[1][1] == s[2][2] && s[2][2] == s[3][3] && s[3][3] == s[4][4])
        return true;
    if(s[1][4] == s[2][3] && s[2][3] == s[3][2] && s[3][2] == s[4][1])
        return true;
    return false;
}

int solve(bool flag)
{
    head = 0, tail = 1;
    order[0] = flag;
    step[0] = 0;
    while(head < tail)
    {
        if(judge(map[head]))
            return step[head];

        for(int i = 1; i <= 4; ++i)
        {
            for(int j = 1; j <= 4; ++j)
            {
                if(map[head][i][j] == 'O')
                {
                    if(i > 1 && ((map[head][i-1][j] == 'B' && order[head] == true) || (map[head][i-1][j] == 'W' && order[head] == false)))
                    {
                        memcpy(map[tail++], map[head], sizeof(map[0])/sizeof(char));
                        swap(map[tail-1][i][j], map[tail-1][i-1][j]);
                        step[tail-1] = step[head] + 1;
                        order[tail-1] = !order[head];
                    }
                    if(j > 1 && ((map[head][i][j-1] == 'B' && order[head] == true) || (map[head][i][j-1] == 'W' && order[head] == false)))
                    {
                        memcpy(map[tail++], map[head], sizeof(map[0])/sizeof(char));
                        swap(map[tail-1][i][j], map[tail-1][i][j-1]);
                        step[tail-1] = step[head] + 1;
                        order[tail-1] = !order[head];
                    }
                    if(i < 4 && ((map[head][i+1][j] == 'B' && order[head] == true) || (map[head][i+1][j] == 'W' && order[head] == false)))
                    {
                        memcpy(map[tail++], map[head], sizeof(map[0])/sizeof(char));
                        swap(map[tail-1][i][j], map[tail-1][i+1][j]);
                        step[tail-1] = step[head] + 1;
                        order[tail-1] = !order[head];
                    }
                    if(j < 4 && ((map[head][i][j+1] == 'B' && order[head] == true) || (map[head][i][j+1] == 'W' && order[head] == false)))
                    {
                        memcpy(map[tail++], map[head], sizeof(map[0])/sizeof(char));
                        swap(map[tail-1][i][j], map[tail-1][i][j+1]);
                        step[tail-1] = step[head] + 1;
                        order[tail-1] = !order[head];
                    }
                }
            }
        }
        head++;
    }
}

int main(int argc, char **argv)
{
    for(int i = 1; i <= 4; ++i)
        scanf("%s", map[0][i] + 1);
    int ans1 = solve(true);
    int ans2 = solve(false);
    printf("%d\n", min(ans1, ans2));
    return 0;
}
