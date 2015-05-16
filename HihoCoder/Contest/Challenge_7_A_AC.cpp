#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

/**
 * Author: buaahetao@gmail.com, SCSE, BUAA
 */

int main(int argc, char *argv[])
{
    char s[200];
    int len, cnt = 0, i;
    while(scanf("%s", s) != EOF) {
        len = strlen(s);
        cnt = 0;
        for(i = 0; i < len; ++i) {
            if(s[i] == '0' || s[i] == '1') {
                continue;
            }
            if(s[i] == '(') {
                cnt++;
                continue;
            }
            if(s[i] == ')') {
                if(i > 0 && s[i-1] != '|' && s[i-1] != '(') {
                    cnt--;
                    if(cnt < 0) {
                        break;               
                    }
                    else {
                        continue;
                    }
                } 
                else {
                    break;
                }
            }
            if(s[i] == '|') {
                if((i > 0 && s[i-1] != '|' && s[i-1] != '(') && 
                        (i < len-1 && s[i+1] != '|' && s[i+1] != ')')) {
                    continue;
                }
                else {
                    break;
                }
            }
            if(s[i] == '*') {
                if(i > 0 && s[i-1] != '|' && s[i-1] != '(') {
                    continue;
                }
                else {
                    break;
                }
            }
            break;
        }
        if(i == len && cnt == 0) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
	return 0;
}

/* vim: set ts=4, sw = 4 */


