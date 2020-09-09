// N개의 합을 만들면서
// 각각 N번 빼주면됨 >> O(N^2)
// 1e8, 될것같은데?? 한번 이렇게 해보자

#include <iostream>

// 최대값, 3억, 그럼 int 가능, 
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nums[10010];
    int dp[10010];
    int N,M; cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }
    dp[0] = nums[0];
    for(int i=1; i<N; i++) {
        dp[i] = dp[i-1] + nums[i];
    }
    int cnt=0;
    for(int i=0; i<N; i++) {
        if(dp[i]==M) cnt++;
        for(int j=0; j<i; j++) {
            if(dp[i]-dp[j]==M) cnt++;
            else if(dp[i]-dp[j] < M) break;
        }

    }

    cout << cnt << '\n';

    return 0;
}