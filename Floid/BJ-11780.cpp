#include <iostream>
#include <vector>

using namespace std;

const int inf = 1e7+10;
int n,m;
int gd[110][110];
int nxt[110][110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(&gd[0][0], &gd[109][110], inf);

    cin >> n >> m;
    for (int i=1; i<=n; i++) gd[i][i] = 0;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;

        gd[a][b] = min(c, gd[a][b]);
        nxt[a][b] = b;
    }

    for(int k=1; k<=n; k++)
        for(int j=1; j<=n; j++)
            for (int i=1; i<=n; i++) {
                if(gd[j][i] > gd[j][k] + gd[k][i]) {
                    gd[j][i] = gd[j][k] + gd[k][i];
                    nxt[j][i] = nxt[j][k];
                }
            }

    for (int j=1; j<=n; j++){
        for (int i=1; i<=n; i++) {
            if(gd[j][i] == inf) cout << 0 << ' ';
            else cout << gd[j][i] << ' ';
        }
        cout <<'\n';
    }

    for (int j=1; j<=n; j++)
        for (int i=1; i<=n; i++) {
            if(gd[j][i] == 0 || gd[j][i] == inf) {
                cout << 0 << '\n';
                continue;
            }
            vector<int> v;
            int cur = j;
            while(cur != i) {
                v.push_back(cur);
                cur = nxt[cur][i];
            }
            v.push_back(cur);

            cout << v.size() << ' ';
            for (int x : v) cout << x <<' ';
            cout <<'\n';

        }
        


    return 0;
}