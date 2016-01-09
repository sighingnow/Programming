#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/**
 * Author: buaahetao@gmail.com, SCSE, BUAA
 */

inline void insert(char s[], char str[], char c, int index) {
    int i = 0, j = 0;
    while(str[j] != '\0') {
        if(i != index) {
            s[i++] = str[j++];
        }
        else {
            s[i++] = c;
        }
    }
    if(i == j) {
        s[i++] = c;
    }
    s[i++] = '\0';
}

int handle(char s[]) {
    int cnt = 0;
    while(true) {
        char tmp[105] = {'\0'};
        int top = 0, i = 0, j = 1;
        for(; s[j] != '\0'; ++j) {
            if(s[j] != s[i]) {
                tmp[top++] = s[i];
            }
            else {
                while(s[j] != '\0' && s[j] == s[i]) {
                    j++;
                }
            }
            i = j;
        }
        if(s[j] == '\0') {
            tmp[top++] = s[i];
        }
        if(strlen(tmp) == strlen(s)) {
            cnt = strlen(tmp);
            break;
        }
        memset(s, 0x00, sizeof(s[0]) * 105);
        strcpy(s, tmp);
    }
    return cnt;
}

int main(int argc, char *argv[])
{
    char s[105], str[105], abc[4] = "ABC";
    int len, ans, T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", str);
        len = strlen(str);
        ans = len;
        for(int i = 0; i <= len; ++i) {
            for(int j = 0; j < 3; ++j) {
                insert(s, str, abc[j], i);
                ans = min(ans, handle(s));
            }
        }
        printf("%d\n", len + 1 - ans);
    }
	return 0;
}

/* vim: set ts=4, sw = 4 */


