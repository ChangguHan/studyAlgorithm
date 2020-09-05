// 그래프 탐색 O(V+E)
// V = 100
// E = 10000

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[110];
bool chk[110];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V,E; cin >> V >> E;
    for(int i=0; i<E; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    chk[1]=1;
    int rs=0;
    while(!q.empty()) {
        rs++;
        int eq = q.front(); q.pop();
        for(int x : adj[eq]) {
            if(chk[x]) continue;
            chk[x] =1;
            q.push(x);
        }

    }

    cout << rs-1 << '\n';
    return 0;
}