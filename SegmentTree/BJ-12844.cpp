// xor segment, lazy

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<int> tree;
vector<int> lazy; 
int nums[500010];

int make(int node, int st, int en) {
    if(st == en) return tree[node] = nums[st];

    int mid = (st+en)/2;
    int rsl = make(node*2, st, mid);
    int rsr = make(node*2+1, mid+1, en);
    return tree[node] = rsl ^ rsr;
}
void lazy_update(int node, int st, int en) {
    if(lazy[node] !=0) {
        if((en-st+1)%2 !=0)tree[node] = tree[node] ^ lazy[node];
        if(st != en) {
            lazy[node*2] =  lazy[node*2] ^ lazy[node];
            lazy[node*2+1] =  lazy[node*2+1] ^ lazy[node];
        }
        lazy[node] = 0;
    }
    return;
}

void update(int node, int st, int en, int li, int ri, int val) {
    lazy_update(node, st, en);
    if(ri < st || en < li) return;
    if(li <= st && en <= ri) {
        if((en-st+1)%2!=0) tree[node] = tree[node] ^ val;
        if(st != en) {
            lazy[node*2] = lazy[node*2] ^ val;
            lazy[node*2+1] = lazy[node*2+1] ^ val;
        }
        return;
    }

    int mid = (st+en)/2;
    update(node*2, st, mid, li, ri, val);
    update(node*2+1, mid+1, en, li, ri, val);
    tree[node] = tree[node*2] ^ tree[node*2+1];
    return;
}
int chk(int node, int st, int en, int li, int ri) {
    lazy_update(node, st, en);
    if(ri < st || en < li) return 0;
    if(li <= st && en <=ri) return tree[node];

    int mid = (st+en)/2;
    int rsl = chk(node*2, st, mid, li, ri);
    int rsr = chk(node*2+1, mid+1, en, li, ri);
    return rsl ^ rsr;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for (int i=0; i<N; i++) cin >> nums[i];

    int h = ceil(log2(N));
    tree.resize(1<<(h+1));
    lazy.resize(1<<(h+1));
    make(1,0,N-1);

    int M; cin >> M;
    while(M--) {
        int a; cin >> a;
        if(a==1) {
            int b,c,d; cin >> b >> c >> d;
            update(1, 0, N-1, b,c, d);
        }  else {
            int b,c;
            cin >> b >> c;
            cout << chk(1,0,N-1,b,c) << '\n';
        }
    }



    return 0;
}