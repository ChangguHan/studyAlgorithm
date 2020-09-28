/**
 BOJ 2003
 
 최대 합 3e8, int 가능
 
 그냥 dp로 탐색하면, N^2, 1e8 가능
 
 근데 two-pointer로 하면, O(2N), 2e4로 가능
 둘다 해보자
 */

//#include <iostream>
//#include <numeric>
//using namespace std;
//
//int nums[10010];
//int dp[10010];
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    int N,M;
//    cin >> N >> M;
//    int cnt=0;
//    for(int i=0; i<N; i++) cin >> nums[i];
//
//    for(int i=0; i<N; i++) {
//        dp[i] = accumulate(nums, nums+i+1,0);
//    }
//
//    for(int i=0; i<N; i++) {
//        if(dp[i]==M) cnt++;
//        for(int j=0; j<i; j++) {
//            if(dp[i]-dp[j] == M) cnt++;
//        }
//    }
//    cout <<cnt << '\n';
//    return 0;
//}


#include <iostream>

using namespace std;

int nums[10010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int st=0, en=0, sum=0, cnt=0;
    int N, M; cin >> N >> M;
    for(int i=0; i<N; i++) cin >> nums[i];
    
    while(1) {
        if(sum>=M) sum -= nums[st++];
        else if(en==N) break;
        else sum += nums[en++];
        
        if(sum ==M) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}
