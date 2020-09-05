
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >>n;
    string s; cin >> s;
    int rs=0;
    for(int i=0; i<n; i++) {
        rs += s[i]-'0';
    }
    cout << rs <<'\n';
    
    return 0;
}



// #include <iostream>

// using namespace std;

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

    
//     return 0;
// }