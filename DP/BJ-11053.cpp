/**
 BOJ 11053
 - 현재 위치에서, 이전 dp 비교해서 갱신
    - 각 인덱스에서
        - 이전 인덱스 돌면서, 크면 하나 추가해줘서 갱신, 그리고 최대값 이용
 - O(N^2)
 */

#include <iostream>
#include <algorithm>

using namespace std;

int nums[1010];
int dp[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> nums[i];
    dp[0] = 1;
    fill(dp, dp+N+1, 1);
    
    
    for(int j=1; j<N; j++) {
        for(int i=0; i<j; i++) {
            if(nums[j] > nums[i]) dp[j] = max(dp[j], dp[i]+1);
        }
    }
    
    int* maxv = max_element(dp, dp+N);
    cout << *maxv << '\n';
    
    return 0;
}
