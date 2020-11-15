

/**
 BOJ 4485
 - 다익스트라로 최소비용 검색
 */

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> ti3;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int N;
const int inf = 1e8+10;
int map[150][150];
bool chk[150][150];
int dist[150][150];
int dijk() {
    
    
    priority_queue<ti3, vector<ti3>, greater<ti3>> pq;
    dist[0][0] = map[0][0];
    pq.push({dist[0][0], 0,0});
    
    
    while(!pq.empty()) {
        int ec,ey, ex;
        tie(ec, ey,ex) = pq.top(); pq.pop();
        if(chk[ey][ex])  continue;
        chk[ey][ex] = 1;
        
        for(int k=0; k<4; k++) {
            int ny = ey + dy[k];
            int nx = ex + dx[k];
            if(ny>=0 && ny<N && nx>=0 && nx<N) {
                if(chk[ny][nx]) continue;
                if(dist[ny][nx] > ec + map[ny][nx]) {
                    dist[ny][nx] = ec + map[ny][nx];
                    pq.push({dist[ny][nx], ny, nx});
                }
            }
        }
    }
    
    return dist[N-1][N-1];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc=0;
    while(1) {
        tc++;
        fill(&map[0][0], &map[149][150], 0);
        fill(&chk[0][0], &chk[149][150], 0);
        fill(&dist[0][0], &dist[149][150], inf);
        cin >> N;
        if(N == 0) return 0;
        for(int j=0; j<N; j++) {
            for(int i=0; i<N; i++) {
                cin >> map[j][i];
            }
        }
        cout << "Problem " << tc << ": " << dijk() << '\n';
    }
    return 0;
}

