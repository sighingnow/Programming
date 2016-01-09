#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
/*******************************************
 * Aho-Corasick automation
 ********************************************/

const int kind = 26;
char pattern[1000010];
char str[1000010];

struct Node{
    Node *fail;
    Node *next[kind];
    bool end;

    Node() {
        this->fail = NULL;
        this->end = false;
        memset(next, 0x00, sizeof(next[0]) * kind);
    }
};

void insert(char pattern[], Node *root) {
    Node *p = root;
    int i = 0, index;
    while(pattern[i] != '\0') {
        index = pattern[i] - 'a';
        if(p->next[index] == NULL) {
            p->next[index] = new Node();
        }
        p = p->next[index];
        ++i;
    }
    p->end = true;
}

void build_ac_auto(Node *root) {
    queue <Node *> bfs_queue;
    for(int i = 0; i < 26; ++i) {
        if(root->next[i]) {
            root->next[i]->fail = root;
            bfs_queue.push(root->next[i]);
        }
    }
    while(!bfs_queue.empty()) {
        Node *tmp = bfs_queue.front();
        bfs_queue.pop();
        for(int i = 0; i < 26; ++i) {
            Node *p = tmp->next[i];
            if(p != NULL && !p->end) {
                Node *fail = tmp->fail;
                while(fail != NULL) {
                    if(fail->next[i] != NULL) {
                        p->fail = fail->next[i];
                        if(p->fail->end) {
                            p->end = true;
                        }
                        break;
                    }
                    else {
                        fail = fail->fail;
                    }
                }
                if(p->fail == NULL) {
                    p->fail = root;
                }
                bfs_queue.push(p);
            }
        }
    }
}

void query(Node *root, char str[]) {
    int i = 0, index;
    Node *p = root;
    while(str[i] != '\0') {
        index = str[i] - 'a';
        while(true) {
            if(p->next[index]) {
                p = p->next[index];
                if(p->end) {
                    printf("YES");
                    return;
                }
                break;
            }
            else {
                p = p->fail;
            }
            if(p == root || p == NULL) {
                p = root;
                break;
            }
        }
        i++;
    }
    printf("NO");
}

int main(int argc, char *argv[]) {
    
    int n;
    scanf("%d", &n);
    Node *root = new Node();
    while(n--) {
        scanf("%s", pattern);
        insert(pattern, root);
    }
    build_ac_auto(root);
    scanf("%s", str);
    query(root, str);
    return 0;
}

