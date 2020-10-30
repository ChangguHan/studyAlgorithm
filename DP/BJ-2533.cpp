/**
 BOJ 2533
 
 - 인접노드가 모두 체크되어야 나도 체크
 - 모든 노드를 체크하기위해서 최소로 필요한  초기 체크의 계수
 
 - 트리 dp?
 - 간선이 하나인 것들뺴고?
 - 모르겠는데...
 
 
 각각 노드에서, 체크 되었을때와 안되었을때, 필요한 어댑터의 수
 
 O(V*2)
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1000010];
vector<int> tree[1000010];
int dp[1000010][2];
void make_tree(int cur, int prev) {
    for(int x : adj[cur]) {
        if(x == prev) continue;
        tree[cur].push_back(x);
        make_tree(x,cur);
    }
}

//각각 노드에서, 체크 되었을때와 안되었을때, 자기 포함해서 어댑터의 수
int get_dp(int cur, bool chk) {
    if(dp[cur][chk] != -1) return dp[cur][chk];
    
    // 말단노드일때
    if(tree[cur].size() ==0) {
        // 체크되있는 경우에는 필요없음
        if(chk) {
            return dp[cur][chk] = 1;
        }else return dp[cur][chk] = 0;
    }
    
    // 말단 노드 아닐때
    // 체크 되어있는지 아닌지에 따라 다름
    int rs=0;
    if(chk) {
        rs++;
        for(int x : tree[cur]) {
            rs += min(get_dp(x,0), get_dp(x,1));
        }
        return dp[cur][chk] = rs;
        
    } else {
        // 체크 안되어있으면 자식노드 체크된것 모두 더해줘야함
        for(int x : tree[cur]) {
            rs += get_dp(x, 1);
        }
        return dp[cur][chk] = rs;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    fill(&dp[0][0], &dp[N][2], -1);
    for(int i=0; i<N-1; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    make_tree(1,-1);
    
    cout << min(get_dp(1,0), get_dp(1,1)) << '\n';
    
    return 0;
}
