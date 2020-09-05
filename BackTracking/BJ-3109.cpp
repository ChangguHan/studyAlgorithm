#include <iostream>

#define MAX 10000
using namespace std;

int R,C, rs;
char map[MAX][500];
bool visit[MAX][500];
int dy[] = {-1,0,1};
int dx[] = {1,1,1};
bool eachAnswer;

void dfs(int j, int i) {

    if(i == C-1) {
        rs++;
        eachAnswer = true;
        return;
    }
    visit[j][i] = true;

    for (int k=0; k<3; k++) {
        int ny = j + dy[k];
        int nx = i + dx[k];
        if(ny>=0 && ny<R && nx>=0 && nx<C) {
            if(map[ny][nx] == '.' && visit[ny][nx] == false) {
                dfs(ny,nx);
                if(eachAnswer) return;
            }
        }

    }
}

int main() {

    cin >> R >> C;

    for (int j=0; j<R; j++) {
        for (int i=0; i<C; i++) {
            cin >> map[j][i];
        }
    }

    for (int j=0; j<R; j++) {
        eachAnswer = false;
        dfs(j,0);
    }

    cout << rs;

    return 0;
}