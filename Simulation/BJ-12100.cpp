// 모든 경우 해보는수밖에없지 않나
// 백트래킹
// 방향 돌리는거랑, 위로 움직일때만 잘 계산해주면 될듯


#include <iostream>
#include <algorithm>

using namespace std;

int N;
int map[30][30];
int maxv= 0;

void topup() {
    // 위에서부터 같은게 아래에 있으면 합치고
    for (int i=0; i<N; i++) {
        for (int j=0; j<N-1; j++) {
            // 현재 다음껏만 보게 되어있음.
            // 0일경우 그다음껏도
            if(map[j][i] != 0) {
                int nxt = j+1;
                while(map[nxt][i] == 0) {
                    if(nxt==N-1) break;
                    nxt++;
                    
                }
                if(map[j][i] == map[nxt][i]) {
                    map[j][i] += map[nxt][i];
                    map[nxt][i] = 0;
                }
            }
            
        }
        // 위로 밀어줌
        int idx=-1;
        for (int j=0; j<N; j++) {
            if(map[j][i] ==0 ) {
                if(idx==-1) idx = j;
            }
            else {
                if(idx != -1) {
                    map[idx][i] = map[j][i];
                    map[j][i] = 0;
                    j = idx;
                    idx = -1;
                }
                
            }
        }
    }

}

void turn() {
    int mapb[30][30];
    for (int j=0; j<N; j++) for (int i=0; i<N; i++) mapb[j][i] = map[j][i];
    for (int j=0; j<N; j++) for (int i=0; i<N; i++) map[j][i] = mapb[N-1-i][j];
    return;
}
void dfs(int depth) {
    if(depth==5) {
        maxv = max(maxv,*max_element(&map[0][0], &map[N-1][N]));
        return;
    }
    int mapb[30][30];
    for (int j=0; j<N; j++) for (int i=0; i<N; i++) mapb[j][i] = map[j][i];

    topup();
    dfs(depth+1);
    
    for (int j=0; j<N; j++) for (int i=0; i<N; i++) map[j][i] = mapb[j][i];
    turn();
    topup();
    dfs(depth+1);
    
    for (int j=0; j<N; j++) for (int i=0; i<N; i++) map[j][i] = mapb[j][i];
    turn();
    turn();
    topup();
    dfs(depth+1);

    for (int j=0; j<N; j++) for (int i=0; i<N; i++) map[j][i] = mapb[j][i];
    turn();
    turn();
    turn();
    topup();
    dfs(depth+1);

}

int main() {
    cin >> N;
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            cin >> map[j][i];
        }
    }

    dfs(0);

    cout << maxv << '\n';


    return 0;
}