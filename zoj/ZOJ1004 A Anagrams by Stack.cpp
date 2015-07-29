#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
using namespace std;

string a, b;
stack <char> build;
vector <char> ops;
int length;

void dfs(int ipush, int ipop) {
    if(ipush == length && ipop == length) {
        for(char a: ops) {
            cout << a << " ";
        }
        cout << endl;
    }
    if(ipush + 1 <= length) {
        build.push(a[ipush]);
        ops.push_back('i');
        dfs(ipush+1, ipop);
        build.pop();
        ops.pop_back();
    }
    if(ipop + 1 <= ipush && ipop+1 <= length && build.top() == b[ipop]) {
        char tc = build.top();
        build.pop();
        ops.push_back('o');
        dfs(ipush, ipop+1);
        build.push(tc);
        ops.pop_back();
    }
}

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    while(cin >> a >> b) {
        length = a.length();
        cout << "[" << endl;
        dfs(0, 0);
        cout << "]" << endl;
    }
    
    return 0;
}
