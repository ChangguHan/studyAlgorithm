/**
 BOJ 9466
 - 싸이클 확인하는 문제
 - O(N^2)로할경우 시간초과
 
 - 배열 두개사용학
    - 하나는 들어온것
    - 하나는 마무리지은것
 - 해당 노드에 들어갔는데, 들어왔지만, 마무리가안되있는거일경우 리턴

 */

#include <iostream>

using namespace std;

bool chk[100010];
bool done[100010];
int N;
int nxt[100010];
int rs;

void dfs(int cur) {
    chk[cur] = 1;
    int next = nxt[cur];
    
    if(!chk[next]) {
        dfs(next);
    } else if(!done[next]) {
        int now = next;
        rs++;
        while(now != cur) {
            rs++;
            now = nxt[now];
        }
    }
    done[cur] = 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while(T--) {
        fill(chk, chk+100010, 0);
        fill(done, done+100010, 0);
        cin >> N;
        for(int i=1; i<=N; i++) cin >> nxt[i];
        rs=0;
        
        for(int i=1; i<=N; i++) {
            if(!chk[i]) dfs(i);
        }
        
        cout << N-rs << '\n';
    }
    
    return 0;
}
