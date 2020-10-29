/**
 
 BOJ 1662
 
-  스택을 통해 ( 만나면 스택에 해당 인덱스 저장해두고
 - )만나면 해당 인덱스를 (에 매칭시켜줌(이때 배열 하나 사용
 
 - 재귀함수로, st, en 탐색하는 중에
 - (만나면, 사전에 파악한 )까지를 안에있는것 재귀사용해서 N배해주면됨
 -(안만나면 길이 1씩 증가
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int nxt[60];
string s;

int exec(int st, int en) {
    int rs=0;
    for(int i=st; i<=en; i++) {
        if(s[i] == '(') {
            int K = s[i-1] - '0';
            int couple = nxt[i];
            
            rs += K * exec(i+1, couple-1) -1;
            i = couple;
        } else {
            rs++;
        }
        
    }
    return rs;
}
int main() {
    cin >> s;

    stack<int> st;
    fill(nxt, nxt+60, -1);
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') st.push(i);
        else if(s[i] == ')') {
            nxt[st.top()] = i;
            st.pop();
        }
    }
    
    cout << exec(0,s.size()-1) << '\n';
    
    return 0;
}
