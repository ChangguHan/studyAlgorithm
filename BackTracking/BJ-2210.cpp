// 모든 위치에서 시작해서
// 각 방향으로 출발해서, 겹치지 않게
// 5칸이 끝났을경우, 이미 있는게 아니라면 값 넣기

// N^2 * 4^N * N
// 5^3 * 2^10
// 125 * 1e3

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> rs;
int map[10][10];
bool visit[10][10];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

void dfs(int y, int x, int dep) {
    if(dep==6) {
        int num=0;
        for(int i=0; i<6; i++) {
            num += v[i] * pow(10,5-i);
        }
        vector<int>::iterator it = find(rs.begin(), rs.end(), num);
        if(it==rs.end()) rs.push_back(num);

        return;
    }

    for (int k=0; k<4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(ny>=0 && ny<5 && nx>=0 && nx<5) {
            
            // visit[ny][nx]=1;
            v.push_back(map[ny][nx]);
            dfs(ny,nx,dep+1);
            // visit[ny][nx]=0;
            v.pop_back();
            

            // if(visit[ny][nx]==false ) {
            //     visit[ny][nx]=1;
            //     v.push_back(map[ny][nx]);
            //     dfs(ny,nx,dep+1);
            //     visit[ny][nx]=0;
            //     v.pop_back();
            // }
        }

    }



}
int main() {
    for (int j=0; j<5; j++) {
        for (int i=0; i<5; i++) {
            cin >> map[j][i];
        }
    }

    for (int j=0; j<5; j++) {
        for (int i=0; i<5; i++) {
            v.clear();
            fill(&visit[0][0], &visit[9][10], 0);
            v.push_back(map[j][i]);
            visit[j][i] =1;
            dfs(j,i,1);

        }
    }

    cout << rs.size() << '\n';

    return 0;
}