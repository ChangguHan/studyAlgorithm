/**
 BOJ 2293
 
 2원짜리는 1원짜리를 사용할수 있음
 5원짜리는 2,1원짜리를 사용할 수 있으나, 그 위로는못씀
 
 순차적 dp
 높은 동전 계싼시 낮은 동전을 사용
 각 동전 계싼에서, 이전것 더해서 사용
 */

#include <iostream>

using namespace std;

int coins[110];
int dp[10010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K; cin >> N >> K;
    for(int i=0; i<N; i++) cin >> coins[i];
    
    dp[0]=1;
    for(int i=0; i<N; i++) {
        int ec = coins[i];
        for(int j=ec; j<=K; j++) {
            dp[j] += dp[j-ec];
        }
    }
    
    cout << dp[K] << '\n';
    return 0;
}
