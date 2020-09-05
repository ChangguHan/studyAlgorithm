// 그냥 스트링 한칸씩 돌려서 비교하면 안되나
// 1카씩 돌리니까 N번
// 한번에 비교 N
// O(N^2), 1e12 >> 10000초

// 두번째줄을 두번 겹쳐서, 끝에서 한칸 빼고
// KMP 사용한다면
// O(3N), 3e6

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

char want[1000010];
char dolim[2000010];

vector<int> fail(string& s) {
    vector<int> f;
    f.resize(s.size());
    int j=0;
    for (int i=1; i<s.size(); i++) {
        while(j>0 && s[i] != s[j]) j = f[j-1];
        if(s[j] == s[i]) f[i] = ++j;
    }
    return f;
 }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string T,P;
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        char a; cin >> a;
        P+=a;
    }
    for (int i=0; i<N; i++) {
        char a; cin >> a;
        T+=a;
    }
    T+=T;
    T = T.substr(0,T.size()-1);

    vector<int> f = fail(P);
    int j=0;
    int cnt=0;
    for (int i=0; i<T.size(); i++) {
        while(j>0 && T[i] != P[j]) j = f[j-1];
        if(T[i] == P[j]) j++;
        if(j==P.size()) {
            cnt++;
            j = f[j-1];
        }
    }
    int cntb = cnt;
    for(int i=2; i<=cnt; i++) {
        // cnt의 소수 먼저 구하기
        if(cntb%i == 0) {
            
            if(N%i==0) {
                cntb = cntb/i;
                N = N/i;
                i--;
                if(cntb==1) break;
            }
        }
        // 소수 구하면 계속 약분해주기
    }
    cout << cntb << '/' << N << '\n';

    return 0;
}