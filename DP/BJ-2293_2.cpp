// Sn = Sn-1 + Sn-2 + Sn-5 하면 중복이 생김
// 순차적 다른 변수 DP 해줘야함
// 각 레벨이 그 이상의 레벨 영향주지 않도록


#include <iostream>

using namespace std;

int main() {
    int n,k; cin >> n >> k;
    int coins[110];
    for(int i=0; i<n; i++) cin >> coins[i];
    int dp[10010];
    fill(dp, dp+k+1, 0);
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=coins[i]; j<=k; j++) {
            dp[j] += dp[j-coins[i]];
        }
    }
    cout  << dp[k] << '\n';
    return 0;
}