#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

map<string, string> relate;
int n, m;

string solve(string a, string b) {
    set<string> s;
    while(a.length() != 0) {
        s.insert(a);
        a = relate[a];
    }
    while(b.length() != 0) {
        if(s.find(b) != s.end()) {
            return b;
        }
        b = relate[b];
    }
    return "-1";
}

int main(int argc, char **argv) {
    string father, son;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        cin >> father >> son;
        relate[son] = father;
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i) {
        cin >> father >> son;
        cout << solve(father, son) << endl;
    }

    return 0;
}

