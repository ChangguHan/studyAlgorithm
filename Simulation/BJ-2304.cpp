/**
 BOJ 2304 창고다각형
 - 창고생기는 원칙
    - 최대값 이전까지 이전의 최대값으로 창고를 그리게됨
    - 최대값 이후부터는, 오르쪽에서부터 이전의 최대값으로 창고를 그림
 
 - 시간복잡도
    - 입력받으면서 전체 최대값 구함 O(N)
    - 왼쪽에서부터, 오른쪽에서부터 각각 최대값을 구함 O(N)
    - 왼쪽에서 맥스까지, 오른쪾에서 맥스전까지 컨테이너 구함 O(N)
 
 >> O(N)
 
 - INT 초과
    - e6
    - 초과하지 않음
 
 */

#include <iostream>
#include <algorithm>

using namespace std;

int nums[1010];
int maxL[1010];
int maxR[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    for(int i=0; i<N; i++) {
        int a,b; cin >> a >> b;
        nums[a] = b;
    }
    
    int maxidx = distance(nums, max_element(nums, nums+1000));
    
    int rs=0;
    int maxv = 0;
    for(int i=1; i<=maxidx; i++) {
        maxv = max(maxv, nums[i]);
        rs += maxv;
    }
    maxv = 0;
    for(int i=1000; i>maxidx; i--) {
        maxv = max(maxv, nums[i]);
        rs += maxv;
    }
    
    cout << rs << '\n';
    
    return 0;
    
}

