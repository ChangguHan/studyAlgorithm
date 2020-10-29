/**
 BOJ 2293
 - 코인 각각 이전것 사용해도 되는지
 
 - 이게 안되는이유 : 300원 만들기 위해서, 1,2와 2,1을 따로따로 카운트해주게됨
 
 - 
 */

#include <iostream>
#include <algorithm>

using namespace std;

int coin[110];
int dp[10010];
int main() {
    int N,K; cin >> N >> K;
    for(int i=0; i<N; i++) cin >> coin[i];
    
    dp[0] = 1;
    sort(coin, coin+N);
    
    for(int j=1; j<=K; j++) {
        for(int i=0; i<N; i++) {
            int ec = coin[i];
            if(j-ec<0) {
                break;
            }
            dp[j] += dp[j-ec];
        }
    }
    
    cout << dp[K] << '\n';
    
    return 0;
}
