// 이걸 DP를 이용해서 풀어보자
// Sn = min(Sn-3, Sn-5);
#include <iostream>

using namespace std;
// 메모리 20KB, 
int main() {
    int dp[5010];
    fill(dp, dp+5010, 2000);

    int N; cin >> N;
    dp[3]=1; dp[5]=1;
    for(int i=6; i<=N; i++) {
        int rs = dp[i];
        
        if(i-3>0) {
            rs = min(rs, dp[i-3]+1);
        }
        if(i-5>0) {
            rs = min(rs, dp[i-5]+1);
        }
        dp[i] = rs;
    }

    if(dp[N] == 2000) cout << -1 << '\n';
    else cout << dp[N] <<'\n';
    return 0;
}