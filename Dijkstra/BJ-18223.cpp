// 다익스트라, 경로 추적 해서, 탐색

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pi2 = pair<int, int>;

int V,E,P;
const int inf = 1e8;
// 메모리 초과나서 인접리스트 말고, 배열로 쓰자
vector<pi2> adj[5010];
// int adjA[5010][5010];
int dist[5010];
int dist2[5010];
// int pre[5010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E >> P;
    fill(dist, dist+5010, inf);
    fill(dist2, dist2+5010, inf);
    // fill(&adjA[0][0], &adjA[5009][5010],inf);
    int st = 1; int en = V;
    while(E--) {
        int a,b,c;
        cin >> a >> b >> c;
        // adjA[a][b] = min(adjA[a][b],c);
        adj[a].push_back(make_pair(c,b));
    }
    // 건우 거치고 안거칠때, 길이 같을때  테스트케이스
    // 건우 지나면 무조건 넣어주기

    priority_queue<pi2, vector<pi2>, greater<pi2> > pq;
    dist[st] = 0;


    pq.push(make_pair(dist[st],st));

    while(!pq.empty()) {
        auto epq = pq.top(); pq.pop();
        int c = epq.first;
        int i = epq.second;
        if(dist[i] != c) continue;
        for (auto ex : adj[i]) {
        // for(int ai =1; ai<=V; ai++){ 
            // if(adjA[i][ai] == inf) continue;
            // int ni = ai;
            // int nc = adjA[i][ai];

            int ni = ex.second;
            int nc = ex.first;

            // 클때는 무조건 업데이트
            if(dist[ni] > c + nc) {
                dist[ni] = c + nc;
                pq.push(make_pair(dist[ni],ni));
                // pre[ni] = i;
                // 같고 견우일때는 이전것만 업데이트
            } 
        }
    }


    priority_queue<pi2, vector<pi2>, greater<pi2> > pq2;
    dist2[P] = 0;


    pq2.push(make_pair(dist2[P],P));

    while(!pq2.empty()) {
        auto epq = pq2.top(); pq2.pop();
        int c = epq.first;
        int i = epq.second;
        if(dist2[i] != c) continue;
        for (auto ex : adj[i]) {
        // for(int ai =1; ai<=V; ai++){ 
            // if(adjA[i][ai] == inf) continue;
            // int ni = ai;
            // int nc = adjA[i][ai];

            int ni = ex.second;
            int nc = ex.first;

            // 클때는 무조건 업데이트
            if(dist2[ni] > c + nc) {
                dist2[ni] = c + nc;
                pq2.push(make_pair(dist2[ni],ni));
                // pre[ni] = i;
                // 같고 견우일때는 이전것만 업데이트
            } 
        }
    }
    // if(dist[V] == inf) cout << "SAVE HIM " << '\n';
    if(dist[P] == inf) cout << "GOOD BYE" << '\n';
    else if(dist[V] == dist[P] + dist2[V]) cout << "SAVE HIM" << '\n';
    else cout << "GOOD BYE" << '\n';

    // // 경로중에 견우 있는지 찾기
    // int cur = en;
    // // vector<int> path;
    // // 메모리 초과 여기서 path 줄이자
    // while(cur != st) {
    //     if(cur == P) {
    //         cout << "SAVE HIM" << '\n';
    //         return 0;
    //     }
    //     cur = pre[cur];
    // }
    // if(cur == P) {a
    //     cout << "SAVE HIM" << '\n';
    //     return 0;
    // }

    // cout << "GOOD BYE" << '\n';



    return 0;
}