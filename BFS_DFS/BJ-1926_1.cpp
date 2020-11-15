/**
 
 BOJ 1926
 - 그림 갯수와, 넓이 가장넓은것 넓이 출력
 - Flood fill, BFS
 - O(N+M), e3
 */

#include <iostream>
#include <queue>
using namespace std;

int map[510][510];
bool chk[510][510];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int N,M;
int bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y,x));
    int rs=0;
    chk[y][x] = 1;
    while(!q.empty()) {
        auto eq = q.front(); q.pop();
        rs++;
        for(int k=0; k<4; k++) {
            int ny = eq.first + dy[k];
            int nx = eq.second + dx[k];
            if(ny>=0 && ny<N && nx>=0 && nx<M) {
                if(map[ny][nx] == 1) {
                    if(chk[ny][nx]) continue;
                    
                    chk[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                }
                
            }
        }
    }
    
    return rs;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int j=0; j<N; j++) {
        for(int i=0; i<M; i++) {
            cin >> map[j][i];
        }
    }
    int maxv = 0;
    int cnt=0;
    for (int j=0; j<N; j++) {
        for(int i=0; i<M; i++) {
            if(map[j][i] == 1) {
                if(chk[j][i]) continue;
                cnt++;
                maxv = max(maxv, bfs(j,i));
            }
            
        }
    }
    
    cout <<cnt << '\n'<< maxv << '\n';
    return 0;
}
