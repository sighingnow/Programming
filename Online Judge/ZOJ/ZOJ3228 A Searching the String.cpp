#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXK 26
#define MAXLEN 100005

#define MAXPLEN 6
#define OVLP 0
#define NOVLP 1

struct trieNode {
	trieNode* sons[MAXK];
	int last, ovlp, novlp;
	trieNode() {
		for(int i = 0; i < MAXK; ++i)
			sons[i] = NULL;
		last = -1;
		ovlp = novlp = 0;
	}
};
typedef trieNode *trie;

void insert(trie t, char s[], int begin, int end) {
	for(int i = begin; i < end; ++i) {
		if(t->sons[s[i] - 'a'] == NULL)
			t->sons[s[i] - 'a'] = new trieNode();
		t = t->sons[s[i] - 'a'];
		++t->ovlp;
		if(t->last < begin)	{
			++t->novlp;
			t->last = i;
		}
	}
}

int query(trie t, int type, char pat[]) {
	for(int i = 0; pat[i] != '\0'; ++i) {
		if(t->sons[pat[i] - 'a'] == NULL)
			return 0;
		t = t->sons[pat[i] - 'a'];
	}
	if(type == OVLP)
		return t->ovlp;
	else
		return t->novlp;
}

void drop(trie t) {
	for(int i = 0; i < MAXK; ++i)
		if(t->sons[i])
			drop(t->sons[i]);
	delete t;
}

int main()
{
//    freopen("data.in", "r", stdin);

    char s[MAXLEN];
	int cs = 0;
	while(scanf("%s", s) != EOF) {
		trie t = new trieNode();
		int len = strlen(s);
		for(int i = 0; i < len; ++i) {
			if(i + MAXPLEN > len)
				insert(t, s, i, len);
			else
				insert(t, s, i, i + MAXPLEN);
		}
		int qnum, type;
		char pat[MAXPLEN + 2];
		scanf("%d", &qnum);
		printf("Case %d\n", ++cs);
		for(int i = 0; i < qnum; ++i) {
			scanf("%d%s", &type, pat);
			printf("%d\n", query(t, type, pat));
		}
		printf("\n");
		drop(t);
	}
	return 0;
}

