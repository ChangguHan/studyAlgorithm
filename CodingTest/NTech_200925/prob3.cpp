#include <iostream>

// 세그먼트리로
// 제일 작은거 빼고 그 양쪽을 구하는걸로

#include <vector>
#include <cmath>
using namespace std;

// 최대 1e9, int 가능
vector<int> tree;
int nums[100010];
// bool chk[100010][100010];
int maket(int node, int st, int en) {
    if(st==en) {
        return tree[node]  = st;
    }

    int mid = (st+en)/2;
    int rsl = maket(node*2, st, mid);
    int rsr = maket(node*2+1, mid+1, en);
    if(nums[rsl]  >= nums[rsr]) return tree[node] = rsl;
    else return tree[node] =  rsr;
}
// 최대 인덱스 구하기
int find(int node, int st, int en, int li, int ri) {
    if(li < st || en < ri) return -1;
    if(li <= st && en <= ri) return tree[node];

    int mid = (st+en)/2;
    int rsl = find(node*2, st, mid, li, ri);
    int rsr = find(node*2+1, mid+1, en, li, ri);

    if(rsl ==  -1) return rsr;
    else if(rsr == -1) return rsl;
    else {
        if(nums[rsl] >= nums[rsr]) return rsl;
        else return rsr;
    }
}
int getMaxV(int node, int st, int  en, int li, int ri) {
    // chk[li][ri] = 1;
    if(ri==li+1) return 0;
    int ar = (ri-li-1) * min(nums[li],nums[ri]);

    // int maxidx = find(node, st, en, li+1, ri-1);
    // if(maxidx == -1) return ar;
    // 가장 작은것 기준으로 왼쪽 오른쪽 구하기
    if(li <= ri-1) {
    // if(li <= ri-1 && !chk[li][ri-1]) {
        
        int rsl = getMaxV(node, st, en, li, ri-1);
        ar = max(ar, rsl);
    }
    if (ri >= li + 1)
    // if (ri >= li + 1 && !chk[li+1][ri])
    {
        int rsr = getMaxV(node, st, en, li+1, ri);
        ar = max(ar, rsr);
    }

    return ar;

}

int solution(vector<int> histogram)
{
    int N = histogram.size();
    int h = ceil(log2(N));
    tree.resize(1<<(h+1));
    for(int i=0; i<histogram.size(); i++){
        nums[i] = histogram[i];
    }
    // 세그먼트리 생성, 가장 작은것 인덱스 반환
    maket(1,0,N-1);


    
    return getMaxV(1,0,N-1,0,N-1);
}
int main() {
    vector<int> histogram;

    // histogram.push_back(2);
    // histogram.push_back(2);
    // histogram.push_back(2);
    // histogram.push_back(3);

    histogram.push_back(6);
    histogram.push_back(5);
    histogram.push_back(7);
    histogram.push_back(3);
    histogram.push_back(4);
    histogram.push_back(2);

    cout << solution(histogram) << '\n';
    return 0;
}