/**
 
 BOJ 1662
 
 - 압축 전처리한다음에
    - (나오면 끝나는 위치찾음
 - 스트링 돌면서 ( 나오면 끝나는 위치 찾아서 재귀
 
 - 해보고, 직접 문자열만들어보는것도 해보자
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int nxt[60];
string s;

int getLen(int st, int en) {
    int rs=0;
    for(int i=st; i<=en; i++) {
        if(s[i] == '(') {
            int k = s[i-1] - '0';
            rs += k * (getLen(i+1, nxt[i]-1));
            rs--; // 앞에 숫자 하나 빠지니까
            i = nxt[i];
        } else {
            rs++;
        }
    }
    return rs;
}
int main() {
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
    
    cout << getLen(0,s.size()-1) << '\n';
    return 0;
}
