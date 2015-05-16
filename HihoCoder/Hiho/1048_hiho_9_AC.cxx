#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

// reference: ZOJ1100.

int f[1100][100];
int n, m, ans;
int state[100][2], cnt = 0;
const int mod = 1000000007;

// dfs中from是一行中前n个格子的状态,to是与之吻合的状态；
void dfs(int k, int from, int to) {
    if(k > m) {
        return;
    }
    if(k == m) {
        state[cnt][0] = from;
        state[cnt][1] = to;
        cnt++;
        return;
    }
    dfs(k+2, (from<<2)+3, (to<<2)+3);  //横着放，这层和下一层匹配的都多两位1  
    dfs(k+1, (from<<1)+1, to<<1);   //竖着放，这层多一个1,匹配下层这个位置是0  
    dfs(k+1, from<<1, (to<<1)+1);  //不放，这层多一个0，匹配的下层多个1  
}

void dp() {
    f[0][(1<<m)-1] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < cnt; ++j) {
            f[i][state[j][1]] += f[i-1][state[j][0]];
            f[i][state[j][1]] %= mod;
        }
    }
    ans = f[n][(1<<m)-1] % mod;
}

int main(int argc, char **argv) {
    scanf("%d %d", &n, &m);
    dfs(0, 0, 0);
    dp();
    printf("%d", ans);
    return 0;
}

