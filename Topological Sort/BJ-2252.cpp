#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[32010];
int indeg[32010];
int main() {
    int N,M;
    cin >> N >> M;
    while(M--) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    for (int i=1; i<=N; i++) if(indeg[i]==0)q.push(i);
    vector<int> rs;
    while(!q.empty()) {
        int eq = q.front(); q.pop();
        rs.push_back(eq);

        for(int x : adj[eq]) {
            indeg[x]--;
            if(indeg[x] == 0) q.push(x);
        }

        
    }

    for (int x : rs) cout << x << ' ';



    return 0;
}