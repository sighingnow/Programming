#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
/**
 * Author: buaahetao@gmail.com
 */

vector<int> edge[1005];

bool dfs(int t, bool *isVisit, int *link)
{
    if(edge[t].size() > 0) {
	    for(int i = 0; i < edge[t].size(); ++i) {
            int b = edge[t][i];
		    if(!isVisit[b]) {
			    isVisit[b] = 1;
		    	if(link[b] == -1 || dfs(link[b], isVisit, link)) {
				    link[b] = t;
				    return true;
			    }
		    }
	    }
    }
	return false;
}

int main(int argc, char **argv) 
{
    int n, m, s, t, ans = 0;
    bool isVisit[1005];
    int link[1005];
    memset(link, 0xff, sizeof(link[0])*1005);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d %d", &s, &t);
        edge[s].push_back(t); edge[t].push_back(s);
    }
    for(int i = 1; i <= n; ++i) {
        memset(isVisit, 0x00, sizeof(isVisit[0])*1005);
        if(dfs(i, isVisit, link)) {
            ans++;
        }
    }
    printf("%d", ans/2);
    return 0;
}

/* vim: set ts=4, sw = 4 */

