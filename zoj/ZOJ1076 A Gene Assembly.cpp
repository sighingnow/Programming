#include <cstdio>
#include <algorithm>
using namespace std;

struct Gene {
    int u, v;
    int index;
} gene[1010];

int comp(const Gene a, const Gene b) {
    if(a.v <= b.v) {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char **argv) {

    freopen("data.in", "r", stdin);
    int n;
    while(scanf("%d", &n) && n) {
        for(int i = 0; i < n; ++i) {
            scanf("%d %d", &gene[i].u, &gene[i].v);
            gene[i].index = i+1;
        }
        sort(gene, gene+n, comp);
        printf("%d", gene[0].index);
        int flag = gene[0].v;
        for(int i = 1; i < n; ++i) {
            if(gene[i].u > flag) {
                flag = gene[i].v;
                printf(" %d", gene[i].index);
            }
        }
        printf("\n");
    }

    return 0;
}
