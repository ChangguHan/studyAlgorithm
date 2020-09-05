// Dijkstra

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pi2 = pair<int, int>;

int V,E,st;
const int inf = 1e6;
vector<pi2> adj[20010];
int dist[20010];

int main() {
    cin >> V >> E >> st;
    for (int i=0; i<E;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c,b));
    }
    fill(dist, dist+V+1,inf);

    priority_queue<pi2, vector<pi2>, greater<pi2> > pq;

    dist[st]=0;
    pq.push(make_pair(0,st));
    

    while(!pq.empty()) {
        pi2 eq = pq.top(); pq.pop();
        int idx = eq.second;
        if(eq.first != dist[eq.second]) continue;
        for (pi2 x : adj[idx]) {
            if(dist[x.second] > dist[idx] + x.first) {
                dist[x.second] = dist[idx] + x.first;
                pq.push(make_pair(dist[x.second],x.second));
            }
            
        }
    }

    for (int i=1; i<=V; i++) {
        if(dist[i] == inf) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }



    return 0;
}