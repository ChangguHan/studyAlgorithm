// DFS로 해보자, 재귀

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[110];
bool chk[110];
int rs=0;
void dfs(int v) {
    rs++;
    for(int x : adj[v]) {
        if(chk[x]) continue;
        chk[x]=1;
        dfs(x);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int v,e; cin >> v >> e;
    for(int i=0; i<e; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    chk[1] = 1;
    dfs(1);

    cout << rs-1 << '\n';

    return 0;
}