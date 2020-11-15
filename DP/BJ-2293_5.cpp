/**
 BOJ 2293
 - 일반 dp를 사용해서, 다음 금액에서 이전 금액을 할경우 발생할 수 있는 문제
    - 중복이 생길수 있음
    - 300원에서 100원 +200원, 200원 + 100원 일떄 중복 생길 수 있음
- 각 동전마다 계싼을 해줘야함
    - 작은 동전 먼저, 300원은 100원 + 200원 케이스를 더해줌
    - 이런식으로 모든 동전에 대해서 더해주ㅐㅁ
 
 - 시간복잡도
    - O(N * K), e6
- INT 초과
    - 많아봐야 e6
 */

#include <iostream>

using namespace std;

int dp[10010];
int coin[110];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,K; cin >> N >> K;
    for(int i=0; i<N; i++) cin >> coin[i];
    
    dp[0] = 1;
    // 모든 코인 종류에서 각각 해당
    for(int i=0; i<N; i++) {
        int ec = coin[i];
        for(int j=ec; j<=K; j++) {
            dp[j] += dp[j-ec];
        }
    }
    
    cout << dp[K] << '\n';
    
    return 0;
}
