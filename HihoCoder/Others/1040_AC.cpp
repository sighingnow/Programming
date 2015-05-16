#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

/**
 * Author: buaahetao@gmail.com, SCSE, BUAA
 */

typedef pair<int, int> node;
int edge[5][5];
int mark[5][2];

int abs(int a) {
    if(a >= 0) {
        return a;
    }
    else {
        return -a;
    }
}

bool if_vertical(int a, int b) {
    if((edge[a][3]-edge[a][1])*(edge[b][3]-edge[b][1])+(edge[a][4]-edge[a][2])*(edge[b][4]-edge[b][2]) == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool if_parallel(int a, int b) {
    if(abs((edge[a][3]-edge[a][1])*(edge[b][4]-edge[b][2])) == abs((edge[b][3]-edge[b][1])*(edge[a][4]-edge[a][2]))) {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char *argv[])
{
	int T;
    bool judge;
    map<node, int> count;
    scanf("%d", &T);
    while(T--) {
        count.clear();
        judge = true;
        memset(mark, 0x00, sizeof(mark));
        for(int i = 1; i <= 4; ++i) {
            scanf("%d%d%d%d", &edge[i][1], &edge[i][2], &edge[i][3], &edge[i][4]);
            count[node(edge[i][1], edge[i][2])] += 1;
            count[node(edge[i][3], edge[i][4])] += 1;
        }
        if(count.size() != 4) {
            judge = false;
        }
        for(map<node, int>::iterator it = count.begin(); it != count.end(); ++it) {
            if(it->second != 2) {
                judge = false;
                break;
            }
        }
        for(int i = 1; i <= 4; ++i) {
            for(int j = 1; j <= 4; ++j) {
                if(if_vertical(i, j)) {
                    mark[i][0] += 1;
                }
                else if(if_parallel(i, j)) {
                    mark[i][1] += 1;
                }
            }
            if(mark[i][0] != 2 || mark[i][1] != 2) {
                judge = false;
                break;
            }
        }
        if(judge) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
	return 0;
}

/* vim: set ts=4, sw = 4 */


