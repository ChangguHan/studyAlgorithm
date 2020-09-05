// 그냥 따라서 구현

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int separate(string s) {
    // 분리
    int cnt=0;
    if(s[0] == '(') cnt++;
    else cnt--;

    for (int i=1; i<s.size(); i++) {
        if(s[i] == '(') cnt++;
        else cnt--;
        if(cnt==0) return i;
    }
    return -1;
}

bool chkright(string s) {
    
    if(s[0]==')') return false;
    int cnt =1;
    for(int i=1; i<s.size(); i++) {
        if(s[i] == '(') cnt++;
        else cnt--;

        if(cnt < 0) return false;
    }
    return 1;
}

string changeu(string s) {
    s = s.substr(1,s.size()-2);
    string n="";
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') n+=")";
        else n += "(";
    }
    return n;


}

string solution(string s) {
    if(s.size()==0) return s;
    // 균형잡힌 문열로 분리
    int idx = separate(s);
    string u = s.substr(0,idx+1);
    string v = s.substr(idx+1,s.size()-idx-1);
    string rs="";
    if(chkright(u)) {
        return u + solution(v);
    }else {
        rs += '(';
        rs += solution(v);
        rs += ')';
        rs += changeu(u);
        return rs;


    }
}

int main() {
    cout << solution("(()())()") <<'\n';
    cout << solution(")(") <<'\n';
    cout << solution("()))((()") <<'\n';

    return 0;
}