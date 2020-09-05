// Sk = Sk-1 + Sk-2 + Sk-5 ...
// nk = 1e6

#include <iostream>

using namespace std;

int n,k;
int coin[110];
int rs[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> coin[i];

    rs[0] = 1;
    sort(coin, coin+n);

    for(int i=1; i<=k; i++) {
        int e = 0;
        for(int j=0; j<n; j++) {
            if(i-coin[j] <0) break;
            e += rs[i-coin[j]];
        }
        rs[i] = e;
    }

    cout << rs[k] << '\n';

    return 0;
}
