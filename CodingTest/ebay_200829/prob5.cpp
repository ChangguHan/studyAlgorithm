// dfs의 최대값을 구하면 안되나

#include <iostream>

#include<vector>
using namespace std;
int ers = 0;
int maxv = 0;
bool chk[200010];
vector<int> adj[200010];
vector<int> tt;
void dfs(int k) {
    for(int x : adj[k]) {
        if(chk[x] == 0) {
            chk[x] = 1;
            ers += tt[x-1];
            dfs(x);
            ers -= tt[x-1];
            chk[x] = 0;
        }
    }
    maxv = max(maxv, ers);
}
int solution(vector<int> T, vector<vector<int>> R, int k)
{
    
    tt = T;
    
    for(auto x : R) {
        adj[x[1]].push_back(x[0]);
    }
    chk[k]=1;

    dfs(k);

    return maxv + T[k-1];
}

int main() {
    vector<int> t;
    
    t.push_back(5);
    t.push_back(8);
    t.push_back(3);
    t.push_back(7);
    t.push_back(10);
    t.push_back(5);
    t.push_back(4);

    vector<vector<int> > r;
    vector<int> er;

    er.clear();
    er.push_back(1);
    er.push_back(2);
    r.push_back(er);

    er.clear();
    er.push_back(2);
    er.push_back(4);
    r.push_back(er);

    er.clear();
    er.push_back(1);
    er.push_back(4);
    r.push_back(er);

    er.clear();
    er.push_back(6);
    er.push_back(5);
    r.push_back(er);

    er.clear();
    er.push_back(3);
    er.push_back(5);
    r.push_back(er);

    er.clear();
    er.push_back(4);
    er.push_back(6);
    r.push_back(er);
    

    cout << solution(t,r,5) << '\n';
    return 0;
}