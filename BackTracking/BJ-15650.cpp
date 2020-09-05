// 조합
#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> v;

void dfs() {
    if(v.size() == M) {
        for(int x : v) cout << x << ' ';
        cout << '\n';
    }
    int idx=0;
    if(v.size()!=0) idx = v.back();

    for(int i=idx+1; i<=N; i++) {
        v.push_back(i);
        dfs();
        v.pop_back();
    }
}


int main() {
    cin >> N >> M;
    dfs();
    return 0;
}
