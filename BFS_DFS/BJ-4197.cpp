// 불 먼저, 그다음 탈출 먼저

#include <iostream>
#include <queue>
#include <string>

using namespace std;

char map[1010][1010];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
bool fchk[1010][1010];
bool jchk[1010][1010];
int N,M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    queue<pair<int, int> > jq;
    queue<pair<int, int> > fq;
    for (int j=0; j<N; j++) {
        string ip;
        cin >> ip;
        for (int i=0; i<ip.length(); i++) {
            map[j][i] = ip[i];
            if(map[j][i] == 'J') {
                jq.push(make_pair(j,i));
                jchk[j][i] = 1;
            }
            if(map[j][i] == 'F') {
                fq.push(make_pair(j,i));
                fchk[j][i] = 1;
            }
        }
    }
    int time=0;
    while(!jq.empty() ) {
        time++;
        // 불 먼저
        int fqsize = fq.size();
        // 메모리 초과니까, F를 큐로하지말고 for 돌면서
        // for (int j=0; j<N; j++)  {
        //     for (int i=0; i<M; i++) {
        //         if(map[j][i] == 'F') {
        //             for (int k=0; k<4; k++) {
        //                 int nfy = j + dy[k];
        //                 int nfx = i + dx[k];
        //                 if(nfy>=0 && nfy<N && nfx >=0 && nfx<M) {
        //                     if(map[nfy][nfx] == 'J' || map[nfy][nfx] == '.') {
        //                         map[nfy][nfx] = 'G';
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // for (int j=0; j<N; j++)  {
        //     for (int i=0; i<M; i++) {
        //         if(map[j][i] == 'G') map[j][i] = 'F';
        //     }
        // }


        while(fqsize--) {
            auto efq = fq.front(); fq.pop();
            int efy = efq.first;
            int efx = efq.second;
            for (int k=0; k<4; k++) {
                int nfy = efy + dy[k];
                int nfx = efx + dx[k];
                if(nfy>=0 && nfy<N && nfx >=0 && nfx<M) {
                    if(map[nfy][nfx] == 'J' || map[nfy][nfx] == '.') {
                        if(fchk[nfy][nfx] == false) {
                            fchk[nfy][nfx] = 1;
                            fq.push(make_pair(nfy, nfx));
                            map[nfy][nfx] = 'F';

                        }
                        
                    }
                }
            }
        }

        int jqsize = jq.size();
        // bool sw = false;
        while(jqsize--) {
            auto ejq = jq.front(); jq.pop();
            int ejy = ejq.first;
            int ejx = ejq.second;
            for (int k=0; k<4; k++) {
                int njy = ejy + dy[k];
                int njx = ejx + dx[k];
                // 탈출
                if(!(njy>=0 && njy<N && njx >=0 && njx<M))  {
                    cout << time << '\n';
                    return 0;
                }
                if (map[njy][njx] == '.' || map[njy][njx] == 'J') {
                    if(jchk[njy][njx] == false) {
                        jchk[njy][njx] = 1;
                        jq.push(make_pair(njy,njx));
                        map[njy][njx] = 'J';
                    }
                    
                }
                
            }
            
        }
        

    }

    cout << "IMPOSSIBLE" << '\n';



    return 0;
}