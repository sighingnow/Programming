#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    int queue[n];
    memset(queue, 0x00, sizeof(queue[0])*n);
    for(int i = 0; i < n; ++i) {
        queue[i] = i+1;
    }
    int head = 0, tail = n-1;
    for(int i = 1; i <= n; ++i){
        printf("%d ", queue[head]);
        head = (head+1)%n;
        queue[(tail+1)%n] = queue[head];
        head = (head+1)%n;
        tail = (tail+1)%n;
    }
    return 0;
}

