// 문자 총개수에서 공통된거 빼면됨

#include <iostream>
#include <string>

using namespace std;

int alpha1[26];
int alpha2[26];
int main() {
    string a,b;
    cin >> a >>b;

    for (int i=0; i<a.size(); i++) {
        alpha1[a[i]-'a']++;
    }

    for (int i=0; i<b.size(); i++) {
        alpha2[b[i]-'a']++;
    }

    int com=0;
    for (int i=0; i<26; i++) {
        com += min(alpha1[i],alpha2[i]);
    }

    cout << a.size() + b.size() - com*2 << '\n';


    return 0;
}