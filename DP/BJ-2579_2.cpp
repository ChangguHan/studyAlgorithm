/**
 BOJ 2579
 복수의 dp 사용하자
 - dp, 각 위치에서, 이전에 올라온 위치
    - 2칸 올라왔을떄는(1), 2칸 이전의 0,1 중 최대값 하면 되는데
    - 1칸 올라왔을때는(0), 1칸 이전의 1만 선택
 */

#include <iostream>

using namespace std;

int dp[310][2];
int map[310];

int get_dp(int cur, int chk) {
    if(cur <=0) return 0;
    if(dp[cur][chk] != -1) return dp[cur][chk];
    
    if(chk==1) {
        // 2칸 올라왔을때는 이전중 최대값
        return dp[cur][chk] = max(get_dp(cur-2, 0), get_dp(cur-2, 1)) + map[cur];
    } else {
        // 1칸 올라왔을떄는 이전의 2칸 올라온것만
        return dp[cur][chk] = get_dp(cur-1,1) + map[cur];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    fill(&dp[0][0], &dp[N][2], -1);
    for(int i=1; i<=N; i++) cin >> map[i];
    
    cout << max(get_dp(N,0), get_dp(N,1)) << '\n';
    return 0;
    
}
