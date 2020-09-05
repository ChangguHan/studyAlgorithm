// 그래프탐색으로

#include <iostream>

using namespace std;

int map[110][110];
bool chk[110][110];
int N;
int oy,ox;

void dfs(int y, int x) {
    for(int i=0; i<N; i++) {
        if(map[x][i]==1 && chk[x][i]==0) {
            chk[x][i] = 1;
            map[y][i] = 1;
            dfs(y,i);
        }
    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++){
            cin >> map[j][i];
        }
    }

    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++){
            if(map[j][i]==1) {
                fill(&chk[0][0], &chk[109][110],false);
                dfs(j,i);
            }
        }
    }

    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++){
            cout << map[j][i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}