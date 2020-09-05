#include <iostream>

using namespace std;

int map[21][21];
int dox[4][4];
int dy[] = {0,0,-1,1};
int dx[] = {1,-1,0,0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(&dox[0][0], &dox[3][3], 0);
    int N,M,x,y,K;
    cin >> N >> M >> x >> y >> K;
    for (int j=0; j<N; j++) {
        for (int i=0; i<M; i++) {
            cin >> map[j][i];
        }
    }
    while (K--) {
        int order;
        cin >> order;
        order--;
        int ny = y+dy[order];
        int nx = x + dx[order];
        if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
        y = ny;
        x = nx;
        //굴려
        switch(order) {
            case 0 :
                for (int i=2; i>=0; i--) {
                    dox[1][i+1] = dox[1][i];
                }
                dox[1][0] = dox[1][3];
                break;
            case 1 :
                
                
        }
        if (map[y][x] ==0) map[y][x] = dox[3][1];
        else {
            dox[3][1] = map[y][x];
            map[y][x] = 0;
        }

        cout << dox[1][1] << '\n';

    }


    return 0;
}