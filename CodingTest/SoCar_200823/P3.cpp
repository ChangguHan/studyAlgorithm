// 백트래킹 쓴다면, 4^16
// 2^32, 1e^9, 10초

// 최소신장트리
// 다익스트라, 안돼...

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int tips[10][10];
int limit[10][10];
bool visit[10][10];
int maxv=0;

void dfs(int dep, int curr_tip, int ey, int ex, int r) {
    if(dep==16) {
        maxv = max(maxv, curr_tip);
        return;
    }


    for(int k=0; k<4; k++) {
        int ny = ey + dy[k];
        int nx = ex + dx[k];
        if(ny>=0 && ny<r && nx>=0 && nx<r) {
            // bool sw = false;
            bool sw2 = false;
            // if(visit[ny][nx]) sw = true;
            // 여기서 팁을 또받는구나
            // 만약 여기서 팁 받았다면 빼줘야지
            if(limit[ny][nx] >= dep+1 && visit[ny][nx] == false ) {
                sw2 = true;
                curr_tip += tips[ny][nx];
                visit[ny][nx] = true;
            }
            

            dfs(dep+1, curr_tip, ny,nx,r);
            // 원래 visit 한곳이 아닐경우, false;
            
            if(sw2) {
                visit[ny][nx] = false;
                curr_tip -= tips[ny][nx];
            }
        }

    }



}
int solution(int r, vector<vector<int> > delivery) {
    for (int j=0; j<r; j++) {
        for (int i=0; i<r; i++) {
            limit[j][i] = delivery[j*r+i][0];
            tips[j][i] = delivery[j*r+i][1];
        }
    }

    visit[0][0] = true;
    int inittip = 0;
    if(limit[0][0]>=0) inittip += tips[0][0];
    
    dfs(0,inittip,0,0, r);

    return maxv;
}
int main() {
    vector<vector<int > > ip;
    // vector<int> e;
    // e.push_back(1);
    // e.push_back(5);
    // ip.push_back(e);

    // e.clear();
    // e.push_back(8);
    // e.push_back(3);
    // ip.push_back(e);
    
    // e.clear();
    // e.push_back(4);
    // e.push_back(2);
    // ip.push_back(e);

    // e.clear();
    // e.push_back(2);
    // e.push_back(3);
    // ip.push_back(e);

    // e.clear();
    // e.push_back(3);
    // e.push_back(1);
    // ip.push_back(e);

    // e.clear();
    // e.push_back(3);
    // e.push_back(2);
    // ip.push_back(e);

    // e.clear();
    // e.push_back(4);
    // e.push_back(2);
    // ip.push_back(e);

    // e.clear();
    // e.push_back(5);
    // e.push_back(2);
    // ip.push_back(e);

    // e.clear();
    // e.push_back(4);
    // e.push_back(1);
    // ip.push_back(e);
    // cout << solution(3, ip) << '\n';

    vector<int> e;
    e.push_back(1);
    e.push_back(10);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);
    
    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);

    e.clear();
    e.push_back(3);
    e.push_back(100);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);

    e.clear();
    e.push_back(9);
    e.push_back(100);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);

    e.clear();
    e.push_back(8);
    e.push_back(1);
    ip.push_back(e);
    

    cout << solution(4, ip) << '\n';


    

    return 0;
}