/**
 
 BOJ 1693
 - 인접한 색깔 칠하려면 dp 이요하면됨
 - dp : 현재 트리 위치에서, 해당 색깔 칠하려고 할때, 비용의 최소값
    - 근데 인접노드의 최소값을 어떻게 구하지
    - 내가 1의 색깔일때, 자식노드가 3개야, 그럼 2,3,4를 각각?
    - 아니지, 인접하지 않으니까 자식끼리는 다 같을 필요가 없음
    - 그냥 모든 색깔중에, 가장 낮은 비용을 구하면 됨
    - 시간복잡도 :
        - 모든 노드에서 N
        - 부모 노드의 모든 색깔중에 N
        - 자식노드는 부모도느와 겹치지 않는 모든 색중 최소값 결정 N
    -
 
 - 시간복잡도
    - O(N^3), e15 시간초과
    - 근데 색깔을 줄일수있지 않을까?
        - 색 2개일때, 최소 노드 수 1개 + 1개
        - 색 3개, 최소노드 1개  + 2개 + 1개
        - 색 4개, 최소녿 1개 + 2개 + 3개 + 1개
        - P(N) = P(1) ~ P(N-1) + 1
        - P(N-1) = P(1) ~ P(N-2) + 1
        - P(N) = 2(P(1) ~ P(N-2) ) + 1 + 1
        - P(N-2) =  P(1) ~ P(N-3) + 1
        - P(N) = 4(P(1) ~ P(N-3) ) 2 +1 + 1
        - P(N-3) = P(1) ~P(N-4) + 1
        - P(N) = 2^3(P(1) ~ P(N-4) + 2^2 + 2^1 + 1 + 1
 
        - P(N) = 1 + 2^N-1
    - N개의 색일때, 최소 노드의 수는 2^N개,
    - 그럼 10만개일의 노드일떄는 lg(10만)개의 색이 필요
        - e^5, 보수적으로 e^6, 20개, 21개로 하고 진행ㅎ자ㅏ
 
        -
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100010];
vector<int> tree[100010];
int dp[100010][21];

void make_tree(int cur, int pre) {
    for(int x : adj[cur]) {
        if(x==pre) continue;
        tree[cur].push_back(x);
        make_tree(x, cur);
    }
}

int get_dp(int cur, int color) {
    if(dp[cur][color] != -1) return dp[cur][color];
    
    int rs=color;
    for(int x : tree[cur]) {
        int emv = 21*1e5;
        for(int i=1; i<=20; i++) {
            if(i==color) continue;
            emv = min(emv, get_dp(x, i));
        }
        rs += emv;
    }
    
    return dp[cur][color] = rs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    fill(&dp[0][0], &dp[N][21], -1);
    for(int i=0; i<N-1; i++) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    make_tree(1,-1);
    
    int minv = 21 * 1e5;
    for(int i=1; i<=20; i++) {
        minv = min(minv, get_dp(1,i));
    }
    cout << minv << '\n';
    
    return 0;
}
