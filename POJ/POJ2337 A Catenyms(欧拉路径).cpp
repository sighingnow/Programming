#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge {
    char str[25];
    int start, end, len;
    bool used;
};

const int maxn = 1005;
Edge edge[maxn];
int T, n, path[maxn], p = 0;
int in[27] = {0}, out[27] = {0};

bool cmp(const Edge & a, const Edge & b) {
    return strcmp(a.str, b.str) <= 0 ? true : false;
}

void dfs(int s) {
    for(int i = 0; i < n; ++i) {
        if(!edge[i].used && edge[i].start == s) {
            edge[i].used = true;
            dfs(edge[i].end);
            path[p++] = i;
        }
    }
}

int main(int argc, char** args) {
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n); p = 0;
        memset(path, 0x00, sizeof(path)); memset(edge, 0x00, sizeof(edge));
        memset(in, 0x00, sizeof(in)); memset(out, 0x00, sizeof(out));
        for(int i = 0; i < n; ++i) {
            scanf("%s", edge[i].str); edge[i].len = strlen(edge[i].str);
            edge[i].start = edge[i].str[0]-'a'; edge[i].end = edge[i].str[edge[i].len-1]-'a';
            edge[i].used = false;
        }
        sort(edge, edge+n, cmp);
        for(int i = 0; i < n; ++i) {
            out[edge[i].start]++;
            in[edge[i].end]++;
        }
        int start = edge[0].start, incnt = 0, outcnt = 0, flag = 0;
        for(int i = 0; i < 26; ++i) {
            if(in[i] == out[i]) {
                continue;
            }
            else if(in[i]-1 == out[i]) {
                incnt++;
            }
            else if(out[i]-1 == in[i]) {
                outcnt++; start = i;
            }
            else {
                flag = 1; break;
            }
        }
        if(flag == 0 && (incnt==1&&outcnt==1 || incnt==0&&outcnt==0)) {
            p = 0; dfs(start);
            if(p < n) {
                printf("***\n"); continue; // no euler path.
            }
            for(int i = p-1; i > 0; --i) {
                printf("%s.", edge[path[i]].str);
            }
            printf("%s\n", edge[path[0]].str);
        }
        else {
            printf("***\n"); continue; // no euler path.
        }
    }

    return 0;
}

