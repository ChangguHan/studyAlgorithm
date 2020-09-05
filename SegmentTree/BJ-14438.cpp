// segment tree, 최소값으로,
// 업데이트 시 , lgN동안, 최소값 비교해줌

// int로 해줘도 됨
// 생성 : NlgN
// 바꿈, 출력 : lgN
// O (NlgN + MlgN)
// O((M+N)lgN)
// 2e5 * 20, 4e6

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> tree;
int nums[100010];

int make(int node, int st, int en) {
    if(st==en) return tree[node] = nums[st];

    int mid = (st+en)/2;
    int rsl = make(node*2, st, mid);
    int rsr = make(node*2+1, mid+1, en);
    return tree[node] = min(rsl, rsr);
}

void update(int node, int st, int en, int idx, int val) {
    // 여기야, 왜냐하면
    // min값을 주기 때문에, idx 벗어나면 return 하는 것과 상관없이
    // min값을 계산해줌, 그니까 return 해주면 안되고, 
    if(idx<st || en <idx) return;
    if(st==en) {
        tree[node] = val;
        return;
    }
    int mid = (st+en)/2;
    update(node*2, st, mid, idx, val);
    update(node*2+1, mid+1, en, idx, val);
    
    tree[node] = min(tree[node*2], tree[node*2+1]);

    return;
}

int chk(int node, int st, int en, int li, int ri) {
    if(ri < st || en < li) return 100001;
    if(li <= st && en <= ri) return tree[node];

    int mid = (st+en) /2;
    int rsl = chk(node*2, st, mid, li, ri);
    int rsr = chk(node*2+1, mid+1, en, li, ri);
    return min(rsl, rsr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N;
    for(int i=0; i<N; i++) cin >> nums[i];

    int h = ceil(log2(N));
    tree.resize(1<<(h+1),100010);
    make(1,0,N-1);

    cin >> M;
    for (int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if(a==1) {
            update(1,0,N-1,b-1,c);
        } else {
            cout << chk(1,0,N-1,b-1,c-1) << '\n';
        }

    }

    return 0;
}