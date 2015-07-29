#include <cstdio>
#include <cstring>

using namespace std;

int solve(char str1[], char str2[], int k) {
    int max_len = 0;
    int len1 = strlen(str1), len2 = strlen(str2);
    for(int i = 0; i < len1; ++i) {
        for(int j = i+1; j <= len1; ++j) {
            int p = i, q = 0, flag = 0;
            for(int t = 0; t < len2; ++t) {
                if(str1[p] == str2[t]) {
                    p++;
                    flag = 1;
                }
                else if(flag == 1){
                    q++;
                }
                if(p == j || q > k) {
                    break;
                }
            }
            if(q <= k && p == j && max_len < (j-i)) {
                max_len = j - i;
            }
        }
    }

    return max_len;
}

int main(int argc, char **argv) {
    char str1[105], str2[105];
    int k, ans1, ans2;
    while(~scanf("%s %s %d", str1, str2, &k)) {
        ans1 = solve(str1, str2, k);
        ans2 = solve(str2, str1, k);
        printf("%d\n", ans1 > ans2 ? ans1 : ans2);
    }

    return 0;
}

