#include <iostream>
#include <algorithm>

#define MAX 100005
using namespace std;

pair<int, pair<int, int> > edge[MAX+1];
int p[MAX+1];

int find(int w) {
    if(p[w]<0) return w;
    return p[w] = find(p[w]);
}

bool is_diff_edge(int u, int v) {
    u = find(u); v = find(v);
    if(u==v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(p, p+MAX+1, -1);
    int v,e;
    cin >> v >> e;
    for (int i=0; i<e; i++) {
        cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    }
    sort(edge, edge + e);
    int cnt=0;
    int ans=0;

    for (int i=0; i<e; i++) {
        int cost = edge[i].first;
        int v1 = edge[i].second.first;
        int v2 = edge[i].second.second;
        if(!is_diff_edge(v1,v2)) continue;
        cnt++;
        ans += cost;
        if(cnt == v-1) break;
    }

    cout << ans;


    return 0;
}