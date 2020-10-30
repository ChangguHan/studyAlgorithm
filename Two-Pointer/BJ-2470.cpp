/**
 BOJ 2470
 - N = 1e5, N^2로 할경우 시간초과
 - 두수 더해야 2e9이므로 int 사용 가능
 
 - 정렬한 다음 lgN
 - 작은수에서부터, 큰수에서부터 내려옴 N
    - 둘이 만나면 끝
    - 0이 되는 경우 바로 종료
 
 O(NlgN)
 */

#include <iostream>
#include <algorithm>

using namespace std;

int nums[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+N);
    
    int st=0, en = N-1;
    int minv = 2e9+10;
    int li =0, ri = N-1;
    while(st != en) {
        if(abs(nums[st] + nums[en]) < minv) {
            minv = abs(nums[st] + nums[en]);
            li = st;
            ri = en;
        }
        
        if(nums[st] + nums[en] ==0 ) {
            break;
        }else if(nums[st] + nums[en] <0 ) {
            // 여기서 0에 더 가까운지 비교
            st++;
        }else {
            en--;
        }
    }
    
    cout << nums[li] << ' ' << nums[ri] << '\n';
    
    return 0;
}
