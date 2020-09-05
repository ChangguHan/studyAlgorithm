
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    for(int i=0; i<s.size(); i+=10) {
        int el = 10;
        if(i+10 > s.size()) el = s.size()-i;
        
        cout << s.substr(i,el) << '\n';
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

