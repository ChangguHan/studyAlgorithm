
// bfs로 연속된것 갯수 검사 >> MN * MN


#include <iostream>
#include <string>
#include <vector>

using namespace std;

char map[12][9];
bool chk[12][9];

int eachans;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int ec;
vector<pair<int, int> > v;

void dfs(int y, int x,char color) {
    v.push_back(make_pair(y, x));
    chk[y][x] = 1;
    for (int k=0; k<4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(ny>=0 && ny<12 && nx >=0 && nx <6) {
            if(map[ny][nx] == color && chk[ny][nx] == 0) {
                
                dfs(ny, nx, color);
                
            }
        }
    }

}

bool puyo() {
    bool rs=false;
    fill(&chk[0][0], &chk[11][9], false);
    eachans=0;
    
    for (int j=0; j<12; j++) {
        for (int i=0; i<6; i++) {
            if(!chk[j][i] && map[j][i] != '.') {
                ec=1;
                v.clear();
                
                dfs(j,i,map[j][i]);
                if(v.size() >=4) {
                    rs=1;
                    // 지우기
                    for (int k=0; k<v.size(); k++) {
                        map[v[k].first][v[k].second] = '.';
                    }

                }
            }
        }
    }
    if(rs==0) return rs;
    // rs 1이면 빈칸 내리고, return 1;
    for (int i=0; i<6; i++) {
        int empty = 11;
        for (int j=11; j>=0; j--) {
            
            if(map[j][i] != '.') {
                if(empty == j) {
                    empty--;
                    continue;
                }
                map[empty][i] = map[j][i];
                map[j][i] = '.';
                empty--;
            }
        }
        
    }
    return 1;

}

int main() {
    for (int j=0; j<12; j++) {
        string ip;
        cin >> ip;
        for (int i=0; i<6; i++) map[j][i] = ip[i];
    }

    int ans=0;
    while(puyo()) ans++;

    cout << ans << '\n';

}