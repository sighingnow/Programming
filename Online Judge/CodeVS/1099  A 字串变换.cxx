#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

//wikioi 1099

string queue[1000000];
int step[1000000];
map<string, int>M;

void find(string s, string t, int pos[])
{
    pos[0] = 0;
    int start = 0;
    while(start < (int)(s.length()))
    {
        int ans = s.find(t, start);
        if(ans == int(s.npos))
            break;
        else
        {
            pos[++pos[0]] = ans;
            start = ans + 1;
        }
    }
}

bool hash(string s)
{
    map<string, int>::iterator it = M.find(s);
    if(it != M.end())
        return true;
    else
    {
        M.insert(map<string, int> :: value_type(s, 1));
        return false;
    }
}

int main(int argc, char **argv)
{
    string src[25], des[25];
    char s[25], t[25];
    int cnt = 0;
    while(scanf("%s %s", s, t) == 2)
    {
        src[cnt] = string(s);
        des[cnt] = string(t);
        cnt++;
    }
    int tail = 0, top = 1;
    int pos[1000];
    queue[0] = src[0];
    while(tail < top)
    {
        if(queue[tail] == des[0])
        {
            cout << step[tail];
            return 0;
        }
        if(step[tail] < 10)
        {
            for(int i = 1; i < cnt; ++i)
            {
                find(queue[tail], src[i], pos);
                if(pos[0])
                {
                    for(int j = 1; j <= pos[0]; ++j)
                    {
                        queue[top++] = queue[tail];
                        step[top-1] = step[tail] + 1;
                        queue[top-1].replace(pos[j], src[i].length(), des[i]);
                        if(hash(queue[top-1]))
                            top--;
                    }
                }
            }
        }
        tail++;
    }
    cout << "NO ANSWER!";
    return 0;
}

