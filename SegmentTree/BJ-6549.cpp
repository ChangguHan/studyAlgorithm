// 이게 문제로 나오면 풀 수 있을까?
// 문제 정리해두기

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

vector<ll> tree;
int nums[100010];
int n;
int make(int node, int st, int en) {
    if(st==en) {
        return tree[node] = st;
    }
    // 최소값 인덱스 넣어주기


    // 크기를 구해야돼,
    // min값에 너비 곱하기
    int mid = (st+en)/2;
    int rsl = make(node*2,st, mid);
    int rsr = make(node*2+1, mid+1, en);
    // 이렇게하면 다 꺠져
    if(nums[rsl] > nums[rsr]) return tree[node] = rsr;
    else return tree[node] = rsl;
}

int chkminidx(int node, int st, int en, int li, int ri) {
    if(ri < st || en < li) return 100009;
    if(li <= st && en <= ri) return tree[node];

    int mid = (st+en)/2;
    int lidx = chkminidx(node*2, st, mid, li, ri);
    int ridx = chkminidx(node*2+1, mid+1, en, li, ri);

    if(nums[lidx] < nums[ridx]) return lidx;
    else return ridx;


}

ll chkmax(int li, int ri) {
    if(li==ri) return nums[li];
    int minidx = chkminidx(1,0,n-1,li,ri);
    ll rs = nums[minidx] * (ri-li+1);

    if (li <= minidx-1) {
        // 여기서 최소 인덱스를 찾아야함
        // 구간 사이에 있는 최소 인덱스
        ll tmp = chkmax(li,minidx-1);
        rs = max(rs,tmp);
    }

    if(minidx+1 <= ri) {
        ll tmp = chkmax(minidx+1, ri);
        rs = max(rs,tmp);
    }

    return rs;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin >> n;
        if(n==0) break;
        fill(nums, nums+n+1,0);
        tree.clear();
        nums[100009] = 1e9;
        for(int i=0; i<n; i++) {
            cin >> nums[i];
        }

        int h = ceil(log2(n));
        tree.resize(1<<(h+1));
        make(1,0,n-1);
        
        cout << chkmax(0,n-1)<< '\n';
    }
    return 0;
}