#include <iostream>

#include <string>
#include <vector>

using namespace std;

// 걍 시뮬레이션
int map[310][310];
int rs=0;
int N=0;
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
void dfs(int y, int x, int d) {
    if(y==N-1 && x==N-1) {
        return;
    }

    for(int k=-1; k<3; k++) {
        // 다음 방향
        int nd = (d+k)%4;
        if(nd<0) nd+=4;
        int ny = y+dy[nd];
        int nx = x+dx[nd];
        if(ny>=0 && ny<N && nx>=0 && nx<N) {
            if(map[ny][nx]==0) {
                rs++;
                dfs(ny, nx, nd);
                break;
            }
            
        }
    }

}
int solution(vector<vector<int>> maze) {
    N = maze.size();
    for(int j=0; j<N; j++) {
        for(int i=0; i<N; i++) {
            map[j][i] = maze[j][i];
        }
    }
    dfs(0,0,0);
    return rs;
}

int main() {
    vector<vector<int>> maze;
    vector<int> e;

    e.clear();
    e.push_back(0);
    e.push_back(1);
    e.push_back(0);
    e.push_back(1);
    maze.push_back(e);
    
    e.clear();
    e.push_back(0);
    e.push_back(1);
    e.push_back(0);
    e.push_back(0);
    maze.push_back(e);

    e.clear();
    e.push_back(0);
    e.push_back(0);
    e.push_back(0);
    e.push_back(0);
    maze.push_back(e);

    e.clear();
    e.push_back(1);
    e.push_back(0);
    e.push_back(1);
    e.push_back(0);
    maze.push_back(e);



    cout << solution(maze) << '\n';
    return 0;
}
