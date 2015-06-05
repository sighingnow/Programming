#include <cstdio>
#include <algorithm>
using namespace std;

/**
 * 贪心算法，每次都选取结束最早的工作，如此便可以尽可能多地完成Task。
 */

const int maxn = 1e5+5;

struct Task {
    int start, end;
} tasks[maxn];

int main(int argc, char **argv) {
    int a, b, c = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &tasks[i].start, &tasks[i].end);
    }
    sort(tasks+1, tasks+1+n, [](Task a, Task b) {return a.end<b.end;});
    for(int i = 1; i <= n; ++i) {
        if(c < tasks[i].end) {
            c = tasks[i].end; ans += 1;
        }
    }
    printf("%d", ans);

    return 0;
}

