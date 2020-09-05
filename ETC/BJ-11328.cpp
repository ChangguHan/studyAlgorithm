// 개수만 비교하면 될듯

#include <iostream>
#include <string>

using namespace std;
int alpha1[26];
int alpha2[26];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        fill(alpha1, alpha1+26, 0);
        fill(alpha2, alpha2+26, 0);
        string a, b;
        cin >> a >> b;
        for (int i=0; i<a.size(); i++) {
            alpha1[a[i]-'a']++;
        }
        
        for (int i=0; i<b.size(); i++) {
            alpha2[b[i]-'a']++;
        }
        bool sw = false;

        for (int i=0; i<26; i++) {
            if(alpha1[i] != alpha2[i]) {
                sw = true;
                break;

            }
        }
        if(sw) cout << "Impossible" << '\n';
        else cout << "Possible" << '\n';

    }




    return 0;
}