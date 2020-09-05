// 그냥 DP로 풀면 : O(NM), 1e10; 시간초과
// segmenttree, O(N + MlgN) 

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll num[1000010];
vector<ll> tree;

ll make(int node, int st, int en) {
    if(st==en) return tree[node] = num[st];

    int mid = (st+en)/2;
    ll rsL = make(node*2, st,mid);
    ll rsR = make(node*2+1, mid+1, en);
    return tree[node] = rsL + rsR;
}

void update(int node, int st, int en, int idx, ll diff) {
    if(idx<st || en < idx) return;
    tree[node] += diff;
    if(st != en) {
        int mid = (st+en)/2;
        update(node*2, st,mid,idx,diff);
        update(node*2+1, mid+1,en,idx,diff);
    }
}

ll treesum(int node, int st, int en, int lv, int rv) {
    if(rv<st || en < lv) return 0;
    if(lv <= st && en <= rv) return tree[node];

    int mid = (st+en)/2;
    ll rsL = treesum(node*2, st, mid, lv, rv);
    ll rsR = treesum(node*2+1, mid+1,en, lv, rv);

    return rsL + rsR;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,K;
    cin >> N >> M >> K;
    for (int i=0; i<N; i++) {
        cin >> num[i];
    }
    
    // tree setting
    int h = ceil(log2(N));
    tree.resize(1<<(h+1));
    make(1,0,N-1);

    for (int i=0; i<M+K; i++) {
        int a,b,c;
        cin >> a >> b >> c;

        if(a==1) {
            ll diff = c - num[b-1];
            num[b-1] = c;
            update(1,0,N-1,b-1,diff);

        } else {
            cout << treesum(1,0,N-1,b-1,c-1) << '\n';
        }
    }


    return 0;
}