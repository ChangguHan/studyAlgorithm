// 그냥 합으로가면 시간초과날것 같아
// O(N^2), 1e10 >> 시초

// two pointer

#include <iostream>

using namespace std;
typedef long long ll;
// 1e8, 1e10 이면 오버플로 날수있음

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int inf = 100010;
    int nums[100010];
    int N,M;
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> nums[i];

    int st=0,en=0,sum=0;
    int rs=inf;

    while(1) {
        if(sum >= M) {
            rs = min(rs, en-st);
            sum -= nums[st++];
        } else if(en==N) break;
        else sum += nums[en++];
    }

    if(rs==inf) cout << 0 << '\n';
    else cout << rs << '\n';

    return 0;
}