/**
 BOJ 15898

  백트래킹 시뮬레이션
 - 각 재료의 위치에 백트래킹을 해서 최대값을 구하면 될 것같음
 
 시간복잡도 계산
 - 재료의 개수 N
 - 위치 총 4군데, 회전 4번,, >> 16번
 - 16^N, 2^(4N), 2^12, 4*e3
 
 - 근데 여기서 N개중에 3개를 뽑는 것이기 때문에 10P3, 720 곱해주기
  - 2.8e6
 
 구현방법
 - 순열 먼저 구해줘서 재료 먼저 구하기
 - 각 재료당, 4위치, 4방향 각각 구하고 다음것 넘어가기
 - 마지막에 탐색하면서 R,B,G,Y,W 개수 세기
 
 
 */

#include <iostream>
#include <vector>
using namespace std;

int map[6][6];
char cMap[6][6];
int N;
vector<vector<vector<int>>> vec;
vector<vector<vector<char>>> cvec;
bool chk[15];
vector<int> v;
int maxv=0;
void plusCal(vector<vector<int>>& emap, vector<vector<char>>& cemap,int y, int x) {
    for(int j=0; j<4; j++) {
        for(int i=0; i<4; i++) {
            map[j+y][i+x] += emap[j][i];
            if(map[j+y][i+x] < 0) map[j+y][i+x] = 0;
            if(map[j+y][i+x] > 9) map[j+y][i+x] = 9;
            
            if(cemap[j][i] != 'W') cMap[j+y][i+x] = cemap[j][i];
            
            
        }
    }
    
}
void turn(vector<vector<int>> &emap, vector<vector<char>> &cemap) {
    vector<vector<int>> emap_copy;
    vector<vector<char>> cemap_copy;
    emap_copy.assign(emap.begin(), emap.end());
    
    cemap_copy.assign(cemap.begin(), cemap.end());
    
    for(int j=0; j<4; j++) {
        for(int i=0; i<4; i++) {
            emap[j][i] = emap_copy[i][3-j];
            cemap[j][i] = cemap_copy[i][3-j];
        }
    }
}

int calRGB() {
    int rs=0;
    for(int j=0; j<5; j++) {
        for(int i=0; i<5; i++) {
            char ec = cMap[j][i];
            if(ec=='R') rs += map[j][i] * 7;
            else if(ec=='B') rs += map[j][i] * 5;
            else if(ec=='G') rs += map[j][i] * 3;
            else if(ec=='Y') rs += map[j][i] * 2;
        }
    }
    
    return rs;
}

void cal(int cur) {
    if(cur == 3) {
        maxv = max(calRGB(), maxv);
        return;
    }
    
    auto emap = vec[v[cur]];
    auto cemap = cvec[v[cur]];
    // 맵 복사해두기
    vector<vector<int>> emap_back;
    vector<vector<char>> cemap_back;
    emap_back.assign(emap.begin(), emap.end());
    cemap_back.assign(cemap.begin(), cemap.end());
    
    int map_back[6][6];
    char cMap_back[6][6];
    copy(&map[0][0], &map[5][6], &map_back[0][0]);
    copy(&cMap[0][0], &cMap[5][6], &cMap_back[0][0]);
    for(int y=0; y<2; y++) {
        for(int x=0; x<2; x++) {
            for(int k=0; k<4; k++) {
//                if(cur==0 && y==0 && x==0 && k==1) {
//                    cout << 1 << '\n';
//                }
                int kk = k;
                while(kk--) {
                    turn(emap, cemap);
                }
                plusCal(emap, cemap, y, x);
                
                cal(cur+1);
                
                emap.assign(emap_back.begin(), emap_back.end());
                cemap.assign(cemap_back.begin(), cemap_back.end());
                copy(&map_back[0][0],  &map_back[5][6], &map[0][0]);
                copy(&cMap_back[0][0], &cMap_back[5][6], &cMap[0][0]);
                
                
            }
            
            
            
        }
    }
     
}
void dfs() {
    if(v.size() == 3) {
        cal(0);
    }
    for(int i=0; i<N; i++) {
        if(chk[i]) continue;
        v.push_back(i);
        chk[i] =1;
        
        dfs();
        
        v.pop_back();
        chk[i] = 0;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int k=0; k<N; k++) {
        vector<vector<int>> ev;
        for(int j=0; j<4; j++) {
            vector<int> eev;
            for(int i=0; i<4; i++) {
                int ec; cin >> ec;
                eev.push_back(ec);
            }
            ev.push_back(eev);
        }
        vec.push_back(ev);
        
        vector<vector<char>> cev;
        for(int j=0; j<4; j++) {
            vector<char> eev;
            for(int i=0; i<4; i++) {
                char ec; cin >> ec;
                eev.push_back(ec);
            }
            cev.push_back(eev);
        }
        cvec.push_back(cev);
    }
    
    fill(&cMap[0][0], &cMap[5][6], 'W');
    
    dfs();
    
    cout << maxv << '\n';
    
    
    return 0;
}

