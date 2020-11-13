/**
 BOJ 2533
 - 트리구조에서 연결노드가 모두 체크되어있거나, 내가 체크되어있어야함
 - 트리 DP
    - O(NM),
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1000010];
vector<int> tree[1000010];
int dp[1000010][2];
void make_tree(int cur, int pre) {
    for(int x : adj[cur]) {
        if(x==pre)continue;
        tree[cur].push_back(x);
        make_tree(x, cur);
    }
}

int get_dp(int cur, bool chk) {
    if(dp[cur][chk] != -1) return dp[cur][chk];
    
    // 만약 자식노드없을떄 먼저
    if(tree[cur].size() ==0) {
        if(chk) return dp[cur][chk] = 1;
        else return dp[cur][chk] = 0;
    }
    
    // 체크되어있을경우, 아무거나 상관없이 작은거면 됨
    int rs=0;
    if(chk) {
        rs++;
        for(int x : tree[cur]) {
            rs += min(get_dp(x, 0), get_dp(x,1) );
        }
        
    } else {
        // 체크 안되어있을떄, 모두 체크되어야함
        for(int x : tree[cur] ) {
            rs += get_dp(x,1);
        }
    }
    return dp[cur][chk] = rs;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;

    fill(&dp[0][0], &dp[N][2], -1);

    for(int i=0; i<N-1; i++) {
        int a,b; cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // 트리 만들기
    make_tree(1,-1);
    
    // 트리 dp
    cout << min(get_dp(1,1), get_dp(1,0)) << '\n';
    return 0;
}
