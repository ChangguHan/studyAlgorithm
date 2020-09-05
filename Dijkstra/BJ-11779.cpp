#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 

using namespace std;
using pi2 = pair<int, int>;

int n,m,st,en;
const int inf = 1e8+10;
int dist[1010];
int pre[1010];
vector<pair<int, int> > adj[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a,b,c;
        cin >>a >> b >> c;
        adj[a].push_back(make_pair(c,b));
    }
    cin >> st >> en;

    fill(dist,dist+n+1,inf);

    priority_queue<pi2, vector<pi2>, greater<pi2> > pq;
    dist[st]=0;
    pq.push(make_pair(dist[st],st));

    while(!pq.empty()) {
        pi2 epq = pq.top(); pq.pop();
        int ei = epq.second;
        int c = epq.first;
        if(dist[ei] != c) continue;
        for (pi2 x : adj[ei]) {
            int ni = x.second;
            int nc = x.first;
            if(dist[ni] > c + nc) {
                dist[ni] = c + nc;
                pre[ni] = ei;
                pq.push(make_pair(dist[ni],ni));
            }
        }
    }

    cout << dist[en] << '\n';
    vector<int> path;
    int cur = en;
    while(cur != st) {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    cout << path.size() << '\n';
    reverse(path.begin(), path.end());
    for(int x : path) cout << x << ' ';





    return 0;
}