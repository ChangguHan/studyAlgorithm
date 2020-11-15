/**
 BOJ 4179
 - BFS로 탈출

 */

#include <iostream>
#include <queue>

using namespace std;

char map[1010][1010];
bool jchk[1010][1010];
bool fchk[1010][1010];

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int R,C; cin >> R >> C;
    queue<pair<int, int>> jack;
    queue<pair<int, int>> f;
    for(int j=0; j<R; j++) {
        for(int i=0; i<C; i++) {
            cin >> map[j][i];
            if(map[j][i] == 'J') {
                jack.push(make_pair(j,i));
                jchk[j][i] =1;
            }
            if(map[j][i] == 'F') f.push(make_pair(j,i));
        }
    }
    
    // 지훈 이동먼저
    // 불 번짐
    int time=0;
    
    
    while(!jack.empty()) {
        time++;
        int jsize = jack.size();
        while(jsize--) {
            auto eq = jack.front(); jack.pop();
            int ey = eq.first;
            int ex = eq.second;
            if(map[ey][ex] == 'F') continue;
            for(int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];
                if(ny>=0 && ny <R && nx>=0 && nx < C) {
                    if(map[ny][nx] == '.') {
                        if(jchk[ny][nx]) continue;
                        jchk[ny][nx] = 1;
                        jack.push(make_pair(ny, nx));
                    }
                } else {
                    cout << time << '\n';
                    return 0;
                }
            }
        }
        
        int fsize = f.size();
        while(fsize--) {
            auto ef = f.front(); f.pop();
            int ey = ef.first;
            int ex = ef.second;
            
            for(int k=0; k<4; k++) {
                int ny = ey+ dy[k];
                int nx = ex + dx[k];
                
                if(ny>=0 && ny<R && nx>=0 && nx < C) {
                    if(map[ny][nx] == '.' || map[ny][nx] == 'J') {
                        map[ny][nx] = 'F';
                        f.push(make_pair(ny, nx));
                    }
                }
            }
        }
        
        
        
        
        
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}
