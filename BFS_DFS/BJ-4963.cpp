// 고립문제
// BFS랑, DFS 하나씩 풀어보자

#include <iostream>
#include <queue>
using namespace std;

int map[60][60];
bool chk[60][60];
int rs=0;
int N,M; 
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
void bfs(int j, int i) {
    queue<pair<int, int> > q;
    q.push(make_pair(j,i));
    chk[j][i]=1;

    while(!q.empty()) {
        auto eq = q.front(); q.pop();
        int ey = eq.first;
        int ex = eq.second;
        for(int k=0; k<8; k++) {
            int ny = ey + dy[k];
            int nx = ex + dx[k];
            if(ny>=0 && ny<N && nx>=0 && nx<M) {
                if(map[ny][nx]==1 && !chk[ny][nx])  {
                    q.push(make_pair(ny, nx));
                    chk[ny][nx]=1;
                }
            }
        }

    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        
        cin >>M >> N;
        if(M==0 && N==0) return 0;
        for (int j=0; j<N; j++) {
            for(int i=0; i<M; i++) {
                cin >> map[j][i];
            }
        }

        rs=0;
        fill(&chk[0][0], &chk[N-1][M], false);

        for(int j=0; j<N; j++) {
            for(int i=0; i<M; i++) {
                if(map[j][i] ==1 && !chk[j][i]) {
                    rs++;
                    bfs(j,i);
                }
            }

        }

        cout << rs << '\n';



    }
    


    return 0;
}