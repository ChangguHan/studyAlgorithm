#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

tuple<int, int, int> edge[100010];
int p[1010];
int N,M;

int find(int v) {
    if(p[v] <0) return v;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    fill(p, p+N+1,-1);
    for (int i=1; i<=M; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edge[i] = {c,a,b};
    }
    sort(edge, edge+M+1);
    int cnt=0;
    int ans=0;

    for (int i=1; i<=M; i++ ) {
        int c,v1,v2;
        tie(c,v1,v2) = edge[i];
        if(!is_diff_group(v1,v2)) continue;
        cnt++;
        ans +=c;
        if(cnt==N-1) break;

    }
    cout << ans << '\n';


    return 0;
}
