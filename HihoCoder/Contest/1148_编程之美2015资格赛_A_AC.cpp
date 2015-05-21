#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char mouth[13][10] = {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

int getmouth(char *s) {
    for(int i = 1; i <= 12; ++i) {
        if(strcmp(s, mouth[i]) == 0) {
            return i;
        }
    }
}

int main(int argc, char** argv) {
    int T, t = 0, y, m, d, cnt1, cnt2;
    char input[50] = {'\0'}, ms[50];
    scanf("%d", &T);
    while(++t <= T) {
        scanf("\n%s %d, %d", ms, &d, &y);
        cnt1 = (y-1)/4-(y-1)/100+(y-1)/400;
        if((y % 100 != 0 && y % 4 == 0 || y % 400 == 0) &&
                getmouth(ms) > 2) {
            cnt1++;
        }
        scanf("\n%s %d, %d", ms, &d, &y);
        cnt2 = (y-1)/4-(y-1)/100+(y-1)/400;
        if((y % 100 != 0 && y % 4 == 0 || y % 400 == 0) && 
                (getmouth(ms) > 2 || getmouth(ms) == 2 && d == 29)) {
            cnt2++;
        }
        printf("Case #%d: %d\n", t, cnt2-cnt1);
    }
    return 0;
}
