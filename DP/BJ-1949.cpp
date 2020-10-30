/**
 
 BOJ 1949
 
 - 추상화
    - 체크되있으면 체크되있지 않은것과 인접해야하고
    - 체크 안되어있으면 체크되어있는것과 인접해야할때
    - 체크되어있는것의 최대의 수
 
 - 트리 DP
    - 체크되있을떄와 되어있지 않을떄
    - 자식노드끼리의 인구 최대값을 구함
 
 - 시간복잡도
    - 모든 노드 도는거니까
    - O(N)
 
 -  INT
    - 1e8이므로 인트 가능
 */

#include <iostream>
#include <vector>

using namespace std;

int dp[10010][2];
int pp[10010];
vector<int> adj[10010];
vector<int> tree[10010];

void make_tree(int cur, int prv) {
    for( int x : adj[cur]) {
        if(x == prv) continue;
        tree[cur].push_back(x);
        make_tree(x,cur);
    }
}

int get_dp(int cur, bool chk) {
    if(dp[cur][chk] != -1) return dp[cur][chk];
    
    if(tree[cur].size()==0) {
        if(chk) return dp[cur][chk] = pp[cur];
        else return dp[cur][chk] = 0;
    }
    int rs=0;
    if(chk) {
        // 체크되있는 경우, 해당 노드랑, 체크안되잇는것 추가해줘야함
        rs += pp[cur];
        for(int x : tree[cur]) {
            rs += get_dp(x, 0);
        }
    } else {
        // 여기에서 전부 체크되어있지 않으면 어떻게하지
        // 체크된것중에 max를 하나 고르고
        // 나머진 체크여부 상관없이 추가
        
        // 이부분이 이해가 잘 안되긴 하는데
        // 다음에 생각하자
        
        for(int x : tree[cur]) {
            rs += max(get_dp(x,0), get_dp(x,1));
        }
        
    }
    return dp[cur][chk] = rs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    fill(&dp[0][0], &dp[N][2], -1);
    for(int i=1; i<=N; i++) cin >> pp[i];
    
    for(int i=0; i<N-1; i++) {
        int a,b; cin >>a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    make_tree(1,-1);
    
    cout << max(get_dp(1,0), get_dp(1,1)) << '\n';
    
    
    
    return 0;
}
