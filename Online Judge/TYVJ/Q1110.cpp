#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map <string, int> Person;
int money[12];
int recieve[12];
int send[12];
vector<int>friends[12];
int n, m, k;
string str[12];
string name;

int main(int argc, char **argv) {
    freopen("data.in", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        cin >> name;
        str[i] = name;
        Person.insert(pair<string, int>(name, i));
    }
    for(int i = 1; i <= n; ++i) {
        cin >> name;
        int p = Person[name];
        scanf("%d %d", &m, &k);
        money[p] = m;
        while(k--) {
            cin >> name;
            friends[p].push_back(Person[name]);
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(!friends[i].empty()) {
            int peer = (int)(money[i] / friends[i].size());
            for(int j = 0; j < friends[i].size(); ++j) {
                recieve[friends[i][j]] += peer;
            }
            send[i] = peer * friends[i].size();
        }
    }
    for(int i = 1; i <= n; ++i) {
        cout << str[i] << " ";
        printf("%d\n", recieve[i]-send[i]);
    }

    return 0;
}
