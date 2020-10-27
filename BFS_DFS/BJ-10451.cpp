/**
 BOJ 10451
 
 - 각 노드돌면서 다음 노드가 이전에 통과한건지 확인하는 방법
    - O(N^2), 시간초과 날 가능성 있음
 - chk 배열과, done 배열 사용
    - chk 배열은 지나간건지 확인
    - done : 내가 현재 보고있는건지 확인
    - chk =1 인데, done = 0 인경우, 사이클 종료
    - 사이클이 일부만 갈일 없으니까, 다시 탐색해줄필요없음
    - O(N)
 
  */

#include <iostream>

using namespace std;

bool chk[1010];
bool done[1010];
int nxt[1010];

void dfs(int cur) {
    if(!chk[cur]) {
        chk[cur] = 1;
        dfs(nxt[cur]);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        for(int i=1; i<=N; i++) cin >> nxt[i];
        fill(chk, chk+1010, 0);
        //fill(done, done+1010, 0);
        
        int cnt=0;
        
        for(int i=1; i<=N; i++) {
            if(chk[i]) continue;
            dfs(i);
            cnt++;
        }
        cout << cnt << '\n';
    }
    
    return 0;
}
