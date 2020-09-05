// dfs로 해보자
// O(V+E)
// E = V*8, O(8*V^2)

#include <iostream>

using namespace std;

int map[60][60];
bool chk[60][60];
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int N,M; 
void dfs(int j, int i) {
    for(int k=0; k<8; k++) {
        int ny = j+dy[k];
        int nx = i + dx[k];
        if(ny>=0 && ny<N && nx>=0 && nx<M) {
            if(map[ny][nx] && !chk[ny][nx]) {
                chk[ny][nx] = 1;
                dfs(ny,nx);
            }
        }
        
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin >> M >> N;
        if(N==0 && M==0) return 0;
        fill(&chk[0][0], &chk[59][60],0);

        for(int j=0; j<N; j++) {
            for(int i=0; i<M; i++) {
                cin >> map[j][i];
            }
        }
        int rs=0;
        for(int j=0; j<N; j++) {
            for (int i=0; i<M; i++) {
                if(map[j][i] == 1 && !chk[j][i]) {
                    rs++;
                    chk[j][i]=1;
                    dfs(j,i);
                    
                }
            }
        }

        cout << rs <<'\n';
        

    }
    

    return 0;
}