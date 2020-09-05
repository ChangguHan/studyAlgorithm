// 그래프 탐색 구할때, 주변이 0이면 +1
// 1이면 계속 추가

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int map[10000][10000];
bool chk[10000][10000];
int chk2[10000][10000];
int cnt=0;
int M,N;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

void split(string str) {
    vector<int> v;
    stringstream ss(str);
    string temp;
    int i;
    int j=0;
    while( getline(ss,temp, ';')) {
        i=0;
        stringstream ss2(temp);
        string num;
        while(getline(ss2, num, ' ')) {
            map[j][i] = stoi(num);
            i++;
        }
        
        j++;   
    }
    N = j;
    M = i;
}

void dfs(int y, int x) {
    for (int k=0; k<4; k++) {
        int ny = y+dy[k];
        int nx = x + dx[k];
        if(ny>=0 && ny<N && nx>=0 && nx<M) {
            if(map[ny][nx] == 1) {
                if(!chk[ny][nx]) {
                    chk[ny][nx] = 1;
                    dfs(ny,nx);
                }   
            }
            if(map[ny][nx] ==0) {
                chk2[ny][nx]++;
                // cnt++;
            }
            
        }
    }

}

int main() {
    string ip;
    getline(cin, ip);
    split(ip);

    bool sw = false;
    for (int j=0; j<N; j++) {
        for (int i=0; i<M; i++ ) {
            if(map[j][i] == 1) {
                chk[j][i] = 1;
                dfs(j,i);
                sw=true;
                break;
            }
        }
        if(sw) break;
    }

    for (int j=0; j<N; j++) {
        for (int i=0; i<M; i++) {
            cnt += chk2[j][i];
            // if(chk2[j][i]==1) cnt++;
            // else if(chk2[j][i]==4) cnt +=4;
            // else if(chk2[j][i] >0) cnt++;
            
        }
    }

    cout << cnt;


    return 0;
}