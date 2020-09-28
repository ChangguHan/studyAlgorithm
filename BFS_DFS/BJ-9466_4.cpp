/**
 BOJ 9466
 
 돌면서 지나온거 있는지 다시한번 확인하는 경우 O(N^2) : 1e10 시간초과
 
 체크하는게 하나는 필요해 : 그래야 다시 돌지 못하지
 배열을 하나 더사용해서, 현재 돌고있는것과를 비교해주자
 
 */

#include <iostream>

using namespace std;

bool chk[100010];
bool done[100010];
int N;
int nxt[100010];
int cnt=0;

void dfs(int v) {
    chk[v] = 1;
//    자기 자신일경우 추가
    if(nxt[v]==v) cnt++;
    else {
        if(!chk[nxt[v]]) dfs(nxt[v]);
        else if(!done[nxt[v]]) {
            int cur = nxt[v];
            while(cur != v) {
                cnt++;
                cur = nxt[cur];
            }
            cnt++;
        }
    }
    
    done[v] = 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while(T--) {
        cin >> N;
        fill(chk, chk+N+1, 0);
        fill(done, done+N+1, 0);
        
        cnt=0;
        for(int i=1; i<=N; i++) cin >> nxt[i];
        for(int i=1; i<=N; i++) {
            if(!chk[i]) dfs(i);
        }
        cout << N-cnt << '\n';
    }
    
    
    return 0;
}
