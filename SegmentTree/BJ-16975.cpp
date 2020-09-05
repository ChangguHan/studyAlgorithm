// 여러개 업데이트, lazy
// 생성 NlgN, 
// 조회 lgN >> MlgN, 2e6
// 1e6씩 1e5번 더할수있으니 노드값은 ll

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector<ll> tree;
vector<ll> lazy;
ll nums[100010];

ll make(int node, int st, int en) {
    if(st==en) return tree[node] = nums[st];
    int mid = (st+en)/2;
    ll rsl = make(node*2, st, mid);
    ll rsr = make(node*2+1, mid+1, en);
    return tree[node] = rsl +rsr;
}
void lazy_update(int node, int st, int en) {
    if(lazy[node] != 0) {
        tree[node] += (en-st+1) * lazy[node];
        if(st != en) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    return;

}

void update(int node, int st, int en, int li, int ri, int diff) {
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
    int mid = (st+en)/2;
    update(node*2, st, mid, li, ri, diff);
    update(node*2+1, mid+1, en, li, ri, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
    return;

}

ll chk(int node, int st, int en, int idx) {
    lazy_update(node, st, en);
    if(idx<st || en < idx) return 0;
    if(st == en && st == idx) return tree[node];

    int mid = (st+en)/2;
    ll rsl = chk(node*2, st, mid, idx);
    ll rsr = chk(node*2+1, mid+1, en, idx);
    return rsl + rsr;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    for (int i=0; i<N; i++) cin >>nums[i];
    
    int h = ceil(log2(N));
    tree.resize(1<<(h+1));
    lazy.resize(1<<(h+1));

    make(1,0,N-1);

    int M; cin >> M;
    for(int i=0; i<M; i++) {
        int a; cin >> a;
        if(a==1) {
            int b,c,d; cin >>b>>c >>d;
            update(1,0,N-1,b-1,c-1,d);
        } else {
            int b; cin >>b;
            cout << chk(1,0,N-1,b-1) << '\n';
        }
    }

    return 0;
}