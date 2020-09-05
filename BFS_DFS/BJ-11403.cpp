#include <iostream>

#define MAX 100
using namespace std;

int N;
int map[MAX][MAX+1];
int visit[MAX];

void dfs(int y, int x) {
    map[y][x] = 1;

    for (int i=0; i<N; i++) {
        if(map[x][i] == 1 && visit[i] == 0) {
            visit[i] = 1;
            dfs(y,i);
        }
    }
}

int main() {
    cin >> N;

    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            cin >> map[j][i];
        }
    }

    for (int j=0; j<N; j++ ) {
        fill(visit, visit+MAX, 0);
        for(int i=0; i<N; i++) {
            if(map[j][i] && visit[i] == 0) {
                visit[i]=1;
                dfs(j,i);
            }
        }
        
    }
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            cout << map[j][i] << ' ';
        }
        cout << '\n';
    }


    return 0;
}