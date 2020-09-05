#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

pair<double, double> v[105];
pair<double, pair<int, int> > edge[6000];
int p[105];

int find(int v) {
    if(p[v]<0) return v;
    return p[v] = find(p[v]);
}

bool is_diff_group(int v1, int v2) {
    v1 = find(v1); v2 =find(v2);
    if(v1==v2) return 0;
    if(p[v1] == p[v2]) p[v1]--;
    if(p[v1] < p[v2]) p[v2] = v1;
    else p[v1] = v2;
    return 1;
}

int main() {
    int N;
    cin >> N;
    fill(p, p+N+1,-1);
    for (int i=1; i<=N; i++) {
        double a,b;
        cin >> a >> b;
        v[i] = make_pair(a,b);
    }

    int cnt=0;

    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            if(i==j) continue;
            cnt++;
            double v1x = v[i].first;
            double v1y = v[i].second;
            double v2x = v[j].first;
            double v2y = v[j].second;
            double cost = pow(pow(v1x-v2x,2) + pow(v1y-v2y,2),1/2);
            edge[cnt] = make_pair(cost, make_pair(i,j));
        }
    }
    sort(edge[1], edge[cnt]);
    int ans=0;
    int cnta=0;

    for(int i=1; i<=cnt; i++) {
        double ec = edge[i].first;
        double v1 = edge[i].second.first;
        double v2 = edge[i].second.second;
        if(!is_diff_group(v1,v2)) continue;
        ans += ec;
        cnta++;
        if(cnta == N-1) break;
    }

    cout << ans;

    return 0;
}