
// map 1씩 줄이지말고
// 경계 1씩 늘려서 고립 영역구하자

#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[310][310];
bool chk[310][310];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

void bfs(int y, int x) {
    queue<pair<int, int> > q;
    q.push(make_pair(y,x));
    int subt[310][310];
    fill(&subt[0][0],&subt[N-1][M], 0);

    while(!q.empty()) {
        int ey = q.front().first;
        int ex = q.front().second; q.pop();
        int adjcnt=0;
        for (int k=0; k<4; k++) {
            int ny = ey + dy[k];
            int nx = ex + dx[k];
            if(ny>=0 && ny<N && nx>=0 && nx <M) {
                if(map[ny][nx] == 0) adjcnt++;
                if(map[ny][nx]>0 && chk[ny][nx] == false) {
                    chk[ny][nx] = true;
                    q.push(make_pair(ny,nx));
                }

            }
            

        }
        subt[ey][ex] = adjcnt;
        
    }
    for (int j=0; j<N; j++) {
        for (int i=0; i<M; i++) {
            if(map[j][i] !=0 && subt[j][i] !=0) {
                map[j][i] -= subt[j][i];
                if(map[j][i] <0 ) map[j][i] = 0;

            }
        }
    }


}

int dfs(int t) {
    // 분리되면 t로 return;
    fill(&chk[0][0], &chk[N-1][M], false);
    int cnt=0;
    for (int j=0; j<N; j++) {
        for (int i=0; i<M; i++) {
            if(map[j][i] > 0 && chk[j][i] == false) {
                chk[j][i] = 1;
                bfs(j,i);
                cnt++;
            }
        }
    }
    if(cnt>1) return t;
    if(cnt==0) return 0;
    // 다녹을때 신경써주기

    return dfs(t+1);

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int j=0; j<N; j++) for(int i=0; i<M; i++) cin >> map[j][i];

    cout << dfs(0) << '\n';


    return 0;
}