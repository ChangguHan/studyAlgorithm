// MST prim으로 해보자

#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int N;
pair<double, double> gd[110];
bool chk[110];

int main() {
    cin >> N;
    for (int i=1; i<=N; i++) {
        double a,b;
        cin >> a >> b;
        gd[i] = make_pair(a,b);
    }

    priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;

    for (int i=2; i<=N; i++) {
        double dist = sqrt(pow(gd[i].first-gd[1].first,2) + pow(gd[i].second-gd[1].second,2));
        pq.push(make_pair(dist, i));
    }
    chk[1] = 1;
    double ans=0;
    int cnt=0;

    while(!pq.empty()) {
        auto eq = pq.top(); pq.pop();
        if(chk[eq.second]) continue;
        chk[eq.second]=1;
        cnt++;
        ans+= eq.first;
        if(cnt==N-1) break;
        for (int i=1; i<=N; i++) {
            if(chk[i]) continue;
            if(i==eq.second) continue;
            double dist = sqrt(pow(gd[i].first-gd[eq.second].first,2) + pow(gd[i].second-gd[eq.second].second,2));
            pq.push(make_pair(dist, i));
        }
    }
    cout << round(ans*100)/100 << '\n';



    return 0;
}