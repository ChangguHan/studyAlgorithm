// Rabin-Karp
// hash값 사용


#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

ll a = 302;
ll p = 1000000007;
ll powa[1000001];

int main() {
    string T,P;
    getline(cin, T);
    getline(cin, P);
    
    int lenT = T.size();
    int lenP = P.size();
    if(lenT<lenP) {
        cout << 0 << '\n';
        return 0;
    }
    ll hashT = 0;
    ll hashP = 0;
    powa[0] = 1;
    for (int i=1; i<1000001; i++) {
        powa[i] = powa[i-1] * a % p;
    }


    for (int i=0; i<lenP; i++) {
        hashP = (hashP + P[i] * powa[lenP-1-i])%p;
        hashT = (hashT + T[i] * powa[lenP-1-i])%p;
    }
    vector<int> rs;
    if(hashP == hashT) rs.push_back(1);
    
    for (int i=1; i<=(lenT-lenP); i++) {
        // 빼주고, 곱해주고, 더해서, 비교
        hashT = (hashT - T[i-1] * powa[lenP-1])%p;
        if(hashT<0) hashT += p;
        hashT = hashT*a%p;
        hashT = (hashT + T[i+lenP-1]) %p;
        if(hashP ==hashT) rs.push_back(i+1);
    }

    cout << rs.size() << '\n';
    for (int x : rs) cout << x <<' ';


    return 0;
}