/**
 BOJ 14719
 
  빗물 담기는 원리 : 각 열에서, 왼쪽과 오른쪽의 최대 높이중 작은것만큼 차게 되어있음
 
 왼쪽에서부터 최대값 구하고 O(N)
 오른쪽에서부터 최대값 구함 O(N)
 열 돌면서 두 최대값중 작은것에서 현재 높이의 차이만큼 값 더해줌
    - 음수일경우 그냥 넘어감
 >> O(N)
 
 - INT 체크
    - H^2, 25e4
 
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
    
    int rs=0;
    for(int i=1; i<W-1; i++) {
        int second = min(maxL[i], maxR[i]);
        int h = second - nums[i];
        if(h>0) rs+=h;
    }
    
    cout << rs << '\n';
    return 0;
}
