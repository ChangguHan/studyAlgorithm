// 그냥 해봐도 될것같은데. 어짜피 O(M)

#include <iostream>

using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    ll rs=1; ll rsb=0;;
    for(int i=2; i<=n; i++) {
        rs = rs+rsb;
        rsb = rs - rsb;
    }
    // if(n==0) cout << 0 << '\n';
    // else 
    cout << rs << '\n';

    return 0;
}