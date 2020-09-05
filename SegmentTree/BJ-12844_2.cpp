#include <bits/stdc++.h>
#define MAX_SIZE 500001

using namespace std;

vector<int> arr;
struct tree
{
    int value = 0, lazy = 0;
}tree[MAX_SIZE * 4];

int init(int start, int end, int node)
{
    if(start == end) return tree[node].value = arr[start];

    int mid = (start + end) / 2;
    return tree[node].value = init(start, mid, node*2) ^ init(mid+1, end, node*2+1);
}
void propagation(int start, int end, int node)
{
    int lazy = tree[node].lazy;
    if(lazy){
        if((end-start+1)%2 == 1) tree[node].value ^= lazy;
        if(start != end){
            tree[node*2].lazy ^= lazy;
            tree[node*2+1].lazy ^= lazy;
        }
        tree[node].lazy = 0;
    }
}
void update(int start, int end, int node, int left, int right, int i_xor)
{
    propagation(start, end, node);
    if(end < left || right < start) return;
    if(left <= start && end <= right){
        if((end-start+1)%2 == 1) tree[node].value ^= i_xor; /// 홀수개이면
        if(start != end){
            tree[node*2].lazy ^= i_xor;
            tree[node*2+1].lazy ^= i_xor;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node*2, left, right, i_xor);
    update(mid+1, end, node*2+1, left, right, i_xor);

    tree[node].value = tree[node*2].value ^ tree[node*2+1].value;
}
int cal_xor(int start, int end, int node, int left, int right) /// xor 계산
{
    propagation(start, end, node);

    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node].value;
    int mid = (start + end) / 2;
    return cal_xor(start, mid, node*2, left, right) ^ cal_xor(mid+1, end, node*2+1, left, right);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    arr.resize(n+1);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    init(0, n-1, 1);
    cin >> m;
    for(int i = 0; i < m; i++){
        int code, start, end;
        cin >> code >> start >> end;
        if(code == 1){
            int k;
            cin >> k;
            if(start > end) swap(start, end);
            update(0, n-1, 1, start, end, k);
        }
        else{
            if(start > end) swap(start, end);
            cout << cal_xor(0, n-1, 1, start, end) << '\n';
        }
    }
}
