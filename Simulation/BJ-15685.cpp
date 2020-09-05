// 벡터에 넣고, 마지막 점을 기준으로 돌리면 됨

#include <iostream>
#include <vector>

using namespace std;

int N;
int x,y,d,g;
bool map[101][102];
int dy[] = {0,-1,0,1};
int dx[] = {1,0,-1,0};
int cnt=0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(&map[0][0], &map[100][102], false);
    

    cin >> N;
    while (N--) {
        cin >> x >> y >> d >> g;
        vector< pair<int, int> > v;
        v.push_back(make_pair(y,x));
        v.push_back(make_pair(y+dy[d],x+dx[d]));
        map[y][x] = true;
        map[y+dy[d]][x+dx[d]] = true;
    
        while (g--) {
            int ly = v.back().first;
            int lx = v.back().second;
            int evsize = v.size();
            for (int i=evsize-2; i>=0; i--) {
                int ey = v[i].first;
                int ex = v[i].second;

                int ny = ly - (lx-ex);
                int nx = lx +(ly-ey);
                v.push_back(make_pair(ny,nx));
                map[ny][nx] = true;
            }
        }
    }

    for (int j=0; j<100; j++) {
        for (int i=0; i<100; i++) {
            if(map[j][i] && map[j][i+1] && map[j+1][i] && map[j+1][i+1]) cnt++;
        }
    }

    cout << cnt << '\n';

}
