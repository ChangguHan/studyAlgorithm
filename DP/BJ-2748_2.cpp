// DP로 다시한번 해보자
// 하고 카톡 답장

#include <iostream>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    ll pibo[100];
    pibo[0]=0; pibo[1] = 1;
    for(int i=2; i<=n; i++) {
        pibo[i] = pibo[i-1] + pibo[i-2];
    }

    cout << pibo[n] << '\n';

    return 0;
}