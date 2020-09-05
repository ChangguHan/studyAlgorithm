// chk 할때 벽부수는 경우와, 안부수는 경우를 구분하자
// 1은 0갈수있지만, 0은 1갈수 없음
// 작은건 갈수 있지만, 큰거로는 못감
// 시복 : NM*2 = 2e6

#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int chk[1010][1010];
int map[1010][1010];
int N,M;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(&chk[0][0], &chk[1009][1010], -1);
    cin >> N >> M;
    for (int j=0; j<N; j++) {
        string ip;
        cin >> ip;
        for (int i=0; i<M; i++) {
            map[j][i] = ip[i]-'0';
        }
    }

    queue<tuple<int, int, int> > q;
    q.push({0,0,1});
    chk[0][0] = 1;
    int time= 1;
    
    while(!q.empty()) {

        time++;
        int qsize = q.size();
        while(qsize--) {
            int ey, ex, ec;
            tie(ey,ex,ec) = q.front(); q.pop();
            for(int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];
                if(ny==N-1 && nx == M-1) {
                    cout << time << '\n';
                    return 0;
                }
                if(ny>=0 && ny<N && nx>=0 && nx<M) {
                    if(chk[ny][nx]>=ec) continue;
                    if(map[ny][nx] == 1 && ec == 1) {
                        chk[ny][nx] = 0;
                        q.push({ny,nx,0});
                    } else if(map[ny][nx] == 0){
                        chk[ny][nx] = ec;
                        q.push({ny,nx,ec});
                    }
                }
            }

        }
        


    }

    if(N==1 && M==1) cout << 1 << '\n';
    else cout << -1 << '\n';
    
    return 0;
}