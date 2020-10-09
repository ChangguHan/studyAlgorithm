/**
 BOJ 1693

 백트로 하면 N^N, 시간초과
 트리 디피로 하면 되겠다
 - N개 색깔 하는 경우
 - N^2의 공간 복잡도, 1e10, 4*e10, 40GB
    - 이 색을 줄일 수 있는 방법이 있을까
 
 - 점화식은 dp[n] = 최소값 dp[k][1~n], N^2, e10, 시간초과
 
 N개의 색을 줄일 수 있을까
 S(N)이 N개의 색을 칠할떄 필요한 최소의 노드 개수라면
 - S(1) = 1
 - S(N) = S(N-1) + S(N-2) ... S(1) + 1 이기 때문에
 - S(N) = 2^(N-1) 이되고
 - 2^(N-1) =  100000이니까,
  - N -1 = log2(100,000) = 약 2^10 * 2^7. 17
 N = 18, 그럼 20으로 해보자
 
 그럼 ㄱ동간복잡도 20, 1e5, 2e6, 2MB
  시간복잡도 2e6
 
  >> OK!!
 
 */

#include <iostream>
#include <vector>
using namespace std;

int dp[100010][21];
vector<int> adj[100010];
vector<int> tree[100010];
bool chk[100010];
void make_tree(int node,int pre) {
    for(int x : adj[node]) {
        if(x==pre) continue;
        tree[node].push_back(x);
        make_tree(x,node);
    }
    
}
int dfs(int cur, int color) {
    if(dp[cur][color] != -1)  {
        return dp[cur][color];
    }
    // 1부터 20까지 색일때
    int tmp=0;
    
    for(int x : tree[cur]) {
        int minv = 2e6;
        for(int i=1; i<=20; i++) {
            if(i==color) continue;
            minv = min(minv, dfs(x,i));
            
        }
        if(minv==2e6) minv = 0;
        tmp += minv;
        
    }
    return dp[cur][color] = tmp + color;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;cin >> N;
    fill(&dp[0][0], &dp[100009][20], -1);
    
    for(int i=0; i<N-1; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    make_tree(1,-1);
    int minv = 2e6;
    for(int i=1; i<=20; i++) {
        minv =  min(minv, dfs(1,i));
    }
    cout << minv << '\n';
    
    return 0;
}
