// Fenwick으로 다시한번 풀어봐자

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<ll> tree;
ll nums[1000001];

void update(int idx, ll diff) {
    while(idx < tree.size()) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

ll sumt(int idx) {
    ll rs=0;
    while(idx > 0) {
        rs += tree[idx];
        idx -=(idx & -idx);
    }
    return rs;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,K; cin >> N >> M >> K;
    
    tree.resize(N+1);
    for(int i=1; i<=N; i++) {
        cin >> nums[i];
        update(i, nums[i]);
    }
    
    for (int i=0; i<M+K; i++) {
        int a,b,c; cin >> a >> b >> c;
        if(a==1) {
            ll diff = c - nums[b];
            nums[b] = c;
            update(b,diff);
        } else {
            cout << sumt(c) - sumt(b-1) << '\n';
        }
    }


    return 0;
}