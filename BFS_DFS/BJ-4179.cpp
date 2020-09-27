/**
 BOJ 4179
 불과, 지훈 위치 각각 BFS
 
 O(V+E)
 V= N^2
 E = 2*N^2;
 O(3*N^2)
 3e6 가능
 
 */


#include <iostream>
#include <queue>
#include <string>

using namespace std;

char map[1010][1010];

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
bool chk[1010][1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M; cin >> N >> M;
    
    queue<pair<int, int>> qf;
    queue<pair<int, int>> qj;
    for(int j=0; j<N; j++) {
        string s; cin >> s;
        for(int i=0; i<M; i++) {
            map[j][i] = s[i];
            if(s[i]=='F') qf.push(make_pair(j,i));
            if(s[i]=='J') {
                qj.push(make_pair(j,i));
                chk[j][i]=1;
            }
        }
    }
    int cnt=0;
    
    while(1) {
        cnt++;
        // j 먼저 옮김
        int jsize = qj.size();
        
        while(jsize--) {
            auto ejq = qj.front(); qj.pop();
            
            int ey = ejq.first;
            int ex = ejq.second;
            if(map[ey][ex] == 'F') continue;
            
            for(int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];
                if(ny>=0 && ny < N && nx>=0 && nx<M) {
                    if(map[ny][nx] == '.' && !chk[ny][nx]) {
                        chk[ny][nx]=1;
                        qj.push(make_pair(ny, nx));
                    }
                }else {
                    cout << cnt << '\n';
                    return 0;
                }
            }
            
        }
        if(qj.size()==0) {
            cout << "IMPOSSIBLE" <<'\n';
            return 0;
        }
        
        
        // fire 옮김
        int fsize = qf.size();
        while(fsize--) {
            auto eq = qf.front(); qf.pop();
            int ey =eq.first;
            int ex = eq.second;
            
            for(int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];
                if(ny >=0 && ny < N && nx>=0 && nx <M) {
                    if(map[ny][nx] == '.' || map[ny][nx] =='J') {
                        map[ny][nx] = 'F';
                        qf.push(make_pair(ny, nx));
                    }
                }
            }
        }
    }
    
    
    
    return 0;
}
