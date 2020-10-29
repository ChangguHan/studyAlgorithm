/**
 
 BOJ 2304
 - 왼쪽에서부터 올라가는 순서면 내려오는걸 잴수가 없음
 - 가장 높은것을 찾고, 그다음 쭉쭉 내려오는 방법으로 해야될듯
    - 가장 높은것을 찾고, 그다음 왼쪽 오른쪽에서 높은것을 찾고
        - 이걸 바닥에 내려올떄까지 반복
 - O(N^2),
 
 
- 입력 배열에 넣으면서 최대값과 최대 인덱스 구함
 - 최대값 양쪽에서 가장 높은 값 구함
 - 해당 인덱스 다음부터 계속 높은값 구해서, 0나올떄까지
 */

#include <iostream>

using namespace std;

int nums[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    int maxidx=-1;
    int maxv = 0;
    int ans=0;
    for(int i=0; i<N; i++) {
        int idx; cin >> idx;
        int v; cin >> v;
        nums[idx] = v;
        
        if(nums[idx] > maxv) {
            maxv = nums[idx];
            maxidx = idx;
        }
    }
    ans += maxv;
    int li = maxidx;
    int ri = maxidx;
    while(1) {
        int lmaxv=0;
        int lmaxi = -1;
        for(int i=0; i<li; i++) {
            if(nums[i] > lmaxv ) {
                lmaxv = nums[i];
                lmaxi = i;
            }
        }
        if(lmaxv !=0) {
            ans += (li - lmaxi) * lmaxv;
            li = lmaxi;
        }
        
        int rmaxv=0;
        int rmaxi = -1;
        for(int i=1000; i>ri; i--) {
            if(nums[i] > rmaxv ) {
                rmaxv = nums[i];
                rmaxi = i;
            }
        }
        if(rmaxv !=0) {
            ans += (rmaxi- ri) * rmaxv;
            ri = rmaxi;
        }
        
        if(lmaxv == 0 && rmaxv ==0 ) break;
        
        
    }
    cout << ans << '\n';
    return 0;
}
