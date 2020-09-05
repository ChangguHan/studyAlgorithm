// segment + lazy

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> tree;
vector<int> lazy;

void lazy_update(int node, int st, int en) {
    if(lazy[node]!= 0) {
        if(lazy[node]%2==0) lazy[node] = 0;
        else {
            if(st != en) {
                tree[node] = (en-st+1) - tree[node];
                lazy[node*2]++;
                lazy[node*2+1]++;
            } else {
                if(tree[node]==0) tree[node]=1;
                else tree[node] = 0;
            }
        }
        lazy[node] =0;
    }
}

void update(int node, int st, int en, int li, int ri) {
    lazy_update(node, st, en);
    if(ri < st || en < li) return;
    if(li <= st && en <= ri) {
        tree[node] = (en-st+1) - tree[node];
        if(st != en) {
            lazy[node*2]++;
            lazy[node*2+1]++;
        }
        return;
    }
    int mid = (st+en)/2;
    update(node*2, st,mid, li, ri);
    update(node*2+1, mid+1,en, li, ri);
    tree[node] = tree[node*2] + tree[node*2+1];
    return;
}



int chk(int node, int st, int en, int li, int ri) {
    lazy_update(node, st, en);
    if(ri < st || en < li) return 0;
    if(li <= st && en <= ri) return tree[node];

    int mid = (st+en)/2;
    int rsl = chk(node*2, st, mid, li, ri);
    int rsr = chk(node*2+1, mid+1, en, li, ri);
    return rsl + rsr;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M; cin >> N >> M;
    
    int h = ceil(log2(N));
    tree.resize(1<<(h+1));
    lazy.resize(1<<(h+1));
    

    for (int i=0; i<M; i++) {
        int a,b,c; cin >> a >> b >> c;
        if(a == 0) {
            update(1,0,N-1,b-1,c-1);
        } else {
            cout << chk(1,0,N-1,b-1,c-1) << '\n';
        }
        // MlgN, 1e5 * 

    }
    return 0;
}
