// 위상정렬인데, 우선순위가 있는것
// 위상정렬 시간복잡도가 어떻게 되더라
// 모든 원소 한번씩 들어가고, 간선 한번씩 돌게되니까
// O(V+E)

// 우선순위는 어떻게 반영하지
// 작은수부터 시작하면 되지

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[32010];
int indeg[32010];
// 공간복잡도
// indeg : 2e5
// 8*1e5, 1e6, 400KB
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M; cin >> N >> M;
    for(int i=0; i<M; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    // priority queue로 쓰면 되겠다
    priority_queue<int, vector<int>, greater<int> > q;
    // queue<int> q;
    for(int i=1; i<=N; i++) {
        if(indeg[i]==0) q.push(i);
    }
    
    vector<int> rs;
    while(!q.empty()) {
        // 여기에서 sort를 한번 해줘야하는데
        // sort ElgE
        //O((V+E)ElgE)
        // O(E^2*lgE) : 1e10, 
        
        
        int eq = q.top(); q.pop();
        rs.push_back(eq);
        for(int x : adj[eq]) {
            indeg[x]--;
            if(indeg[x]==0) {
                q.push(x);
            }
        }
    }
    for(int x : rs) cout << x << ' ';
    cout << '\n';


    return 0;
}