/**
 빗물문제, 왼쪽과 오른쪽중 두번째로 큰것까지 나머지 구하기
 O(N)
 
 */

#include <iostream>

using namespace std;

int map[510];
int maxL[510];
int maxR[510];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int H,W; cin >> H >> W;
    for(int i=0; i<W; i++) {
        cin >> map[i];
    }
    // 왼쪽 최대값 구하기
    maxL[0] = map[0];
    for(int i=1; i<W; i++) {
        maxL[i] = max(maxL[i-1], map[i]);
    }
    
    maxR[W-1] = map[W-1];
    for(int i=W-2; i>=0; i--) {
        maxR[i] = max(maxR[i+1], map[i]);
    }
    int rs=0;
    for(int i=0; i<W; i++) {
        int secondmax = min(maxL[i], maxR[i]);
        if(secondmax > map[i]) rs += secondmax - map[i];
    }
    
    cout << rs << '\n';
    return 0;
}
