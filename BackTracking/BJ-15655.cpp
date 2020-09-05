// 인덱스 조합
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
int nums[20];
vector<int> v;

void dfs() {
    if(v.size() == N) {
        for(int x : v) cout << nums[x] <<' ';
        cout << '\n';
        return;
    }
    int idx=0;
    if(v.size()!=0) idx = v.back();

    for(int i=idx+1; i<=M; i++) {
        v.push_back(i);
        dfs();

        v.pop_back();
    }

}

int main() {
    cin >> M >> N;
    for (int i=1; i<=M; i++) cin >> nums[i];
    sort(nums, nums+M+1);

    dfs();

    return 0;
}