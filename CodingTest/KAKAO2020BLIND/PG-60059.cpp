
// key의 칸을 줄일 필요가 있나??
// key 왼쪽아래부터, 오른쪽아래까지 돌려보면서 맞춰본다음
// 맞으면 바로 return
// 회전 : 2N*2N *

#include <iostream>
#include <vector>

using namespace std;

int keya[30][30];
int locka[30][30];
int M, N;
void turn() {
    // key 돌리기
    int keyb[30][30];
    for(int j=0; j<M; j++) for (int i=0; i<M; i++) keyb[j][i] = keya[j][i];

    for(int j=0; j<M; j++) {
        for (int i=0; i<M; i++) {
            keya[j][i] = keyb[M-1-i][j];
        }
    }
    
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    M = key.size();
    N = lock.size();
    for(int j=0; j<M; j++) {
        for (int i=0; i<M; i++) {
            keya[j][i] = key[j][i];
        }
    }

    int cnt=0;

    for(int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            locka[j][i] = lock[j][i];
            if(lock[j][i] == 0) cnt++;
        }
    }

    for(int j=0; j<N+M-1; j++) {
        for (int i=0; i<N+M-1; i++) {
            for(int k=0; k<4; k++) {
                turn();
                // 이 겹치는 공간은 어떻게 계산?
                int sw = true;
                int ct = 0;
                for (int jj=0; jj<M; jj++) {
                    if(j+jj<M-1) continue;
                    if(j+jj>M+N-2) continue;
                    for (int ii=0; ii<M; ii++) {
                        if(i+ii<M-1) continue;
                        if(i+ii>M+N-2) continue;
                        // 빈곳이 모두 채워져야되잖아
                        // 지금은 모두 다른곳이 없는지 확인하는건데 이게 맞을까
                        // 그럼 lock의 빈칸이 모두 충족되지 않아도 통과되는 경우가 있음

                        if(keya[jj][ii] == locka[j+jj-M+1][i+ii-M+1]) {
                            sw = false;
                            break;
                        } else if(locka[j+jj-M+1][i+ii-M+1] == 0){
                            ct++;
                        }


                    }
                    if(!sw) break;
                }
                if(sw) {
                    // 여기서 빈칸 없는지 다시한번 검증?   
                    if(cnt==ct) return true;
                }

                
            
            }


        }
    }

    return false;
}

int main() {
    vector<vector<int> > key;
    vector<int> row1;
    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(0);

    vector<int> row2;
    row2.push_back(1);
    row2.push_back(0);
    row2.push_back(0);
    
    vector<int> row3;
    row3.push_back(0);
    row3.push_back(1);
    row3.push_back(1);

    key.push_back(row1);
    key.push_back(row2);
    key.push_back(row3);

    vector<vector<int> > lock;
    row1.clear();
    row1.push_back(1);
    row1.push_back(1);
    row1.push_back(1);

    row2.clear();
    row2.push_back(1);
    row2.push_back(1);
    row2.push_back(0);
    
    row3.clear();
    row3.push_back(1);
    row3.push_back(0);
    row3.push_back(1);

    lock.push_back(row1);
    lock.push_back(row2);
    lock.push_back(row3);


    cout << solution(key, lock) << '\n';


    return 0;
}