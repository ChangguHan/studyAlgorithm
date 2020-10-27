/**
 BOJ 1389
 - BFS 로 카운트 구하는 문제
    - 각각 bfs 해서 min 값이랑 min idx 가지고 있어서 최소값 리턴
    -  O(N+M)
 - 입력 중복 계산
    중복처리하지말고, 다음꺼넘어갈때 chk 있으면 안넘어가는걸로
 - 엣지값
 */


#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M; cin >> N >> M;
    while(M--) {
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool chk[110];
    int minv = 110;
    int idx = -1;
    
    for(int i=1; i<=N; i++) {
        fill(chk, chk+110, false);
        chk[i] = 1;
        queue<int> q;
        q.push(i);
        int cnt=0;
        int rs=0;
        while(!q.empty()) {
            int qsize = q.size();
            cnt++;
            while(qsize--) {
                auto eq = q.front();
                q.pop();
                for(int x : adj[eq]) {
                    if(chk[x]) continue;
                    chk[x] = 1;
                    rs+=cnt;
                    q.push(x);
                }
            }
            
        }
        if(minv > rs) {
            minv = rs;
            idx = i;
        }
    }
    
    cout << idx << '\n';
    return 0;
}
