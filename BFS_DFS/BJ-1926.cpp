#include <iostream>
#include <queue>

using namespace std;

int map[510][510];
bool chk[510][510];
int n,m;
int maxv=0;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int bfs(int y, int x) {
    int ecnt=0;
    ecnt++;
    queue<pair<int, int> > q;
    q.push(make_pair(y,x));
    while(!q.empty()) {
        auto eq = q.front(); q.pop();
        int ey = eq.first;
        int ex = eq.second;
        for (int k=0; k<4; k++) {
            int ny = ey + dy[k];
            int nx = ex + dx[k];
            if(ny>=0 && ny<n && nx>=0 && nx<m) {
                if(chk[ny][nx]== false && map[ny][nx]) {
                    q.push(make_pair(ny,nx));
                    chk[ny][nx] = 1;
                    ecnt++;
                } 
            }
        }
    }
    return ecnt;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int j=0; j<n; j++) {
        for (int i=0; i<m; i++) {
            cin >> map[j][i];
        }
    }

    int cnt = 0;

    for (int j=0; j<n; j++) {
        for (int i=0; i<m; i++) {
            if(map[j][i] && chk[j][i]==false) {
                cnt++;
                chk[j][i] = 1;
                maxv = max(maxv, bfs(j,i));
                
            }

        }
    }

    cout << cnt << '\n' << maxv << '\n';

    return 0;
}