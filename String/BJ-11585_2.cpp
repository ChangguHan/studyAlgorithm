// 라빈카프로 풀어보자

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

ll a = 302;
ll p = 1e9+7;
ll pow_a[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    string T,P;
    for (int i=0; i<N; i++) {
        char a; cin >> a;
        P+=a;
    }

    pow_a[0] = 1;
    for (int i=1; i<N; i++) {
        pow_a[i] = pow_a[i-1] * a %p;
    }

    for (int i=0; i<N; i++) {
        char a; cin >> a;
        T+=a;
    }
    T+=T;
    T = T.substr(0,N*2-1);

    int lenP = N;
    int lenT = 2*N-1;

    ll hashP=0;
    ll hashT=0;
    for (int i=0; i<lenP; i++) {
        hashP = (hashP + P[i] * pow_a[lenP-i-1]) %p;
        hashT = (hashT + T[i] * pow_a[lenP-i-1]) %p;
    }
    int cnt=0;
    if(hashP == hashT) cnt++;
    for (int i=1; i<=lenT-lenP; i++) {
        // 빼고, 곱하고, 더해서, 비교
        hashT = (hashT - T[i-1] * pow_a[lenP-1]) %p;
        if(hashT <0) hashT += p;
        hashT = hashT * a %p;
        hashT = (hashT + T[i+lenP-1])%p;
        if(hashT == hashP) cnt++;
    }


    int cntb = cnt;
    for(int i=2; i<=cnt; i++) {
        if(cntb %i==0) {
            if(N%i==0) {
                cntb = cntb/i;
                N = N/i;
                i--;
                if(cntb==1) break;
            }
        }
    }

    cout << cntb << '/' << N << '\n';




    return 0;
}