// 지형의 크기가 얼마나 큰지 확인하기
// 각 육지 위치에서 BFS로 해서 얼마나 넓은지 확인하면 될듯
// 이거의 최대값으로 만들면 되겠다


#include <iostream>
#include <string>
#include <queue>

using namespace std;

char map[55][55];
bool chk[55][55];
int Y,X;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int bfs(int j, int i) {
    int rs = 0;
    fill(&chk[0][0], &chk[54][55], 0);
    queue<pair<int, int> > q;
    q.push(make_pair(j,i));
    chk[j][i] = 1;

    while(!q.empty()) {
        rs++;
        int qsize = q.size();
        for(int i=0; i<qsize; i++) {
            int ey = q.front().first;
            int ex = q.front().second;
            q.pop();
            for (int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];
                if(ny>=0 && ny<Y && nx>=0 && nx<X) {
                    if(chk[ny][nx] == 0 && map[ny][nx] == 'L') {
                        q.push(make_pair(ny,nx));
                        chk[ny][nx] = 1;
                    }

                }

            }
            
        }
    }
    return rs-1;

}

int main() {
    cin >> Y >> X;
    int ans=0;
    for (int j=0; j<Y; j++) {
        string ip;
        cin >> ip;
        for (int i=0; i<X; i++) {
            map[j][i] = ip[i];
        }
    }

    for (int j=0; j<Y; j++) {
        for (int i=0; i<X; i++) {
            if(map[j][i]=='L') {
                ans = max(ans, bfs(j,i));
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
