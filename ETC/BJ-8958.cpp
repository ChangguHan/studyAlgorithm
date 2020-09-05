

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        int rs=0;
        int cnt=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='O') {
                cnt++;
                rs+=cnt;
            } else {
                cnt=0;
            }

        }
        cout << rs << '\n';
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