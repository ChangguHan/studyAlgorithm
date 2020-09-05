

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int alpha[26];
    fill(alpha, alpha+26, -1);
    for(int i=0; i<s.size(); i++) {
        if (alpha[s[i]-'a'] != -1) {
            alpha[s[i]-'a'] = min(i,alpha[s[i]-'a']);
        }  else {
            alpha[s[i]-'a'] = i;
        }
    }

    for(int i=0; i<26; i++) cout << alpha[i] <<' ';

    
    return 0;
}


// #include <iostream>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

    
//     return 0;
// }

