// 중복순열
#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> v;

void dfs() {
    if(v.size() == M) {
        for(int x : v) cout << x <<' ';
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
    dfs();
    return 0;
}