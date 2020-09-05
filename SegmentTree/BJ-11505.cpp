// 세그먼트 트리 곱셈으로 해보자

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

const ll modv = 1000000007;
vector<ll> tree;
int num[1000010];

ll make(int node, int st, int en) {
    if(st==en) return tree[node] = num[st];

    int mid = (st+en)/2;
    ll rsL = make(node*2, st, mid);
    ll rsR = make(node*2+1, mid+1, en);
    return tree[node] = rsL*rsR%modv;
}

void update(int node, int st, int en, int idx, ll diff) {
    if(idx<st || en < idx) return;
    
    if(st != en) {
        int mid = (st+en)/2;
        update(node*2, st, mid, idx, diff);
        update(node*2+1, mid+1, en, idx, diff);
    }

    // 일반케이스일때 diff를 곱해주는 곳이 없음
    if(st==en && st == idx) {
        tree[node] = tree[node] = diff %modv;
    } else {
        
        tree[node] = (tree[node*2] * tree[node*2+1] ) % modv;
    }

    
    
}

ll treesum(int node, int st, int en, int lv, int rv) {
    if(rv<st || en < lv) return 1;
    if(lv <= st && en <= rv) return tree[node];

    int mid = (st+en)/2;
    ll rsL = treesum(node*2, st, mid, lv, rv);
    ll rsR = treesum(node*2+1, mid+1, en, lv, rv);

    return rsL * rsR %modv;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,K;
    cin >> N >> M >> K;
    for (int i=0; i<N; i++) cin >> num[i];

    //tree setting;
    int h = ceil(log2(N));
    tree.resize(1<<(h+1),1);

    make(1,0,N-1);

    for (int i=0; i<M+K; i++) {
        int a,b,c;
        cin >>a >> b >> c;
        if(a==1) {

            // diff가 float인게 좀 걸리는데
            num[b-1] = c;
            update(1,0,N-1,b-1,c);
        } else {
            cout << treesum(1,0,N-1,b-1,c-1) << '\n';
        }



    }
    

    return 0;
}