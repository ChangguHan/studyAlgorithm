#include <iostream>
#include <string>

using namespace std;
int alpha[26];
int main() {
    string ip;
    cin >> ip;
    for (int i=0; i<ip.size(); i++) {
        alpha[ip[i]-'a']++;
    }
    for (int i=0; i<26; i++) {
        cout << alpha[i] << ' ';
    }
    cout << '\n';

    return 0;
}