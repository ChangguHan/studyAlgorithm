/**
 BOJ 19237
 각 턴제로 이루어지니까 BFS로 하자
 */

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
typedef tuple<int, int, int,int> ti4;

int map[30][30];
int smellmap[30][30][2]; // 0 : 상어, 1 : 남은시간
int dy[] = {0,-1,1,0,0};
int dx[] = {0,0,0,-1,1};
int sd[1010][5][5];
int initialshark[1010][5];
bool chk[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<ti4> q;
    int N,M,K; cin >> N >> M >> K;
    for(int j=0; j<N; j++) {
        for(int i=0; i<N; i++) {
            cin >> map[j][i];
            if(map[j][i] != 0) {
                initialshark[map[j][i]][0] = j;
                initialshark[map[j][i]][1] = i;
                smellmap[j][i][0] = map[j][i];
                smellmap[j][i][1] = K;
            }
        }
    }
    for(int i=1; i<=M; i++) {
        int ed; cin >> ed;
        ti4 et =make_tuple(i,initialshark[i][0],initialshark[i][1],ed);
        q.push(et);
    }
    
    for(int i=1; i<=M; i++) {
        
        for(int j=1; j<=4; j++) {
            for( int k=1; k<=4; k++) {
                cin >> sd[i][j][k];
            }
            
            
        }
    }
    int t=0;
    while(q.size()!=1) {
        t++;
        if(t>1000) break;
        int qsize =q.size();
        // 상어 맵 초기화시켜줌
        fill(&map[0][0], &map[N-1][N], 0);
        while(qsize--) {
            // 상어 움직이기
            int es, ej, ei, ed;
            tie(es, ej, ei, ed) = q.front(); q.pop();
            if(chk[es]) continue;
            bool sw = true;
            for(int k=1; k<=4; k++) {
                // 각 방향 가능한지 탐색
                int nd =sd[es][ed][k];
                int ny = ej + dy[nd];
                int nx = ei + dx[nd];
                if(ny>=0 && ny<N && nx>=0 && nx<N) {
                    // 이동했는데 향기 없다면
                    if(smellmap[ny][nx][0] ==0) {
                        // 이동했는데 더 작은 상어 없다면
                        // 그럼 상어 맵을 초기화 시켜주자
                        // 여기서 smellmap 0 조건으로 내세우면
                        // 겹치는 경우가 없어짐
                        // 그니까 우선 map에만 놓고, smellmap은 한꺼번에 올리자
                        
                        // 내가 큰경우 >> 잡아먹힘
                        if(map[ny][nx] !=0 && map[ny][nx] < es) {
                            sw=false;
                            break;
                            // 작거나 0인경우
                        } else {
                            //더 작은 것이 있을때
                            if(map[ny][nx] !=0) chk[map[ny][nx]] = 1;
                            map[ny][nx] = es;
                            q.push(make_tuple(es, ny, nx, nd));
                            sw=false;
                            break;
                        }
                        
                    }
                }
            }
            // 이동 못했다면 원래 자리로
            // 처음부터 이동못하는 경우는 없음
            if(sw) {
                for(int k=1; k<=4; k++) {
                    // 각 방향 가능한지 탐색
                    int nd =sd[es][ed][k];
                    int ny = ej + dy[nd];
                    int nx = ei + dx[nd];
                    if(ny>=0 && ny<N && nx>=0 && nx<N) {
                        if(smellmap[ny][nx][0] ==es) {
                            map[ny][nx] = es;
                            q.push(make_tuple(es, ny, nx, nd));
                            // smell queue를 이용하면, 기존 자리 돌아갔을때
                            // 새로 갱신해주는 것이 너무 힘듬
                            // 그래서 smellmap으로 해주는게 나을듯
                            // 그리고 N^2으로 한칸씩 줄여주는거지
                            break;
                        }
                    }
                }
            }
            
            //
            
            
        }
        // 새로 냄새 추가해주기
        // 냄새 하나씩 없애주기
        for(int j=0; j<N; j++) {
            for (int i=0; i<N; i++) {
                if(map[j][i] !=0) {
                    smellmap[j][i][0] = map[j][i];
                    smellmap[j][i][1] = K+1;
                }
                if(smellmap[j][i][0] != 0) {
                    smellmap[j][i][1]--;
                    if(smellmap[j][i][1]==0) smellmap[j][i][0] = 0;
                }
            }
        }
                                   
                                   
    }
    
    if(t>1000) cout << -1 << '\n';
    else cout << t << '\n';
    
    return 0;
}
