/**
 BOJ 1662 압축
 - 전처리를 통해서, 압축 시작되고 끝나는지점 주갛ㅁ
 - 재귀함수 사용해서 길이 출력
 - 시간복잡도
    - 한번 전처리 O(N)
    - 재귀 O(N)
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int nxt[60];

int cal(int st, int en, string& s) {
    int rs=0;
    for(int i=st; i<=en; i++) {
        rs++;
        if(s[i] == '(') {
            rs-=2;
            int num = s[i-1] -'0';
            rs += num * cal(i+1, nxt[i]-1, s);
            i = nxt[i];
        }
        
    }
    return rs;
}
int main() {
    string s; cin >> s;
    stack<int> st;
    for(int i=0; i<s.size(); i++) {
        int cur = s[i];
        if(cur == '(') {
            st.push(i);
        } else if(cur== ')') {
            nxt[st.top()] = i;
            st.pop();
        }
    }
    
    cout << cal(0,s.size()-1, s) << '\n';
    return 0;
}
