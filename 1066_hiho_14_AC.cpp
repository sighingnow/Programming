#include <cstdio>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

map<string, int>M;
int root[20005], rank[20005];

int find(int x) {
    if(x != root[x]) {
        root[x] = find(root[x]);
    }
    return root[x];
}

void unionSet(int a, int b) {
    if((a = find(a)) == (b = find(b))) {
        return;
    }
    if(rank[a] < rank[b]) {
        root[a] = b;
    }
    else {
        root[b] = a;
        if(rank[a] == rank[b]) {
            rank[b]++;
        }
    }
}

int main(int argc, char **argv) {
    int op, cnt = 1, n;
    string a, b;
    for(int i = 0; i < 20005; ++i) {
        root[i] = i;
        rank[i] = 0;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        cin >> op >> a >> b;
        if(M[a] == 0) {
            M[a] = cnt++;
        }
        if(M[b] == 0) {
            M[b] = cnt++;
        }
        if(op == 0) {
            unionSet(M[a], M[b]);
        }
        else {
            puts(find(M[a]) == find(M[b]) ? "yes" : "no");
        }
    }

    return 0;
}

