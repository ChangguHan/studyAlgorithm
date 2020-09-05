// 백트래킹 M개 조합
// 모든공간 퍼지도록

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[60][60];
int N,M;
vector<pair<int, int> > li;
vector<int > v;
int minv = 60;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int cal() {
    // bfs로 ㄲ
    // mapb 만들기
    int mapb[60][60];
    for (int j=0; j<N; j++) for (int i=0; i<N; i++) mapb[j][i] =map[j][i];
    int time = 0;
    queue<pair<int, int> > q;
    for(int x : v) {
        int ey = li[x].first;
        int ex = li[x].second;
        mapb[ey][ex] = 3;
        q.push(make_pair(ey,ex));

    }
    
    while(!q.empty()) {
        time++;
        int qsize = q.size();
        while(qsize--) {
            auto eq = q.front(); q.pop();
            int ey = eq.first;
            int ex = eq.second;
            for (int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];
                if(ny>=0 && ny<N && nx>=0 && nx<N) {
                    if(mapb[ny][nx] == 2 || mapb[ny][nx] == 0 ) {
                        mapb[ny][nx] = 3;
                        q.push(make_pair(ny,nx));
                    }
                }

            }

        }
        
    }

    for(int j=0; j<N; j++) {
        for(int i=0; i<N; i++) {
            if(mapb[j][i] == 0) return 60;
        }

    }
    return time-1;

}


void dfs(int dep) {
    if(dep==M) {

        minv = min(minv, cal());
        return;
    }

    int idx = -1;
    if(v.size()!=0) idx = v.back();
    for (int i= idx+1; i<li.size(); i++) {
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
        for (int i=0; i<N; i++ ) {
            cin >> map[j][i];
            if(map[j][i]==2) li.push_back(make_pair(j,i));
        }
    }

    dfs(0);
    if(minv != 60) cout << minv << '\n';
    else cout << -1 << '\n';



    return 0;
}
