// 각각에서 min값

#include <iostream>
#include <queue>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        vector<int> adj[1010];

        vector<int> rs;
        int minv[1010];
        int cost[1010];
        int indeg[1010];
        int N,K;
        cin >> N >> K;
        fill(minv, minv+N+1, 0);
        fill(cost, cost+N+1, 0);
        fill(indeg, indeg+N+1, 0);
        for (int i=1; i<=N; i++) {
            cin >> cost[i];
        }
        while(K--) {
            int a,b;
            cin >>a >>b;
            adj[a].push_back(b);
            indeg[b]++;
        }

        int ri; cin >> ri;

        queue<int> q;
        for(int i=1; i<=N; i++) if(indeg[i]==0){
            q.push(i);
            minv[i] = cost[i];
        }

        while(!q.empty()) {
            int eq = q.front(); q.pop();

            for (int x : adj[eq]) {
                indeg[x]--;
                minv[x] = max(minv[x], minv[eq] + cost[x]);
                if(indeg[x]==0) {
                    q.push(x);
                }
            }
        }

        cout << minv[ri] << '\n';

    }

    return 0;
}

