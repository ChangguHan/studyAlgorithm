// 최단거리

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int K,W,H;
int map[210][210];
int chk[210][210];
// bool chkh[210][210];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int dhy[] = {1,2,2,1,-1,-2,-2,-1};
int dhx[] = {2,1,-1,-2,-2,-1,1,2};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> W >> H;
    for (int j=0; j<H; j++) {
        for (int i=0; i<W; i++) {
            cin >> map[j][i];
        }
    }
    fill(&chk[0][0], &chk[209][210],-1);
    // fill(&chkh[0][0], &chkh[209][210],false);

    queue<tuple<int, int, int> > q;
    q.push({0,0,K});
    // chk[0][0] = 1;
    chk[0][0] = 0 ;
    int time = 0;
    while(!q.empty()) {
        time++;
        int qsize = q.size(); 
        while(qsize--) {
            int ey,ex,ek;
            tie(ey,ex,ek)= q.front(); q.pop();
            for(int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];
                if(ny>=0 && ny<H && nx>=0 && nx<W) {
                    if(ny==H-1 && nx == W-1) {
                        cout << time << '\n';
                        return 0;
                    }
                    if(chk[ny][nx]<ek && map[ny][nx] == 0) {
                        // 말 뛰는거랑 다르게 chk 가져가야할것같음
                        chk[ny][nx] = ek;
                        q.push({ny,nx,ek});
                    }
                }
            }
            if(ek>0) {
                for(int k=0; k<8; k++) {
                int ny = ey + dhy[k];
                int nx = ex + dhx[k];
                if(ny>=0 && ny<H && nx>=0 && nx<W) {
                    if(ny==H-1 && nx == W-1) {
                        cout << time << '\n';
                        return 0;
                    }
                    // if(!chkh[ny][nx]&& map[ny][nx] == 0) {
                    if(map[ny][nx] == 0 && chk[ny][nx] < ek-1) {
                        // 말 뛰는거랑 다르게 chk 가져가야할것같음
                        chk[ny][nx] = ek-1;
                        q.push({ny,nx,ek-1});
                    }
                }
            }
            }
        }
        

    }

    cout << -1 << '\n';

    return 0;
}