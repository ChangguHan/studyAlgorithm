// 명령 개수 K * 돌리는것 4*3 = 12
// 12K = 1e4
#include <iostream>

using namespace std;
int N,M,x,y,K;
int map[30][30];
int dice[][3] = {{-1,0,-1},{0,0,0},{-1,0,-1},{-1,0,-1}};
void turn(int d) {
    if(d==1) { // 동쪽
        if(x+1<M) {
            int tmp = dice[1][1];
            dice[1][1] = dice[1][0];
            dice[1][0] = dice[3][1];
            dice[3][1] = dice[1][2];
            dice[1][2] = tmp;
            x++;

            if(map[y][x] == 0) {
                map[y][x] = dice[3][1];
            } else {
                dice[3][1] = map[y][x];
                map[y][x] = 0;
            }
            cout << dice[1][1] << '\n';
        }
    } else if (d==2) { // 서쪽
        if(x-1>=0) {
            int tmp = dice[1][1];
            dice[1][1] = dice[1][2];
            dice[1][2] = dice[3][1];
            dice[3][1] = dice[1][0];
            dice[1][0] = tmp;
            x--;

            if(map[y][x] == 0) {
                map[y][x] = dice[3][1];
            } else {
                dice[3][1] = map[y][x];
                map[y][x] = 0;
            }
            cout << dice[1][1] << '\n';
        }

    } else if (d==3) { // 북쪽
        if(y-1>=0) {
            int tmp = dice[1][1];
            dice[1][1] = dice[2][1];
            dice[2][1] = dice[3][1];
            dice[3][1] = dice[0][1];
            dice[0][1] = tmp;
            y--;

            if(map[y][x] == 0) {
                map[y][x] = dice[3][1];
            } else {
                dice[3][1] = map[y][x];
                map[y][x] = 0;
            }
            cout << dice[1][1] << '\n';
        }

    }else if (d==4) { // 남쪽
        if(y+1<N) {
            int tmp = dice[1][1];
            dice[1][1] = dice[0][1];
            dice[0][1] = dice[3][1];
            dice[3][1] = dice[2][1];
            dice[2][1] = tmp;
            y++;

            if(map[y][x] == 0) {
                map[y][x] = dice[3][1];
            } else {
                dice[3][1] = map[y][x];
                map[y][x] = 0;
            }
            cout << dice[1][1] << '\n';
        }

    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> y >> x >> K;
    for (int j=0; j<N; j++) for(int i=0; i<M; i++) cin >> map[j][i];
    while(K--) {
        int d;
        cin >> d;
        turn(d);
    }


    return 0;
}
