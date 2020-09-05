// 문자열 비교
// 깡으로 비교할경우
// O(NMS), 5e10
// compare 써도 그러나? 이건 해봐야겠다


// trie사용할 경우, O(MS + NS), 1e7

// hash 사용할경우, O(NSM)

#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct node {
    bool fin;
    int child[26];
    node() {
        fin = false;
        for (int i=0; i<26; i++) child[i]=-1;
    }
};
vector<node> trie;
void insert(string& s, int idx, int nodi) {
    if(idx==s.size()) {
        trie[nodi].fin = true;
        return;
    }
    int cur = s[idx]-'a';
    if(trie[nodi].child[cur] == -1) {
        trie[nodi].child[cur] =trie.size();
        trie.push_back(node());
    }

    return insert(s, idx+1,trie[nodi].child[cur]);
}
bool chk(string& s, int idx, int nodi) {
    if(idx == s.size()) {
        if(trie[nodi].fin) return true;
        return false;
    }

    int cur = s[idx]-'a';
    if(trie[nodi].child[cur] == -1) return false;

    return chk(s, idx+1, trie[nodi].child[cur]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // vector<string> s;
    int N,M;
    cin >> N >> M;
    trie.push_back(node());
    for (int i=0; i<N; i++) {
        string ip; cin >> ip;
        // s.push_back(ip);
        insert(ip, 0,0);
    }
    int rs = 0;
    while(M--) {
        string e; cin >> e;
        if(chk(e,0,0)) rs++;
    }


    cout << rs << '\n';

    return 0;
}
