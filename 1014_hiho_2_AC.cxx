#include <cstdio>
#include <cstring>
using namespace std;

struct Node {
    int cnt;
    char c;
    Node *next[26];
    Node() {    }
    Node(int cnt, char c) {
        this->cnt = cnt;
        this->c = c;
        for(int i = 0; i < 26; ++i) {
            this->next[i] = NULL;
        }
    }
};

int main(int argc, char **argv) {
    int n, m, len;
    char str[12];
    Node *root = new Node(0, '\0');
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", str);
        len = strlen(str);
        Node *p = root;
        for(int i = 0; i < len; ++i) {
            if(p->next[str[i]-'a'] == NULL) {
                p->next[str[i]-'a'] = new Node(0, str[i]);
            }
            p = p->next[str[i]-'a'];
            p->cnt++;
        }
    }

    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%s", str);
        len = strlen(str);
        Node *p = root;
        int index = 0;
        for(index = 0; index < len; ++index) {
            if(p->next[str[index] - 'a'] != NULL) {
                p = p->next[str[index]-'a'];
            }
            else {
                break;
            }
        }
        printf("%d\n", index == len ? p->cnt : 0);
    }

    return 0;
}

