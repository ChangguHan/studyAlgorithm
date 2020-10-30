/**
 BOJ 2304
 
 - 최대값 이전까지 현재 최대값을 가지고 있고
 - 반대서 최대값 이전까지 현재 최대값 가지고 있어서 더해줌
 
 */

#include <iostream>

using namespace std;

int nums[1010];
int maxL[1010];
int maxR[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int maxv = 0;
    int maxi = -1;
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        int a,b; cin >> a >> b;
        nums[a] = b;
        if(b > maxv) {
            maxv = b;
            maxi = a;
        }
    }
    
    for(int i=1; i<=1000; i++) {
        maxL[i] = max(maxL[i-1] , nums[i]);
    }
    
    for(int i=1000; i>=1; i--) {
        maxR[i] = max(maxR[i+1], nums[i]);
    }
    
    int ans=0;
    for(int i=1; i<=maxi; i++) {
        ans += maxL[i];
    }
    
    for(int i=1000; i>maxi; i--) {
        ans += maxR[i];
    }
    
    cout << ans << '\n';
    
    return 0;
}
