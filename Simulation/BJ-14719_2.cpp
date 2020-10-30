/**
 BOJ 14719 빗물
 
 - 처음 드는 생각 : 가장 높은것에서 구간을 나눠서 두번째꺼까지? ㄴㄴ
 
 - 빗물 고이는 규칙
    - 왼쪽과 오른쪽에 있는 최대값중 낮은 값까지 차오르게됨
 
 - 시간복잡도
    - 각 위치에서 N
    - 왼쪽과 오른쪽의 최대값을 탐색 N
    
    - 근데 미리 최대값을 한번 탐색했을경우, N으로 끝낼 수 있음
 
 
 - 구체적
    - 각 위치에서의 값 받으면서, 왼쪾에서부터 max, 오른쪽에서부터 max 가져옴
    - 각 위치에서 왼쪽에서부터의 최대값과 오른쪽에서의 최대값중 작은수만큼 높이 추가
 
*/

#include <iostream>

using namespace std;

int nums[510];
int maxL[510];
int maxR[510];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int H,W; cin >> H >> W;
    for(int i=0; i<W; i++) {
        cin >> nums[i];
    }
    
    maxL[0] = nums[0];
    for(int i=1; i<W; i++) {
        maxL[i] = max(maxL[i-1], nums[i]);
    }
    
    maxR[W-1] = nums[W-1];
    for(int i=W-2; i>=0; i--) {
        maxR[i] = max(maxR[i+1], nums[i]);
    }
    
    int ans=0;
    for(int i=1; i<W-1; i++) {
        int secondv = min(maxL[i], maxR[i]);
        int eadd = secondv - nums[i];
        if(eadd>0) ans += eadd;
    }
    
    cout << ans << '\n';
    
    
    return 0;
}
