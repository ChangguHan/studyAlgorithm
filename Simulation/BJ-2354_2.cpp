/**
 BOJ 2304
 - 이런 히스토그램 문제, 블럭단위로 너비 * 높이 구하면 힘들어짐
 - 그떄그떄 위치에서 높이를 더하는게 가장 쉬움
 
 - 가장 높은곳 구한다음에
 - 시작해서 높은곳 갈때까지, 현재 나온것중에 최대인 수를 더해줌
 - 끝에서 높은곳 갈ㄱ때까지도 마찬가지로
    - 단 가장 높은곳은 한쪽에서만 더해주면 됨
 */

#include <iostream>
#include <stack>

using namespace std;

int nums[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    int maxv = 0;
    int maxi = -1;
    for(int i=0; i<N; i++) {
        int a,b; cin >> a >> b;
        nums[a] = b;
        if(maxv < nums[a]) {
            maxv = nums[a];
            maxi = a;
        }
    }
    
    stack<int> st;
    int ans=0;
    for(int i=1; i<=maxi; i++) {
        if(nums[i]) {
            if(st.empty()) st.push(nums[i]);
            else if(nums[i] > st.top()) st.push(nums[i]);
        }
        if(!st.empty()) ans += st.top();
    }
    
    while(!st.empty()) st.pop();
    for(int i=1000; i>maxi; i--) {
        if(nums[i]) {
            if(st.empty()) st.push(nums[i]);
            else if(nums[i] > st.top()) st.push(nums[i]);
        }
        if(!st.empty()) ans += st.top();
    }
    
    cout << ans << '\n';
    
    return 0;
}
