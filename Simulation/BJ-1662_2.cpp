/**
 BOJ 1662 압축
 
 - 스택을 통해 (나올떄마다 연산자에 넣고, 끝나는것을 먼저 전처리해줌
 - 스택함수 돌면서 재귀함수로, 나오면 카운트 세줌
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int nxt[60];
string s;

int cal(int st, int en) {
    int rs=0;
    for(int i=st; i<=en; i++) {
        if(s[i] == '(') {
            int bf = s[i-1]-'0';
            rs += bf * (cal(i+1, nxt[i]-1)) -1;
            i = nxt[i];
        } else {
            rs++;
        }
    }
    return rs;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;
    stack<int> st;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            st.push(i);
        } else if(s[i] == ')') {
            nxt[st.top()] = i;
            st.pop();
        }
    }
    
    cout << cal(0,s.size()-1) << '\n';
    
    return 0;
}
