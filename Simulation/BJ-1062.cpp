// 알파벳 목록화해서
// 각각을 습득했을때, 조합 >> 백트래킹
// 단어 읽을수 있는 최대

#include <iostream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> dl;
vector<char> alpha;
char base[5] = {'a','n','t','c','i'};
vector<int> v;
int N,K;
int mv = 0;

void cal() {
    int rs=0;
    vector<char> newv;
    for (int x : v) newv.push_back(alpha[x]);
    for (int i=0; i<5; i++) newv.push_back(base[i]);
    
    for (string x : dl) {
        bool sw = true;
        for (int i=0; i<x.size(); i++) {
            char ex =x[i];
            vector<char>::iterator it = find(newv.begin(), newv.end(), ex);
            if(it== newv.end()) {
                sw = false;
                break;
            }
        }
        if(sw) rs++;
    }
    mv = max(mv, rs);
}


void dfs() {
    if(v.size() == K-5) {
        cal();
        return;
    }
    int idx = -1;
    if(v.size()!=0) idx = v.back();

    for (int i=idx+1; i<alpha.size(); i++) {
        v.push_back(i);
        dfs();
        v.pop_back();
    }
}

int main() {
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        string ip;
        cin >> ip;
        dl.push_back(ip.substr(4,ip.length()-4-4));

        // }
        
    }
    // 베이스 못배우면, 0 출력
    if(K <5) {
        cout << 0 << '\n';
        return 0;
    }


    // 추가 외워야할 글자 리스트 출력
    for (string x : dl) {
        for (int i=0; i<x.length(); i++) {
            char *it;
            it = find(base, base+5, (char)x[i]);
            if(it == base+5) {
                // 이미 있는곳에 없으면
                vector<char>::iterator it = find(alpha.begin(), alpha.end(), (char)x[i]);
                if (it == alpha.end()) alpha.push_back(x[i]);
            }
        }
    }
    dfs();

    cout << mv << '\n';



    return 0;
}