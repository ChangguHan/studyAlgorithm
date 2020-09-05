// 인덱스 순열
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nums[15];
int N,M;
vector<int> v;

void dfs() {
    if(v.size()==N) {
        for(int x : v) cout << nums[x] << ' ';
        cout << '\n';
        return;
    }
    bool sw=false;
    for (int i=1; i<=M; i++ ) {
        sw=false;
        for(int x : v ) {
            if(x==i) {
                sw=true;
                break;
            }
        }
        if(sw) continue;
        v.push_back(i);
        dfs();
        v.pop_back();
    }
}

int main() {
    cin >> M >> N;
    for (int i=1; i<=M; i++) cin >> nums[i];
    sort(nums,nums+M+1);

    dfs();


    return 0;
}