// 세그먼트 트리, 최대 최소로
// 시복구해보자
// 만들기 : O(NlgN)
// 조회 : MlgN
//O(lgN(N+M))
// 20 * 2e5, 4e6

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector<ll> maxtree;
vector<ll> mintree;
ll nums[100001];


ll maxmake(int node, int st, int en) {
    if(st==en) return maxtree[node] = nums[st];

    int mid = (st+en)/2;
    ll rsl = maxmake(node*2, st, mid);
    ll rsr = maxmake(node*2+1,mid+1, en);
    return maxtree[node] = max(rsl, rsr);
}

ll minmake(int node, int st, int en) {
    if(st==en) return mintree[node] = nums[st];

    int mid = (st+en)/2;
    ll rsl = minmake(node*2, st, mid);
    ll rsr = minmake(node*2+1,mid+1, en);
    return mintree[node] = min(rsl, rsr);
}
ll getmax(int node, int st, int en, int li, int ri) {
    if(ri < st || en < li) return 0;
    if(li <= st && en <= ri) return maxtree[node];

    int mid = (st+en)/2;
    ll rsl = getmax(node*2, st,mid, li, ri);
    ll rsr = getmax(node*2+1, mid+1,en, li, ri);
    return max(rsl, rsr);

}

ll getmin(int node, int st, int en, int li, int ri) {
    if(ri < st || en < li) return 1e9;
    if(li <= st && en <= ri) return mintree[node];

    int mid = (st+en)/2;
    ll rsl = getmin(node*2, st,mid, li, ri);
    ll rsr = getmin(node*2+1, mid+1,en, li, ri);
    return min(rsl, rsr);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M; cin >> N >> M;
    for (int i=0; i<=N-1; i++) cin >> nums[i];
    
    int h = ceil(log2(N));
    maxtree.resize(1<<(h+1));
    mintree.resize(1<<(h+1));
    maxmake(1,0,N-1);
    minmake(1,0,N-1);

    for(int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        cout << getmin(1,0,N-1,a-1,b-1) << ' ' << getmax(1,0,N-1,a-1,b-1) << '\n';
    }


    return 0;
}