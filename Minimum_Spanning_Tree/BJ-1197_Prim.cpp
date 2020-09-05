#include <iostream>
#include <vector>

#define MAX 100000
using namespace std;
using ti3 = tuple<int, int, int>;

int v,e;
vector<pair<int, int > > adj[MAX];
bool chk[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }

    int cnt=0;
    int ans=0;
    priority_que<ti3, vector<ti3>, greater<ti3> > PQ;
    for (auto nxt : adj[1]) {
        PQ.push({nxt.first, 1, nxt.second});
    }
    chk[1] = 1;
    while (1) {
        int cost, v1, v2;
        tie(cost, v1, v2) = PQ.top(); PQ.pop();
        if(chk[v2]) continue;
        chk[v2] = 1;
        ans += cost;
        cnt++;
        if(cnt==v-1)break;
        for(auto nxt : adj[v2]) {
            if(!chk[nxt.second])
                PQ.push({nxt.first,v2,nxt.second});
        }


    }

    cout << ans;



    return 0;
}