// DP로 풀수있을까? 
// 앞에 큰거 나오면 경우의수가 여러개 생겨서 어려움
// 알파벳 모은다음, 각각의 수를 대입해서, 최대수로 출력하면 되겠다

// 시간초과를 어떻게 해결할지...
// 1. 최대 숫자 알파벳 선정 미리하는 경우
// >> 작은 숫자 여러개면 의미없음


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxv=0;
vector<char> alpha; // 알파벳 모아놓을곳
vector<int> v;
int N;
vector<char> map[20];
void cal() {
    int rs=0;
    for (int j=0; j<N; j++) {
        string a;
        for (int i=0; i<map[j].size(); i++) {
            int alphaidx;
            for(int k=0; k<alpha.size(); k++) {
                if(alpha[k] == map[j][i]) {
                    a += to_string(v[k]);
                    break;
                }
            }
        }
        rs += stoi(a);
    }
    maxv = max(rs, maxv);
    
    return;
}
void dfs() {
    if(v.size() == alpha.size()) {
        cal();
        return;
    }
    // int idx = 10;
    // if(v.size() !=0 ) idx = v.back();
    
    // 조합이 아니고 순열이지
    for(int i=9; i>=10-alpha.size(); i--) {
        bool sw= false;
        for (int x : v) {
            if(x==i) {
                sw = true;
                break;
            }
        }
        if(sw) continue;
        v.push_back(i);
        dfs();
        v.pop_back();
    }

}
int main() {
    cin >> N;
    for (int i=0; i<N; i++ ) {
        string ip;
        cin >> ip;
        for (int j=0; j<ip.length(); j++ ) {
            map[i].push_back(ip[j]);
            // 알파벳 모아놓기
            bool sw = false;
            for (char x : alpha) {
                if(x == ip[j]) {
                    sw = true;
                    break;
                }
            }
            if(sw == false) alpha.push_back(ip[j]);
        }
    }

    dfs();


    cout << maxv << '\n';

    return 0;
}

// 시간초과를 어떻게 해결...?
// 1. min값 들만 백트래킹 해볼ㅏ

