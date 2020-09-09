#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M; cin >> N >> M;
    int nums[10010];
    for(int i=0; i<N; i++) cin >> nums[i];

    int st=0,en=0;
    int sum=0, cnt=0;
    
    while(1) {
        if(sum >= M) sum -= nums[st++];
        else if(en == N) break;
        else sum += nums[en++];

        if(sum==M) cnt++;
    }

    cout <<  cnt << '\n';
    return 0;
}