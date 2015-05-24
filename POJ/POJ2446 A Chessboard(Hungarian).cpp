#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void initMap(int n, int m, int k, int cnt[], int map[][4]) {
	bool posi[33][33] = {{false}};
	for(int i = 1; i <= k; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		posi[y][x] = true;
	}
	for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(!posi[i][j]){
                int order = (i-1)*m+j;
                if(i > 1 && !posi[i-1][j]) {
                    map[order][cnt[order]++] = order-m;
                }
                if(i < n && !posi[i+1][j]) {
                    map[order][cnt[order]++] = order+m;
                }
                if(j > 1 && !posi[i][j-1]) {
                    map[order][cnt[order]++] = order-1;
                }
                if(j < m && !posi[i][j+1]) {
                    map[order][cnt[order]++] = order+1;
                }
            }
        }
    }
}

bool dfs(int t, bool isVisit[], int link[], int cnt[], int map[][4])//dfs算法寻找增广路径
{
	if(cnt[t]) {
		for(int i = 0; i < cnt[t]; ++i) {
			if(!isVisit[map[t][i]]) {
				isVisit[map[t][i]] = 1;
				if(link[map[t][i]] == -1 || dfs(link[map[t][i]], isVisit, link, cnt, map)) {
					link[map[t][i]] = t;
					return true;
				}
			}
		}
	}
	return false;
}

int Hungarian(int n, int m, int cnt[], int map[][4]) {
	bool isVisit[n*m+1];
	int link[n*m+1], ans = 0;
	memset(link, 0xff, sizeof(link[0])*(n*m+1));
	memset(isVisit, 0x00, sizeof(isVisit[0])*(n*m+1));
	for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
		    memset(isVisit, 0x00, sizeof(isVisit[0])*(n*m+1));
		    if(dfs((i-1)*m+j, isVisit, link, cnt, map))
			    ++ans;
	    }
    }
	return ans; //在计算过程中，每个匹配都算了两次
}

int main() {//Hungarian算法，max_match
	int map[1200][4] = {{0}};
	int cnt[1200] = {0};
    int n, m, k, ans;
	cin >> n >> m >> k;
	initMap(n, m, k, cnt, map);
	ans = Hungarian(n, m, cnt, map);
	puts(ans+k == m*n ? "YES" : "NO");

	return 0;
}

