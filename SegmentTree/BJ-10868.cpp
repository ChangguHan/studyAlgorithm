// 구간 최소값이니까 세그먼트 트리
// 삽입 O(NlgN)
// 조회 lgN
//O(NlgN + MlgN)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
vector<ll> tree;
ll nums[100010];

ll make(int node, int st, int en) {
    if(st==en) return tree[node] = nums[st];

    int mid = (st+en)/2;
    ll rsl = make(node*2, st,mid);
    ll rsr = make(node*2+1, mid+1, en);

    return tree[node] = min(rsl, rsr);
}

ll chk(int node, int st, int en, int li, int ri) {
    if(ri < st || en < li) return 1e9;
    if(li <= st && en <= ri) return tree[node];

    int mid = (st+en)/2;
    ll rsl = chk(node*2,st,mid,li,ri);
    ll rsr = chk(node*2+1, mid+1, en, li, ri);
    return min(rsl, rsr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M;

    // tree set
    int h = ceil(log2(N));
    tree.resize(1<<(h+1));

    for(int i=0; i<N; i++) cin >> nums[i];
    make(1,0,N-1);

    for (int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        cout << chk(1,0,N-1,a-1,b-1) << '\n';
    }


    return 0;
}
