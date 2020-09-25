// 매턴마다 국경선 열어야하는 것들 추가해놓고
// 합쳐서 평균해주면 됨


#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int N;
int map[60][60];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream in("in.txt");
    int L, R;
    in >> N >> L >> R;
    for(int j=0; j<N; j++) {
        for(int i=0; i<N; i++) {
            in >> map[j][i];
        }
    }
    
    while(1) {
        // 국경 먼저
        int cnt=0;
        bool chk[60][60];
        int sum=0;
        // 오른쪽, 아래만 보면 됨
        for(int j=0; j<N; j++) {
            for( int i=0; i<N; i++) {
                // 오른쪽
                if(i<N-1) {
                    int sub = abs(map[j][i] - map[j][i+1]);
                    if(sub <= R || sub >= L) {
                        
                        if(chk[j][i]) {
                            chk[j][i]=1;
                            sum += map[j][i];
                            cnt++;
                        } 
                        if(chk[j][i+1]) {
                            chk[j][i+1]=1;
                            sum += map[j][i+1];
                            cnt++;
                        }
                        
                    }
                }
                // 아래
                if (j < N - 1)
                {
                    int sub = abs(map[j][i] - map[j+1][i]);
                    if (sub <= R || sub >= L)
                    {
                        if (chk[j][i])
                        {
                            chk[j][i] = 1;
                            sum += map[j][i];
                            cnt++;
                        }
                        if (chk[j+1][i])
                        {
                            chk[j+1][i] = 1;
                            sum += map[j+1][i];
                            cnt++;
                        }
                    }
                }
                
            }
        }

        if(!cnt) break;

    
    }

    return 0;
}