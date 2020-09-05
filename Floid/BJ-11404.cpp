// Floid

#include <iostream>

using namespace std;

const int inf = 1e7+10;
int map[110][110];
int n,m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill(&map[0][0], &map[109][110],inf);
    for(int i=1; i<=n; i++) map[i][i] = 0;
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        map[a][b] = min(c, map[a][b]);
    }
    for (int k=1; k<=n; k++) {
        for (int j=1; j<=n; j++) {
            for (int i=1; i<=n; i++) {
                if(map[j][i] > map[j][k] + map[k][i]) {
                    map[j][i] = map[j][k] + map[k][i];
                }
            }
        }
    }

    for (int j=1; j<=n; j++) {
        for (int i=1; i<=n; i++) {

            if(map[j][i] == inf) cout << 0 << ' ';
            else cout << map[j][i] << ' ';
        }
        cout << '\n';
    }


    return 0;
}