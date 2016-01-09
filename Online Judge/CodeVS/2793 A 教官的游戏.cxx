#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int n, t, ans;
    cin >> n;
    if(n < 0) ans = 120;
    t = n % 5;
    if(t == 0) ans = -1;
    if(t == 1 || t == 4) ans = 0;
    if(t == 2 || t == 3) ans = 1;
    cout << ans << endl;
    return 0;
}
