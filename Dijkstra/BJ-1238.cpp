// 가는건 플로이드(E^2가 비슷), 오는건 다익스트라

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pi2 = pair<int, int>;

int N,M,X;
const int inf = 1e5;
vector<pi2> adj[1010];
int map[1010][1010];
int dist[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> X;

    fill(&map[0][0], &map[1009][1010],inf);
    fill(dist, dist+N+1, inf);

    while(M--) {
        int a,b,c;
        cin >> a >> b >>c;
        map[a][b] = c;
        adj[a].push_back(make_pair(c,b));
    }

    for (int k=1; k<=N; k++) 
        for (int j=1; j<=N; j++)
            for (int i=1; i<=N; i++) {
                if(map[j][i] > map[j][k]+ map[k][i]) {
                    map[j][i] = map[j][k]+ map[k][i];
                }
            }
    priority_queue<pi2, vector<pi2>, greater<pi2> > pq;

    dist[X] = 0;
    pq.push(make_pair(0,X));
    while(!pq.empty()) {
        pi2 epq = pq.top(); pq.pop();
        int c = epq.first;
        int i = epq.second;
        if(dist[i] != c ) continue;
        for (pi2 x : adj[i]) {
            int nc = x.first;
            int ni = x.second;
            if(dist[ni] > nc + c) {
                dist[ni] = nc + c;
                pq.push(make_pair(dist[ni],ni));
            }
        }
    }

    int mv = 0;
    for(int i=1; i<=N; i++) {
        mv = max(mv, map[i][X] + dist[i]);
    }

    cout << mv << '\n';



    return 0;
}