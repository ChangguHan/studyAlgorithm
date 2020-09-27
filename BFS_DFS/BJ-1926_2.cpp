/**
 BOJ 1926
 flood fill
 */

#include <iostream>

using namespace std;

int map[510][510];
bool chk[510][510];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int N,M;
int maxv=0;
int rs=0;

void dfs(int y, int x) {
    chk[y][x]=1;
    rs++;
    for(int k=0; k<4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        
        if(ny>=0 && ny < N && nx>=0 && nx <M) {
            if(map[ny][nx] && !chk[ny][nx]) {
                dfs(ny,nx);
            }
        }
    }
    return;
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
    int cnt=0;
    for(int j=0; j<N; j++) {
        for(int i=0; i<M; i++) {
            if(map[j][i]==1 && !chk[j][i]) {
                cnt++;
                rs=0;
                dfs(j,i);
                maxv = max(maxv, rs);
            }
        }
    }
    cout << cnt << '\n';
    cout << maxv << '\n';
    return 0;
}
