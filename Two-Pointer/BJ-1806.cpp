/**
 BOJ 1806
 - DP로 사용하면 O(N^2), 1e10이 되어서 시간초과
 
 - Two pointer 사용 O(2N)
    - st, en,왼쪽에서 시작해서, 최소길이 갱신
    
 - 모두 합 e9, 이므로 long 사용
 */

#include <iostream>

using namespace std;
typedef long long ll;

int nums[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    ll M; cin >> N >> M;
    for(int i=0; i<N; i++) cin >> nums[i];
    
    int st=0, en=0;
    ll sum = 0;
    int rs=100010;
    
    while(1) {
        if(sum >= M) sum -= nums[st++];
        else if(en==N) break;
        else sum += nums[en++];
        
        if(sum>=M) {
            rs = min(rs, en-st);
        }
    }
    if(rs==100010) cout << 0 << '\n';
    else cout << rs << '\n';
    return 0;
}
