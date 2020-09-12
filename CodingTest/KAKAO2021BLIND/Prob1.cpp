#include <iostream>


#include <string>
#include <vector>
// #include <algorithm>
// #include <cctype>

using namespace std;

string solution(string new_id) {
    for(int i=0; i<new_id.size(); i++) {
        char ec = new_id[i];
        new_id[i] = tolower(ec);
        // ㅅㅗ문자, 숫자, 뺴기, 밑줄 마침표 제외하고 제거
        int ei = new_id[i]-'a';
        // if(!((ei>=0 && ei<=25) ||(ei>=-49 && ei<=-40) ||ei==-52 ||ei== -2 || ei==-51)) {
        if(!((ei>=0 && ei<=25) ||(ei>=-49 && ei<=-40) ||ec=='-' ||ec== '_' || ec=='.')) {
        // if(ec=='~'||ec=='!'||ec=='@'||ec=='#'||ec=='$'||ec=='%'||ec=='^'||ec=='&'||ec=='*'||ec=='('||
        // ec==')'||ec=='='||ec=='+'||ec=='['||ec=='{'||ec==']'||ec=='}'||ec==':'||ec=='?'||ec==','||ec=='<'||ec=='>') {
            new_id = new_id.substr(0,i) + new_id.substr(i+1);
            i--;
            continue;
        }

        // 중복 마침표 치환
        // 뒤에껄 보는게 낫겠다
        if(i!=new_id.size()-1) {
        // if(i!=0) {
            // if(new_id.substr(i-1,2)=="..") {
            if(new_id.substr(i,2)=="..") {
                // new_id = new_id.substr(0,i) + new_id.substr(i+1);
                new_id = new_id.substr(0,i) + new_id.substr(i+1);
                i--;
                // if(i!=new_id.size()-1) continue;
                continue;

            }
            
        }


        // . 제거
        if(i==0) {
            if(ec=='.') {
                new_id = new_id.substr(1);
                i--;
                continue;
            }
        }
        if(i==new_id.size()-1) {
            if(ec=='.') {
                new_id = new_id.substr(0,i);
                continue;
            }
        }


    }

    if(new_id.size()==0) new_id="a";
    if(new_id.size()>=16) {
        new_id = new_id.substr(0,15);
        if(new_id[14]=='.') new_id = new_id.substr(0,14);
    }
    if(new_id.size()<=2) {
        char lc = new_id[new_id.size()-1];
        while(1) {
            new_id += lc;
            if(new_id.size()==3) break;
        }
    }
    
    return new_id;
}

int main() {

    // cout << solution("...!@BaT#*..y.abcdefghijklm") << '\n';
    // cout << solution("b......................b") << '\n';
    // cout << solution("123_.def") << '\n';
    // cout << solution("abcdefghijklmn.p") << '\n';
    cout << solution("z-+.^.") << '\n';
    // cout << solution("") << '\n';

    // cout <<'a'-'a' << '\n';
    // cout <<'z'-'a' << '\n';
    // cout <<'0'-'a' << '\n';
    // cout <<'9'-'a' << '\n';
    // cout <<'-'-'a' << '\n';
    // cout <<'_'-'a' << '\n';
    // cout <<'.'-'a' << '\n';

  


    
    


    return 0;
}