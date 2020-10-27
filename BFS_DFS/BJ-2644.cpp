/**
 BOJ 2644
 
 - 그래프 탐색
    - bfs 돌려서 거리 구하면 될듯
    - adj로 관계 넣어두고
    - bool 로 체크
    - 찾는것 찾으면 종료
 - max 계산
    - O(M+N) O(N^2), 괜찮
 - 없을경우 -1 출력
    - bfs 큐 다썻느데, 안나오면 return -1
 
 - dfs로도 해보자
 */


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[110];
bool chk[110];
int cnt=0;
int rs=-1;
int st, en;
bool sw = false;
void dfs(int v) {
    chk[v] = 1;
    for(int x : adj[v]) {
        if(chk[x]) continue;
        cnt++;
        if(x == en) {
            rs = cnt;
            return;
        }
        dfs(x);
        cnt--;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    cin >> st >> en;
    
    int M; cin >> M;
    while(M--) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(st);
    cout << rs << '\n';
    return 0;
}
