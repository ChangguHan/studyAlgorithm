#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int map[15][15];
int mapb[15][15];
int N,M;
vector<tuple<int, int, int> > nl;
vector<int> v;
int maxv = 64;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int cal() {
    for (int i=0; i<v.size(); i++) {
        int ex,ey,n;
        tie(ey,ex,n) = nl[i];
        int ed = v[i];
        int ny= ey;
        int nx = ex;
        if(n==1) {
            while(1) {
                ny += dy[ed];
                nx += dx[ed];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }
        }else if(n==2) {
            while(1) {
                ny += dy[ed];
                nx += dx[ed];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }
            ny = ey; nx = ex;
            while(1) {
                ny += dy[(ed+2)%4];
                nx += dx[(ed+2)%4];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }

        }else if(n==3) {
            while(1) {
                ny += dy[ed];
                nx += dx[ed];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }
            ny = ey; nx = ex;
            while(1) {
                ny += dy[(ed+1)%4];
                nx += dx[(ed+1)%4];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }
        }else if(n==4) {
            while(1) {
                ny += dy[ed];
                nx += dx[ed];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }
            ny = ey; nx = ex;
            while(1) {
                ny += dy[(ed+1)%4];
                nx += dx[(ed+1)%4];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }
            ny = ey; nx = ex;
            while(1) {
                ny += dy[(ed+2)%4];
                nx += dx[(ed+2)%4];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }
            
        }else if(n==5) {
            while(1) {
                ny += dy[ed];
                nx += dx[ed];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }
            ny = ey; nx = ex;
            while(1) {
                ny += dy[(ed+1)%4];
                nx += dx[(ed+1)%4];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }
            ny = ey; nx = ex;
            while(1) {
                ny += dy[(ed+2)%4];
                nx += dx[(ed+2)%4];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }
            ny = ey; nx = ex;
            while(1) {
                ny += dy[(ed+3)%4];
                nx += dx[(ed+3)%4];
                if(!(ny>=0 && ny<N && nx>=0 && nx < M)) break;
                if(map[ny][nx] !=0) {
                    if(map[ny][nx] == 6) break;
                    continue;
                }
                map[ny][nx] = 9;
            }
        }


    }
    int cnt=0;
    for (int j=0; j<N; j++) for (int i=0; i<M; i++) if(map[j][i]==0) cnt++;

    return cnt;


}

void dfs() {
    if(v.size() == nl.size()) {
        for(int j=0; j<N; j++) for (int i=0; i<M; i++) map[j][i] = mapb[j][i];

        maxv = min(maxv, cal());
        return;
    }
    for(int i=0; i<4; i++) {
        v.push_back(i);
        dfs();
        v.pop_back();
    }

}
int main() {
    cin >> N >> M;
    for (int j=0; j<N; j++) {
        for (int i=0; i<M; i++) {
            cin >> map[j][i];
            mapb[j][i] = map[j][i];
            if(map[j][i] !=0 && map[j][i] != 6) nl.push_back({j,i,map[j][i]});
        }
    }

    dfs();

    cout << maxv << '\n';



    return 0;
}