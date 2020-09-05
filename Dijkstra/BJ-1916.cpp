
// 음수 아니니까 다익스트라
//ElgE : 1e5*20, 2e6
// 최대값, e3 * 1e5, int


// 다해보고, 프림처럼 한번 해보기

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1e8+10;
vector<pair<int, int> > adj[1010];
int dist[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M; cin >> N >> M;
    fill(dist,dist+N+1, inf);

    for(int i=0; i<M; i++) {
        int a,b,c;
        cin >> a >> b >>c;
        adj[a].push_back(make_pair(c,b));
    }
    int st,en; cin >> st >> en;
    
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > pq;
    pq.push(make_pair(dist[st], st));

    while(!pq.empty()) {
        auto eq = pq.top(); pq.pop();
        if(eq.first != dist[eq.second]) continue;

        for(auto x : adj[eq.second]) {
            if(dist[x.second] > dist[eq.second] + x.first ) {
                dist[x.second] = dist[eq.second] + x.first;
                pq.push(make_pair(dist[x.second],x.second));
            }
        }
    }

    cout << dist[en] << '\n';


    return 0;
}