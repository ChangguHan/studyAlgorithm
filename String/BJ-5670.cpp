// trie 쓰는 문제
// 시간복잡도 먼저 계산해보자
// trie 시간복잡도, N개의 M 문자열
// 구축, O(MN), 조회 : O(M)
// O(MN + MN), O(MN), 1e7

//영어 소문자로만 이루어져있음

// 중복되는게 없으면 되는거니까
// 각 숫자가 몇개인지, 만들기
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
struct node{
    bool fin;
    int totalcnt;
    int child[26];
    int childcnt[26];
    node() {
        fin = false;
        totalcnt=0;
        for(int i=0; i<26; i++) {
            child[i] = -1;
            childcnt[i]=0;
        }
    }
};
vector<node> trie;

void insert(string& s, int idx, int nodi) {
    if(idx==s.size()) {
        trie[nodi].fin = 1;
        trie[nodi].totalcnt++;

        return;
    }

    int cur = s[idx]- 'a';
    if(trie[nodi].child[cur] == -1) {
        trie[nodi].child[cur] = trie.size();
        trie.push_back(node());
    }
    // 카운트 세주기
    trie[nodi].childcnt[cur]++;
    trie[nodi].totalcnt++;
    return insert(s,idx+1,trie[nodi].child[cur]);
}

int check(string& s, int idx, int nodi, int cnt) {
    if(s.size() == idx) return cnt;

    int cur = s[idx]-'a';
    // 첫글자는 무조건 치게
    if(idx==0) {
        return check(s,idx+1,trie[nodi].child[cur], cnt+1);    
    }
    if(trie[nodi].totalcnt == trie[nodi].childcnt[cur]) {
        return check(s,idx+1,trie[nodi].child[cur], cnt);    
    }

    return check(s,idx+1,trie[nodi].child[cur], cnt+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<string> ss;
    while(cin >> n) {
        //setting;
        trie.clear();
        ss.clear();
        trie.push_back(node());
        for (int i=0; i<n; i++) {
            string s; cin >> s;
            ss.push_back(s);
            insert(s,0,0);
        }
        int rs=0;
        for (int i=0; i<n; i++) {
            rs += check(ss[i],0,0,0);
        }
        float rsf = (float)rs*100/n;
        rsf = round(rsf)/100;
        cout<<fixed;
        cout.precision(2);    
        cout << rsf << '\n';
    
    }

    return 0;
}
