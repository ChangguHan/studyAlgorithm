#include <iostream>
#include <string>
#include <queue>

#define MAX 50
using namespace std;


// 물먼저 그다음 고슴
// bfs
char map[MAX][MAX+1];
int R,C;
queue<pair<int, int> > qs;
queue<pair<int, int> > qw;
int dy[] = {0,-1,0,1};
int dx[] = {1,0,-1,0};

int main() {
    cin >> R >> C;
    string ip;
    int cnt=0;
    bool endflag=false;
    for (int j=0; j<R; j++) {
        cin >> ip;
        for (int i=0; i<ip.length(); i++) {
            map[j][i] = ip[i];
            if(ip[i] == 'S') qs.push(make_pair(j,i));
            if(ip[i] == '*') qw.push(make_pair(j,i));
        }        
    }

    while(qs.size()) {
        cnt++;
        int qssize = qs.size();
        int qwsize = qw.size();

        for (int i=0; i<qwsize; i++) {
            // 물먼저
            int wey = qw.front().first;
            int wex = qw.front().second;
            qw.pop();
            for (int k=0; k<4; k++ ) {
                int wny = wey + dy[k];
                int wnx = wex + dx[k];

                if(wny >=0 && wny <R && wnx >=0 && wnx < C) {
                    if(map[wny][wnx] == '.' || map[wny][wnx] == 'S') {
                        map[wny][wnx] = '*';
                        qw.push(make_pair(wny,wnx));
                    }
                }
            }
        }
        
        for (int i=0;i<qssize; i++) {
            int ey = qs.front().first;
            int ex = qs.front().second;
            qs.pop();

            for (int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];

                if(ny>=0 && ny<R && nx>=0 && nx < C) {
                    if(map[ny][nx] == 'D') {
                        endflag = true;
                        break;
                    }
                    if(map[ny][nx] == '.') {
                        map[ny][nx] = 'S';
                        qs.push(make_pair(ny, nx));
                    }
                }
            }
            if(endflag) break;
        }
        if(endflag) break;
    }
    if(endflag) cout << cnt << '\n';
    else cout << "KAKTUS" << '\n';
    
    


    return 0;
}