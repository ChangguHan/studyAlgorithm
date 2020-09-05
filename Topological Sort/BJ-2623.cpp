#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> rs;
vector<int> adj[1010];
int indeg[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    while(M--) {
        int n;
        cin >> n;
        int idx=0;
        int nxt;
        while(n--) {
            cin >> nxt;
            if(idx!=0) {
                adj[idx].push_back(nxt);
                indeg[nxt]++;
            }
            idx= nxt;

        }
    }
    queue<int> q;
    for(int i=1; i<=N; i++)if(indeg[i]==0) q.push(i);
    while(!q.empty()) {
        int eq = q.front(); q.pop();
        rs.push_back(eq);

        for(int x : adj[eq]) {
            indeg[x]--;
            if(indeg[x] ==0) q.push(x);
        }
    }

    if(rs.size() == N) {
        for (int x : rs) cout << x <<'\n';
    } else cout << 0 << '\n';

    return 0;
}