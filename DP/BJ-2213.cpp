/**
 BOJ 2213
 연속하지 않는 최대 가중치 값을 구하면 됨
 Tree DP
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int val[10010];
vector<int> adj[10010];
int dp[10010][2];
vector<int> tv;
bool chk[10010];
int dfs(int cur, bool include) {
    if(dp[cur][include] != -1) return dp[cur][include];
    chk[cur]=1;
    // 포함되어있으면 다음껀 안포함된걸로만
    int rs=0;
    if(include) {
        
        for(int x : adj[cur]) {
            // 부모노드만 빼려고 하는거잖아
            // 그니까 이미 지난건 뺴줘도 되지않을까
            if(chk[x]) continue;
            //
            rs += dfs(x,0);
        }
        chk[cur]=0;
        return dp[cur][1] = val[cur] + rs;
    } else {
        for(int x : adj[cur]) {
            if(chk[x]) continue;
            rs += max(dfs(x,0), dfs(x,1));
        }
        chk[cur]=0;
        return dp[cur][0] = rs;
    }
}
void track(int cur, bool include) {
    chk[cur]=1;
    if(include) {
        tv.push_back(cur);
        for(int x : adj[cur]) {
            if(chk[x]) continue;
            track(x,0);
        }
    } else {
        for(int x : adj[cur]) {
            if(chk[x]) continue;
            int t1 = dp[x][0];
            int t2 = dp[x][1];
            if(t1>=t2) track(x,0);
            else track(x,1);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(&dp[0][0], &dp[10009][2], -1);
    int N; cin >> N;
    for(int i=1; i<=N; i++) cin >> val[i];
    for(int i=0; i<N-1; i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    adj[0].push_back(1);
    
    dfs(0,0);
    fill(chk, chk+N+1, false);
    track(0,0);
    
    cout << dp[0][0] << '\n';
    sort(tv.begin(), tv.end());
    for(int x : tv) cout << x <<' ';
    cout << '\n';
    
    return 0;
}
