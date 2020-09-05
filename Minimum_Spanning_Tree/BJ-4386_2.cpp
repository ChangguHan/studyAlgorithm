// MST, Kruscal, prim 해보자

#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
tuple<double, int, int> edge[10000];
pair<double, double> gd[110];
int p[110];
int find(int v) {
    if(p[v]<0) return v;
    return p[v] = find(p[v]);
}
bool is_diff_group(int v1, int v2) {
    v1 = find(v1); v2 =find(v2);
    if(v1==v2) return 0;
    if(p[v1] == p[v2]) p[v1]--;
    if(p[v1]<p[v2]) p[v2] = v1;
    else p[v1] = v2;
    return 1;
}
int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        double a,b;
        cin >> a >> b;
        gd[i] = make_pair(a,b);
    }
    fill(p,p+N,-1);
    int idx=1;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if(i==j) continue;
            double dist = sqrt(pow(gd[i].first-gd[j].first,2) + pow(gd[i].second-gd[j].second,2));
            edge[idx] = {dist, i,j};
            idx++;
        }
    }
    double ans=0;
    int cnt=0;
    sort(edge, edge+idx-1);

    for (int i=1; i<idx; i++) {
        double c;
        int v1,v2;
        tie(c,v1,v2) = edge[i];
        if(!is_diff_group(v1,v2)) continue;
        cnt++;
        ans+=c;
        if(cnt==N-1) break;

    }

    cout << round(ans*100)/100 << '\n';

}