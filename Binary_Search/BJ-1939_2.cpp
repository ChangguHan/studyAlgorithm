/**
 BOJ 1939
  옮길수 있는 중량의 최대값을 구함
- 해당 무게를 올릴수 있는지 확인하는법 >> BFS, O(N+M), e5
 - 모든 무게를 다해볼수 없으니 이분탐색, NlgN
 
 - int 가능?
    - 무게 최대가 1e9이긴하지만, 넘어갈수있는지만 확인하는 것이기 때문에 상관없음
 
 - 구체적 방법
    - 이분탐색에서 각각 무게에서 넘길수 있는 최대값(innerBound)을 구함
    - 각 무게에서 확인하는 방법 BFS
        - 해당 무게이상인것만 q에 넣어서, 끝까지 도달하게되면 종료
 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> adj[10010];

int N,M;
int st, en;

bool bfs(int num) {
    bool chk[10010];
    fill(chk, chk+N+1, false);
    
    queue<int> q;
    q.push(st);
    chk[st]=1;
    
    while(!q.empty()) {
        int eq = q.front(); q.pop();
        if(eq == en) return 1;
        
        for(auto x : adj[eq]) {
            int ei = x.first;
            int ec = x.second;
            if(chk[ei] ) continue;
            if(ec >= num) {
                q.push(ei);
                chk[ei] = 1;
            }
        }
        
    }
    return 0;
}

int binary(int st, int en) {
    if(st==en) return en;
    
    int mid = (st+en)/2;
    if((st+en)%2 !=0) mid++;
    if(bfs(mid)) return binary(mid, en);
    else return binary(st, mid-1);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a,b,c; cin >> a>> b >> c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    cin >> st >> en;
    
    cout << binary(1,1e9) << '\n';
    
    return 0;
}
