/**
 BOJ 2533
- 체크 안된경우, 인접노드 모두 체크되있어야함
 - 체크 된경우에 상관없음
 
 - dp : 각 노드에서 체크여부에따라, 필요한 체크의 최소의 수
 - 단 단말노드에서는 예외, 체크된것이 몇개인지
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1000010];
vector<int> tree[1000010];
int dp[1000010][2];

void make_tree(int cur, int prv) {
    for(int x : adj[cur]) {
        if(x==prv) continue;
        tree[cur].push_back(x);
        make_tree(x, cur);
    }
}

int get_dp(int cur, int chk) {
    if(dp[cur][chk] != -1) return dp[cur][chk];
    
    if(tree[cur].size() ==0) {
        if(chk) return dp[cur][chk] = 1;
        else return dp[cur][chk] = 0;
    }
    
    int rs=0;
    if(chk) {
        rs++;
        for(int x : tree[cur]) {
            rs += min(get_dp(x, 0), get_dp(x,1));
        }
    } else {
        for(int x : tree[cur]) {
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
    for( int i=0; i<N-1; i++) {
        int a,b; cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    make_tree(1,-1);
    
    cout << min(get_dp(1,0), get_dp(1,1)) << '\n';
    
    return 0;
}
