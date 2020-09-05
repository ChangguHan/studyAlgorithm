


#include <tuple>
#include <iostream>

using namespace std;

std::tuple<int, int, int> edge[100010];
int p[10010];
int V,E;
int find(int v) {
    if(p[v]<0) return v;
    return p[v] = find(p[v]);
}
bool is_diff_group(int v1, int v2) {
    v1 = find(v1); v2 = find(v2);
    if(v1==v2) return 0;
    if(p[v1] == p[v2]) p[v1]--;
    if(p[v1] < p[v2]) p[v2] = v1;
    else p[v1] = v2;
    return 1;
    
}
int main() {
    //kruscal;
    cin >> V >> E;
    fill(p, p+V,-1);
    for (int i=0; i<E; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edge[i] = {c,a,b};
    }
    sort(edge, edge+E);
    int ans=0;
    int cnt=0;
    for (int i=0; i<E; i++) {
        int c,v1,v2;
        tie(c,v1,v2) = edge[i];
        if(!is_diff_group(v1,v2)) continue;
        ans+=c;
        cnt++;
        if(cnt == V-1) break;
    }
    cout << ans << '\n';
    return 0;
}
