#include <cstdio>
#include <cstring>
using namespace std;

int n, ans;
char city[5][5];
bool vis[20];

void init() {
    memset(city, 0x00, sizeof(city));
    memset(vis, 0x00, sizeof(vis));
    ans = 0;
}

bool judge(int point) {
    int row = point / n, col = point % n, tmp;
    if(city[row][col] == 'X') {
        return false;
    }
    
    tmp = col;
    while(tmp >= 0 && city[row][tmp] != 'X' && !vis[row*n+tmp]) {
        tmp--;
    }
    if(tmp >= 0 && vis[row*n+tmp]) {
        return false;
    }
    
    tmp = row;
    while(tmp >= 0 && city[tmp][col] != 'X' && !vis[tmp*n+col]) {
        tmp--;
    }
    if(tmp >= 0 && vis[tmp*n+col]) {
        return false;
    }
    
    return true;
}

void dfs(int point) {
    if(point == n * n) {
        int tmp = 0;
        for(int i = 0; i < n*n; ++i) {
            if(vis[i]) {
                tmp++;
            }
        }
        ans = ans >= tmp ? ans : tmp;
        return;
    }

    if(judge(point)) {
        vis[point] = true;
        dfs(point+1);
        vis[point] = false;
    }
    dfs(point+1);
}

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    while(scanf("%d", &n) && n) {
        init();
        for(int i = 0; i < n; ++i) {
            scanf("%s", city[i]);
        }
        dfs(0);
        printf("%d\n", ans);
    }
}
