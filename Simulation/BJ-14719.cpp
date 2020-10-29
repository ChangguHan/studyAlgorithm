/**
 BOJ 14719 빗물
 
 - 왼쪽과 오른쪽 둘다 물을 준 경우보다, 높거나 같으면 물을 담을 수 있음
 - 모든라인 한번 돌아야하고, O(N)
 - 물 높이 M만큼을 확인해야하고 O(M)
 - 각각의 위치에서 왼쪽과, 오른쪽 둘다 확인 O(N)
 
O(N^2 * M)
O(125e6), O(1.e8)
 - 왼쪽에서부터 오른쪽까지
 - 높이 가장 최고부터 낮은곳까지
 - 왼쪾과 오른쪽 탐색하면서 각각 하나라도 있으면 됨
 - 왼쪽, 오른쪽 둘다 있으면 리턴
 */

#include <iostream>

using namespace std;

int num[510];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int H,W; cin >> H >> W;
    for(int i=0; i<W; i++) cin >> num[i];
    int ans=0;
    // 왼쪽 오른쪽은 비를 채울 수 없음
    for(int i=1; i<W-1; i++) {
        // 가장 높은 높이부터 확인
        for(int h = H-num[i]; h>0; h--) {
            // 왼쪽, 오른쪾 확인
            bool chkL = false;
            bool chkR = false;
            
            for(int il=0; il<i; il++) {
                if(num[il] >= h+num[i]) {
                    chkL = true;
                    break;
                }
            }
            for(int ir=W-1; ir>i; ir--) {
                if(num[ir] >= h + num[i]) {
                    chkR = true;
                    break;
                }
            }
            
            if(chkL && chkR) {
                ans += h;
                break;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}

