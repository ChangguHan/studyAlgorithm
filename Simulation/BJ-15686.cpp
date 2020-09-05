// 백트래킹 위치 조합 : 2^(M)
// 각 위치에서 최소거리 치킨집 확인 : N^2

// 치킨집마다 확인 N*M
// N=50, M=13 이니까 치킨집마다 확인하는게 빠르겠군
// O(NM2^M) : 650*1e3*8 = 5e6

#include <iostream>
#include <vector>

using namespace std;

int N,M;
int map[60][60];
vector<pair<int, int> > chick;
vector<pair<int, int> > home;
vector<int> v;
int minv = 3600*13;

int cal() {
    int rs=0;
    // 각 집에서
    for (auto eh : home) {
        // 각 치킨집까지
        int minv = 3600;
        for (int i : v) {
            auto ec = chick[i];
            minv = min(minv, abs(eh.first-ec.first) + abs(eh.second-ec.second));
        }
        rs += minv;
    }
    return rs;
}

void dfs(int dep) {
    if(dep==M) {
        minv = min(minv, cal());
        return;
    }

    int idx=-1;
    if(v.size() !=0) idx = v.back();

    for (int i=idx+1; i<chick.size(); i++) {
        v.push_back(i);
        dfs(dep+1);
        v.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            cin >> map[j][i];
            if(map[j][i] == 1) home.push_back(make_pair(j,i));
            if(map[j][i] == 2) chick.push_back(make_pair(j,i));
        }
    }

    // 조합
    dfs(0);

    cout << minv << '\n';


    return 0;
}
