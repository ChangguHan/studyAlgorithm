// 그대로 따라해보자

// 위치찾음 >> 스티커 크기 모두 들어갈수있을만한 자리 확인
// 스티커 칸에 모두 빈칸 있는지 찾음
// 모두 빈칸 아니면 회전, 총 4번까지
// 모두 안되면 다음것으로 넘어감

#include <iostream>

using namespace std;
bool map[50][50];
bool smap[50][50];
int N,M,K;
int rs=0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(&map[0][0], &map[49][50], false);
    cin >> N >> M >> K;
    while (K--) {
        int sn,sm;
        cin >> sn >> sm;
        fill(&smap[0][0], &smap[49][50],false);
        for(int sj=0; sj<sn; sj++) {
            for (int si = 0; si < sm; si++) {
                cin >> smap[sj][si];
            }
        }
        // 스티커 회전이 먼저
        for (int k=0; k<4; k++) {
            int esn,esm;
            if(k==0){
                esn = sn; esm = sm;
            }
            else {
                bool smapb[50][50];
                fill(&smapb[0][0], &smapb[49][50], false);
                if(k%2==1) {
                    esn = sm;
                    esm = sn;
                } else {esn = sn; esm = sm;}
                // 스티커 회전
                for (int j=0; j<40; j++) {
                    for (int i=0; i<40; i++) {
                        smapb[j][i] = smap[j][i];
                    }
                }
                for (int tj=0; tj<esn; tj++) {
                    for (int ti=0; ti<esm; ti++) {
                        smap[tj][ti] = smapb[esm-1-ti][tj];
                    }
                }

            }
            
            bool sw = false;
            for (int j=0; j<=N-esn; j++) {
                for (int i=0; i<=M-esm; i++) {
                    // 스티커 체크
                    bool esw=false;
                    for(int eej=0; eej<esn; eej++) {
                        for (int eei=0; eei<esm; eei++) {
                            if(smap[eej][eei]==0) continue;
                            if(map[j+eej][i+eei]) {
                                esw = true;
                                break;
                            }

                        }
                        if(esw) break;
                    }
                    if(!esw) {
                        sw = true;
                        rs++;
                        // 스티커 붙이기
                        for(int eej=0; eej<esn; eej++) {
                            for (int eei=0; eei<esm; eei++) {
                                if(smap[eej][eei]==0) continue;
                                map[j+eej][i+eei] = 1;
                            }
                        }
                        break;
                        
                    }

                    



                }
                if(sw) break;
            }
            if(sw) break;

        }
        
    }
    rs=0;
    for (int j=0; j<N; j++) {
        for (int i=0; i<M; i++) {
            if(map[j][i]) rs++;
        }
    }

    cout << rs << '\n';




    return 0;
}