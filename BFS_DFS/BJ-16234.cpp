/**
 BOJ 16234, 인구이동
 
 시뮬레이션
    - 각 사이클에서,
    - 각 노드들 인접한 값들과 차이 ㅣ확인
    - 기준값 안에 들어오면,
        - chk 배열 확인한 후
        - 없으면 벡터에 추가
        - 총 합에도 추가
    - 인구 나눠서 넣어주고
    - 벡터 없으면 더이상 실행 안함

 
인접한것 적용 >> 각각 bfs
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[60][60];
bool chk[60][60];
int dy[] =  {0,1,0,-1};
int dx[] = {1,0,-1,0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,L,R; cin >> N >> L >> R;
    for(int j=0; j<N; j++) {
        for(int i=0; i<N; i++) cin >> map[j][i];
    }
    

    for(int t=0; t<2000; t++) {
        fill(&chk[0][0], &chk[59][60], false);
        bool sw = true;
        for(int j=0; j<N; j++) {
            for(int i=0; i<N; i++) {
                if(chk[j][i]) continue;
                int total = 0;
                queue<pair<int, int>> q;
                vector<pair<int, int>> v;
                q.push(make_pair(j,i));
                while(!q.empty()) {
                    auto eq = q.front();
                    q.pop();
                    int ey = eq.first;
                    int ex = eq.second;
                    
                    for(int k=0; k<4; k++) {
                        int ny = ey + dy[k];
                        int nx = ex + dx[k];
                        if(ny>=0 && ny<N && nx>=0 && nx < N) {
                            if(chk[ny][nx]) continue;
                            int diff = abs(map[ey][ex] - map[ny][nx]);
                            if(diff>=L && diff <=R) {
                                chk[ny][nx] = 1;
                                v.push_back(make_pair(ny, nx));
                                q.push(make_pair(ny, nx));
                                total += map[ny][nx];
                                if(!chk[ey][ex]) {
                                    chk[ey][ex] = 1;
                                    v.push_back(make_pair(ey, ex));
                                    total += map[ey][ex];
                                }
                            }
                        }
                    }
                }
                if(v.size() !=0) {
                    sw = false;
                    int et = total / v.size();
                    for(auto x : v) {
                        int ey = x.first;
                        int ex = x.second;
                        map[ey][ex] = et;
                    }
                }
                
            }
        }
        
        // 합치기
        if(sw) {
            cout << t << '\n';
            break;
        }
        
    }
    return 0;
}
