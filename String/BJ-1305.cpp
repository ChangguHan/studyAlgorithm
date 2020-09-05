// 가능한 광고의 길이 :: 반복되는 것
// 2번이상 반복되는 것중 가장 짧은것
// 앞에서부터 L개 끊어서 포함되는지 확인하면 됨
// L * L, 시간초과

// 6글자라고하면, 앞에 2글자랑 뒤에 2글자랑 같을경우, 4개
// 앞에 4글자랑, 뒤에 4글자가같ㄴ다면 2개
// fail구해서 문자열 길이 - 마지막 숫자 
// 홀수이고 지랄이고 상관없음

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> fail(string& s) {
    vector<int> f(s.size());
    int j=0;
    for(int i=1; i<s.size(); i++) {
        while(j>0 && s[i] != s[j]) j = f[j-1];
        if(s[i] ==s[j]) f[i] = ++j;
    }
    return f;
}

int main() {
    int N; cin >> N;
    string s; cin >> s;
    vector<int> f = fail(s);

    cout << N-f[s.size()-1] <<'\n';

    return 0;
}