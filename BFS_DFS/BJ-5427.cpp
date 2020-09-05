// BFS로 조져

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N,M;
char map[1010][1010];
bool visit[1010][1010];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; 
    cin >> t;

    while(t--) {
        bool sw = false;
        fill(&map[0][0], &map[1009][1010],'\0');
        fill(&visit[0][0], &visit[1009][1010],false);
        cin >> M >> N;
        queue<pair<int, int> > fq;
        queue<pair<int, int> > sq;

        for (int j=0; j<N; j++) {
            string ip; cin >> ip;
            for (int i=0; i<M; i++) {
                map[j][i] = ip[i];
                if(ip[i] == '*') fq.push(make_pair(j,i));
                if(ip[i] == '@') {
                    sq.push(make_pair(j,i));
                    visit[j][i] = 1;
                }
            }
        }

        int time=0;

        while(!sq.empty()) {
            time++;
            // 불먼저 번져
            int fqsize = fq.size();
            while(fqsize--) {
                int ey = fq.front().first;
                int ex = fq.front().second;
                fq.pop();
                for (int k=0; k<4; k++) {
                    int ny = ey + dy[k];
                    int nx = ex + dx[k];
                    if(ny>=0 && ny <N && nx>=0 && nx<M) {
                        if(map[ny][nx] != '#' && map[ny][nx] != '*') {
                            // *가 visit 역할
                            fq.push(make_pair(ny, nx));
                            map[ny][nx] = '*';

                        }
                    }
                }

            }

            // 상민 탈출
            int sqsize = sq.size();
            while(sqsize--) {
                int ey = sq.front().first;
                int ex = sq.front().second;
                sq.pop();
                for (int k=0; k<4; k++) {
                    int ny = ey + dy[k];
                    int nx = ex + dx[k];
                    if(!(ny>=0 && ny <N && nx>=0 && nx<M)) {
                        sw = true;
                        break;
                    } else {
                        if(map[ny][nx] =='.' && visit[ny][nx] == false) {
                            visit[ny][nx] = 1;
                            sq.push(make_pair(ny, nx));

                        }
                    } 
                }
                if(sw) break;
            }
            if(sw) break;


        }
        if(sw) cout << time << '\n';
        else cout << "IMPOSSIBLE" << '\n';
        



    }
    

    return 0;

}
