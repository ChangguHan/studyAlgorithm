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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> s;
    int N,M;
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        string ip; cin >> ip;
        s.push_back(ip);
    }
    int rs = 0;
    while(M--) {
        string e; cin >> e;
        for(int i=0; i<N; i++) {
            if(e.compare(s[i])==0) {
                rs++;
                break;
            }
        }
    }


    cout << rs << '\n';

    return 0;
}
