

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >>s;
    int alpha[26];
    fill(alpha, alpha+26,0);
    for(int i=0; i<s.size(); i++) {
        alpha[tolower(s[i])-'a']++;
    }
    int maxv=0;
    int idx=0;
    for(int i=0; i<26; i++) {
        if(alpha[i]>maxv) {
            maxv = alpha[i];
            idx=i;
        } 
    }

    int cnt=0;
    for(int i=0; i<26; i++) {
        if(alpha[i]== maxv) {
            cnt++;
        } 
    }
    if(cnt>1) cout <<'?' <<'\n';
    else {
        cout << char(idx + 'A') << '\n';
    }


    
    return 0;
}




// #include <iostream>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

    
//     return 0;
// }

