#include <iostream>
#include <cstring>
using namespace std;
int graph[130][130];
int main(void) {
    int n;
    cin >> n;
    memset(graph, 0, sizeof(graph));
    int center = 65;
    graph[center][center] = 1;
    graph[center - 1][center] = 1;
    graph[center + 1][center] = 1;
    graph[center][center - 1] = 1;
    graph[center][center + 1] = 1;
    // left
    for(int i = 0; i <= n; i++) {
        for(int j = -i * 2; j <= i * 2; j++) {
            graph[center - 2 - i * 2][center + j] = 1;
        }
    }
    // right
    for(int i = 0; i <= n; i++) {
        for(int j = -i * 2; j <= i * 2; j++) {
            graph[center + 2 + i * 2][center + j] = 1;
        }
    }
    // up
    for(int i = 0; i <= n; i++) {
        for(int j = -i * 2; j <= i * 2; j++) {
            graph[center + j][center - 2 - i * 2] = 1;
        }
    }
    // down
    for(int i = 0; i <= n; i++) {
        for(int j = -i * 2; j <= i * 2; j++) {
            graph[center + j][center + 2 + i * 2] = 1;
        }
    }
    // left up
    for(int i = 0; i <= n; i++) {
        graph[center - i * 2][center - i * 2] = 1;
        graph[center - i * 2 - 1][center - i * 2] = 1;
        graph[center - i * 2][center - i * 2 - 1] = 1;
    }
    // right up
    for(int i = 0; i <= n; i++) {
        graph[center + i * 2][center - i * 2] = 1;
        graph[center + i * 2 + 1][center - i * 2] = 1;
        graph[center + i * 2][center - i * 2 - 1] = 1;
    }
    // left down
    for(int i = 0; i <= n; i++) {
        graph[center - i * 2][center + i * 2] = 1;
        graph[center - i * 2 - 1][center + i * 2] = 1;
        graph[center - i * 2][center + i * 2 + 1] = 1;
    }
    // right down
    for(int i = 0; i <= n; i++) {
        graph[center + i * 2][center + i * 2] = 1;
        graph[center + i * 2 + 1][center + i * 2] = 1;
        graph[center + i * 2][center + i * 2 + 1] = 1;
    }
    for(int i = center - 2 - 2 * n; i <= center + 2 + 2 * n; i++) {
        for(int j = center -2 -2 * n; j <= center + 2 + 2 * n; j++) {
            if(graph[i][j] == 1) {
                cout << "$";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    return 0;
}
