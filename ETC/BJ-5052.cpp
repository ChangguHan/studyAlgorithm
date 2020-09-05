// TRIE 해보자

#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct node {
    bool fin;
    int child[10];
    node() {
        fin = false;
        for (int i=0; i<10; i++) child[i] = -1;
    }

};
vector<node> trie;
bool sw;

void insert(string& s, int idx, int nodi) {
    if(s.size() == idx) {
        trie[nodi].fin = 1;
        return;
    }
    int cur = s[idx]-'0';
    if(trie[nodi].fin) sw = true;
    if(idx == s.size()-1 && trie[nodi].child[cur] != -1) sw = true;

    if(trie[nodi].child[cur]== -1) {
        trie[nodi].child[cur] = trie.size();
        trie.push_back(node());
    }
    return insert(s,idx+1, trie[nodi].child[cur]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        trie.clear();
        trie.push_back(node());
        sw = false;
        int n; cin >> n;
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            insert(s,0,0);
        }
        if(sw) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}