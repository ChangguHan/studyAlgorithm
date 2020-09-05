#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

pair<int, pair<int, int> > edge[300010];
int p[300010];
// mst로 하면됨
// 그룹 미리 연결해놓으면 됫듯


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


int solution(int n, vector<vector<int>> network, vector<vector<int>> repair) {
    fill(p, p+300010, -1);
    for (auto x : network) {
        is_diff_edge(x.front(),x.back());
    }

    for (int i=0; i<repair.size(); i++) {
        edge[i] = make_pair(repair[i][2], make_pair(repair[i][0],repair[i][1]));
    }

    sort(edge, edge + repair.size());
    
    int cnt=network.size();
    int ans=0;


    for (int i=0; i<repair.size(); i++) {
        int cost,v1,v2;
        cost = edge[i].first;
        v1 = edge[i].second.first;
        v2 = edge[i].second.second;
        // tie(cost,v1,v2) = edge[i];
        
        if(!is_diff_edge(v1,v2)) continue;
        cnt++;
        ans += cost;
        if(cnt >= n-1) {
            return ans;
        }
    }

    return -1;

}

int main() {
    vector<vector<int>> network;
    network.push_back({1,2});
    network.push_back({3,5});
    network.push_back({4,2});
    network.push_back({5,6});

    vector<vector<int>> repair;
    repair.push_back({3,2,10});
    repair.push_back({5,4,15});
    // repair.push_back({2,3,10});
    // repair.push_back({3,1,12});

    cout << solution(6,network, repair) << '\n';


    return 0;
}
