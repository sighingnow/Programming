#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int main(int argc, char **argv) {
    int n, m;
    char op;
    set<int, greater<int> > S;
    scanf("%d", &n);
    while(n--) {
        scanf("\n%c", &op);
        if(op == 'A') {
            scanf("%d", &m);
            S.insert(m);
        }
        else {
            printf("%d\n", *(S.begin()));
            S.erase(S.begin());
        }
    }

    return 0;
}

