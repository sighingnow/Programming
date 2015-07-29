#include <cstdio>
#include <algorithm>
using namespace std;

struct Room {
    double bean;
    double food;
    double radio;
} room[1010];

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    int n;
    double sum, ans;
    while(scanf("%lf %d", &sum, &n)) {
        if(sum == -1) {
            break;
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%lf %lf", &room[i].bean, &room[i].food);
            room[i].radio = room[i].bean / room[i].food;
        }
        sort(room+1, room+n+1, [](const Room & a, const Room & b) {
            if(a.radio >= b.radio) {
                return true;
            }
            else {
                return false;
            }
        });
        ans = 0.0;
        for(int i = 1; i <= n; ++i) {
            if(sum >= room[i].food) {
                sum -= room[i].food;
                ans += room[i].bean;
            }
            else {
                ans += sum * room[i].radio;
                break;
            }
        }
        printf("%.3lf\n", ans);
    }
    
    return 0;
}