#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[100010];
int n = 0, m = 0, index_n = -1, index_m = -1;

int main(int argc, char **argv) {
    while(~scanf("%s", str)) {
        n = 0, m = 0, index_n = -1, index_m = -1;
        for(int i = 0; str[i] != '\0'; ++i) {
            if(str[i] <= 'Z' && str[i] >= 'A') {
                n++;
                if(n == 1) {
                    index_n = i;
                }
            }
            else {
                m++;
                if(m == 1) {
                    index_m = i;
                }
            }
            if(m > 1 && n > 1) {
                break;
            }
        }
        if(n == 1 && m == 1) {
            printf("-1\n");
        }
        else if(n == 1) {
            printf("%d\n", index_n+1);
        }
        else if(m == 1) {
            printf("%d\n", index_m+1);
        }
        else {
            printf("-1\n");
        }
    }
    return 0;
}

