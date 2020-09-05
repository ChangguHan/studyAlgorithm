// 확정하는 방식으로 해보기
//프림처럼

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1e8+10;
vector<pair<int, int> > adj[1010];
int dist[1010];
bool chk[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M; cin >> N >> M;
    fill(dist, dist+N+1, inf);
    for(int i=0; i<M; i++) {
        int a,b,c;
        cin >>a >>b >>c;
        adj[a].push_back(make_pair(c,b));
    }

    int st,en; cin >> st >> en;
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(dist[st], st));

    while(!pq.empty()) {
        auto eq = pq.top(); pq.pop();
        int dis = eq.first;
        int idx = eq.second;
        if(chk[idx]) continue;
        chk[idx]=1;
        for(auto x : adj[idx]) {
            int nc = x.first;
            int ni = x.second;
            if(!chk[ni]) {
                if(dist[ni] > dist[idx] + nc) {
                    dist[ni] = dist[idx] + nc;
                    pq.push(make_pair(dist[ni],ni));
                }
            }
        }
    }

    cout << dist[en] << '\n';


    return 0;
}