#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string ans;

void recoveryTree(string pre, string mid) {
    int iPos;
    if(pre == "" || mid == "") {
        return;
    }
    iPos = mid.find(pre[0]);
    recoveryTree(pre.substr(1, iPos), mid.substr(0, iPos));
    recoveryTree(pre.substr(iPos+1, pre.size()-iPos), mid.substr(iPos+1, mid.size()-iPos));
    ans += pre[0];
}

int main(int argc, char **argv) {

    freopen("data.in", "r", stdin);
    string pre, mid;
    while(cin >> pre >> mid) {
        ans.clear();
        recoveryTree(pre, mid);
        cout << ans << endl;
    }

    return 0;
}
