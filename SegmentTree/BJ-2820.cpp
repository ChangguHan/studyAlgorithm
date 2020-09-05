// node를 상사번호로 관리하는것,
// 이렇게하면 안되고, 노드자체가 상사이어야함
#include <iostream>

using namespace std;
typedef long long ll;

// ll tree[500010];
// ll lazy[500010];
int tree[500010];
int lazy[500010];
int parent[500010];


void update(int node, int val) {
    // 여기가 일반적에서는 위에서부터 아래로 내려오면서,
    // lazy_update를 해주는 효과가 있잖아

    // lazy_update(node);
    lazy[node] +=val;
    // for(int x : child[node]) {
    //     lazy[x] += val;
    // }
    return;
}
// ll chk(int node) {
int chk(int node) {
    // 그냥 위에서부터 값만 가져오면 안되나
    int rs = tree[node];
    node = parent[node];
    while(node != 0) {
        rs += lazy[node];
        node = parent[node];
    }
    // lazy_update(node);
    return rs;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M; cin >> N >> M;
    // fill(parent, parent+500010, -1);

    for(int i=1; i<=N; i++) {
        int a; cin >> a;
        tree[i] = a;
        if(i!=1){
            int b; cin >> b;
            parent[i] = b;
        }
    }

    for(int i=1; i<=M; i++) {
        char a; cin >> a;
        if(a=='p') {
            int b,c; cin >> b >> c;
            update(b, c);
        }else {
            int b; cin >> b;
            cout << chk(b) << '\n';
        }
    }

    return 0;
}

// 이게 시간초과가 난다고??
// 시복 계산해보자
// 업데이트 : O(1)
// 확인 : O(N)
// O(M*N), 1e11
