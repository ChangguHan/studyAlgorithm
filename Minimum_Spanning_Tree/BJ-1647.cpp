// kruscal 써서 N-2개 뽑으면 종료
// ElgE, 1e6*30, 3e7;


#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

tuple<int, int, int> edge[1000010];
int p[100010];

// tuple<int, int, int> edge[100];
// int p[100];

int find(int v) {
    if(p[v]<0) return v;
    return p[v] = find(p[v]);
}

bool is_diff_group(int v1, int v2) {
    v1 = find(v1); v2 = find(v2);
    if(v1==v2) return false;
    if(p[v1] == p[v2] ) p[v1]--;
    if(p[v1] < p[v2]) p[v2] = v1;
    else p[v2] = v1;
    return true;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,M; cin >> N>>M;
    fill(p, p+N+1, -1);
    for(int i=0; i<M; i++) {
        int a,b,c; cin>> a >> b >> c;
        edge[i] = {c,a,b};
    }

    sort(edge, edge+M);

    int cnt=0;
    int ans=0;
    for (int i=0; i<M; i++) {
        int a,b,c;
        tie(c,a,b) = edge[i];
        if(!is_diff_group(a,b)) continue;
        cnt++;
        ans+=c;
        if(cnt==N-2) break;
    }

    cout << ans <<'\n';
    return 0;
}