// 경치좀 쌓아볼까
// lazy

// 시간복잡도 계산하는 습관들이자, 귀찮아도
// 그냥 배열로 할겨우
// 합구하는데, O(N)
// M번 합구하면 O(NK + M)
// 1e10 >> 100초, 시간초과

// lazy 이용할경우.
// 초반 세팅, O(NlgN)
// M번 업데이트 및  K번 합구함
// O(NlgN+M+K)
// 1e6*20 + 1e4 + 1e4
// 2e7, 시간안초과

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector<ll> tree;
vector<ll> lazy;
// 입력으로 주어지는 수, e18, ll 써야됨
ll nums[1000001];

ll make(int node, int st, int en) {
    if(st==en) return tree[node] = nums[st];

    int mid = (st+en)/2;
    ll rsl = make(node*2, st, mid);
    ll rsr = make(node*2+1, mid+1, en);
    return tree[node] = rsl+rsr;
}
void lazy_update(int node, int st, int en) {
    if(lazy[node] !=0 ) {
        tree[node] += (en-st+1) * lazy[node];
        if(st != en) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    return;
}
void update(int node, int st, int en, int li, int ri, ll diff) {
    lazy_update(node, st, en);
    if(ri < st || en < li) return;
    if(li <= st && en <= ri) {
        tree[node] += (en-st+1) * diff;
        if(st != en) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }

    int mid = (st + en) /2;
    update(node*2, st,mid, li, ri, diff);
    update(node*2+1, mid+1, en, li, ri, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
    return;
}

ll sumt(int node, int st, int en, int li, int ri) {
    lazy_update(node, st, en);
    if(ri < st || en < li) return 0;
    if(li <= st && en <= ri) return tree[node];
    
    int mid = (st+en)/2;
    ll rsl = sumt(node*2, st, mid, li, ri);
    ll rsr = sumt(node*2+1, mid+1, en, li, ri);
    return rsl + rsr;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,K;
    cin >> N >> M >> K;
    for (int i=1; i<=N; i++) cin >> nums[i];

    //setting
    int h = ceil(log2(N));
    tree.resize(1<<(h+1));
    lazy.resize(1<<(h+1));
    make(1,1,N);

    for (int i=0; i<M+K; i++) {
        int a;
        cin >> a;
        if(a==1) {
            int b,c,d; cin >> b >> c >> d;
            update(1,1,N,b,c,d);
        } else {
            int b,c; cin >> b >> c;
            cout << sumt(1,1,N,b,c) << '\n';
        }
    }

    return 0;
}