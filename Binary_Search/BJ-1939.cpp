/**
 BOJ 1939
 
 - 경로중 이동시킬 수 있는 최대값을 구하는 문제
 - 다익스트라로 최소비용 아닌 최대비용으로 하면 안되나
 - 안돼, 다익스트라는 더하는 문제잖아
 - 이건 최대값
 
 - 모든 중량에 대해서, 이분탐색 : lgN, 30
 - 해당 중량이 가능한지 탐색하는 방법, BFS, O(V+E),  1e5
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[100010];
bool visited[100010];
int st,en;

bool bfs(int mid) {
    fill(visited, visited+100009, 0);
    queue<int> q;
    q.push(st);
    visited[st]= 1;
    
    while(!q.empty()) {
        auto eq = q.front(); q.pop();
        if(eq==en) return true;
        
        
        for(auto x : adj[eq]) {
            
            if(visited[x.first]) continue;
            if(x.second >= mid) {
                visited[x.first] = 1;
                q.push(x.first);
            }
        }
    }
    
    return false;
    
    
}
int chk(int st, int en) {
    if(st==en) {
        return en;
    }
    
    int mid = (st+en)/2;
    if((st+en)%2 !=0) mid++;
    // 최대값이기 때문에 낮은건 모두 통과할수 있음
    // 같거나 작은값을 찾으면 됨
    if(bfs(mid)) {
        return chk(mid, en);
    } else {
        return chk(st, mid-1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M; cin >> N >> M;
    
    for(int i=0; i<M; i++) {
        int a,b,c; cin >> a>> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
        
    }
    cin >> st >> en;
    
//    cout << chk(1,3) << '\n';
    cout << chk(1,1e9) << '\n';
    return 0;
}
