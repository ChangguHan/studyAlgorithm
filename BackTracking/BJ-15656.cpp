// 중복 순열 인덱스

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nums[20];
int N,M;
vector<int> v;

void dfs() {
    if(v.size() == M) {
        for (int x : v) cout << nums[x] << ' ';
        cout << '\n';
        return;
    }
    for (int i=1; i<=N; i++) {
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
