
// 실패함수가 뭐였지,
// F(2), 앞에서부터 겹치는것을 출력하는 거잔아

// 부분문자열중 가장 길이 긴걸 구하려면
// KMP 써서 포함되는지 여부를 확인하면 되긴 하는데
// P를 어떻게 고르냐 이거지
// L(길이 정하고) * L(시작위치 정하면), 이제 이거
// KMP써서 횟수 구하는거 구하면 됨
// L*L*(L+L)
//O(L^3 ) 125e9


// 실패함수를 구하면되는데
// 위치 바꿔가면서 자신의 실패함수를 만듬
// 그중에 2넘는 최대값을 구하면 되지
// O(L^2)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fail(string& s) {
    vector<int> f(s.size());
    int j=0;
    for (int i=1; i<s.size(); i++) {
        while(j>0 && s[j] != s[i]) j = f[j-1];
        if(s[j] == s[i]) f[i] = ++j;
    }

    return f;
}
int main() {
    string s; cin >> s;
    int maxv = 0;
    for (int i=0; i<s.size(); i++) {
        string subs = s.substr(i,s.size()-i);
        vector<int> f =  fail(subs);
        int maxelement = *max_element(f.begin(), f.end());
        maxv = max(maxv, maxelement);
    }
    cout << maxv << '\n';
    return 0;
}