// 인덱스, 조합, 값중복금지

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int nums[20];
vector<int> v;

void dfs() {
    if(v.size() == M) {
        for (int x : v) cout << nums[x] << ' ';
        cout << '\n';
    }
    int bef=-1;
    int idx=0;
    if(v.size()!=0) idx = v.back();
    for (int i=idx+1; i<=N; i++) {
        if(bef == nums[i]) continue;
        bef = nums[i];
        v.push_back(i);
        dfs();
        v.pop_back();
        
    }
}
int main() {
    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> nums[i];
    sort(nums, nums+N+1);
    dfs();

    return 0;
}