
// 백트해서, 4명이상 먼저 확인, 인접한거 확인

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[10][10];
int rs=0;
vector<pair<int, int> > v;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
void chk() {
    int cnt=0;
    for(auto x : v) {
        if(map[x.first][x.second]=='S') cnt++;
    }
    if(cnt<4) return;


    // 인접한걸 어떻게 알지?, 
    // 애초에 인접한걸 가져오는 방법이 있겠고
    // 각각 4방향으로 보내서 없는게 있으면 return
    // 이럼 안돼, 떨어져있어도, 서로만 붙어있으면 연결로나와

    // bfs로 풀면되지 않을까?
    bool chk[7] = {false, };
    queue<pair<int, int> > q;
    q.push(v[0]);
    chk[0] = 1;
    while(!q.empty()) {
        pair<int, int> eq = q.front(); q.pop();
        int ey = eq.first;
        int ex = eq.second;
        for (int k=0; k<4; k++) {
            int ny = ey + dy[k];
            int nx = ex + dx[k];
            for(int i=0; i<v.size(); i++) {
                if(ny == v[i].first && nx == v[i].second) {
                    if(chk[i]) break;
                    chk[i] = 1;
                    q.push(make_pair(ny,nx));
                    break;
                }
            }
        }
    }
    for (bool eb : chk) if(eb==0) return;
    rs++;
}

void dfs() {
    if(v.size() == 7) {
        chk();
        return;
    }

    int ey=0; int ex=-1;
    if(v.size() !=0) {
        ey = v.back().first;
        ex = v.back().second;
    }
    for (int j=ey; j<5; j++) {
        for (int i=ex+1; i<5; i++) {
            v.push_back(make_pair(j,i));
            dfs();
            v.pop_back();
        }
        ex = -1;
    }

}

int main() {
    for (int j=0; j<5; j++) {
        for (int i=0; i<5; i++) {
            cin >> map[j][i];
        }
    }
    dfs();
    cout << rs << '\n';
    return 0;

}