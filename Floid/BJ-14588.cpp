// 각각 1인것만 먼저 놓고, Floid 처리

#include <iostream>

using namespace std;

const int inf = 1e5;
int N;
int lf[310];
int ll[310];
int map[310][310];

int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> lf[i];
        cin >> ll[i];
    }
    fill(&map[0][0], &map[309][310], inf);

    for (int i=1; i<=N; i++) {
        for (int j=i+1; j<=N; j++) {
            //첫 수가 앞에있는경우
            if((ll[i] >= lf[j] && lf[j] >= lf[i]) || 
            // 첫 수가 뒤에있는경우
            (lf[i] >= lf[j] && lf[i] <=ll[j] )) {
                map[i][j] = 1;
                map[j][i] = 1;
            }
        }
    }
    for(int i=1; i<=N; i++) map[i][i]=0;

    for (int k=1; k<=N; k++)
        for (int j=1; j<=N; j++)
            for (int i=1; i<=N; i++) {
                if(map[j][i] > map[j][k] + map[k][i]) {
                    // if(j==3 && i == 5 ){

                    // }
                    map[j][i] = map[j][k] + map[k][i];
                    // map[i][j] = map[j][k] + map[k][i];
                }
            }

    int Q;
    cin >> Q;
    while(Q--) {
        int a,b;
        cin >> a >> b;
        if(map[a][b] == inf) cout <<-1 << '\n';
        else cout << map[a][b] << '\n';
    }

    return 0;
}