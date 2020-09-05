// 1을 포함한 조합을 사용해서
// 나머지 값과 최소값을 구하면 되지 않을까

// 조합 >> 2^N
// 2^20 >> 1e6;
// 팀 점수 나열, 1/4 * N^2
// 다른팀 구하는것, N * 1/4 * N^2

// 2^N * N^2 * 1(1+N)
// 1e6 * 4e2 * 20 = 8e8
// 가지치기 잘하면 될듯

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
int map[30][30];
vector<int> v;
int minv = 2000;
void dfs(int dep) {
    if(dep == N/2) {
        int sc1=0;
        int sc2=0;
        for (int y=0; y<N; y++) {
            // 벡터 안에 있으면
            // 벡터안에꺼 다더해줌
            vector<int>::iterator it = find(v.begin(), v.end(), y);
            if(it != v.end()) {
                for(int x : v) {
                    if(y==x) continue;
                    sc1 += map[y][x];
                }
            } else {
                for(int x=0; x<N; x++) {
                    // 없을경우에만 더해줌
                    if(y==x) continue;
                    vector<int>::iterator it2 = find(v.begin(), v.end(), x);
                    if(it2 == v.end()) sc2+=map[y][x];
                }
            }
        }
        
        minv = min(minv, abs(sc1-sc2));

        return;
    }
    int idx=v.back()+1;

    for(int i=idx; i<N; i++) {
        v.push_back(i);
        dfs(dep+1);
        v.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int j=0; j<N; j++) for (int i=0; i<N; i++) cin >> map[j][i];

    v.push_back(0);
    dfs(1);

    cout << minv << '\n';


    return 0;
}
