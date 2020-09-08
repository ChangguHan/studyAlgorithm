// dfs 완전탐색 가능한가
// dfs : O(V+E)
// O(N^2 + 4*N^2), O(5N^2)

// 4^(N^2), 2^100, e3^10, e30

// 계속 시간초과나는데 이거 DP로해봐야겠다
//근데 DP로 할수없는게 방향이, 사방에서 올수 있으니까 불가능

// 메모리제이션하는 방법이 있음





#include <iostream>


#include <string>
#include <vector>

using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int minv = 25*25*500;
int map[30][30];
bool chk[30][30];
int N;
void dfs(int y, int x, int cost, int bef) {
    if(y==N-1 && x==N-1) {
        minv = min(minv, cost-100);
        return;
    }

    for(int k=0; k<4;k++) {
        int ny = y+dy[k];
        int nx = x+dx[k];
        if(ny >=0  && ny < N && nx >=0 && nx < N) {
            if(map[ny][nx]==0) {
                if(chk[ny][nx] == 0) {
                    chk[ny][nx] = 1;
                    // cost를 어떻게 할꺼야
                    // 이전 정보를 가지고 있어야하나
                    // 가로로 가는것,k= 0, 2, 나머지가 없으니까 0으로가고
                    // 세로로 가는걸 1로가자
                    // 그리고 처음 시작은 무효로 가고,
                    if(y==0 && x==0) dfs(ny, nx, cost+100, k%2);
                    else if(k%2 != bef) dfs(ny, nx, cost+600, k%2);
                    else dfs(ny, nx, cost+100, k%2);
                    chk[ny][nx] = 0;
                }
            }
        }
    }


}
int solution(vector<vector<int>> board) {
    N = board.size();
    for(int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            map[j][i] = board[j][i];
        }
    }
    chk[0][0]=1;
    dfs(0,0,100,-1);
    return minv;
}

int main() {
    vector<vector<int>> board;
    vector<int> a;
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    board.push_back(a);

    a.clear();
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    board.push_back(a);

    a.clear();
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    board.push_back(a);

    a.clear();
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    board.push_back(a);

    a.clear();
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    board.push_back(a);

    a.clear();
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    board.push_back(a);

    a.clear();
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    board.push_back(a);

    a.clear();
    a.push_back(1);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    board.push_back(a);

    
    cout << solution(board) << '\n';
    return 0;
}