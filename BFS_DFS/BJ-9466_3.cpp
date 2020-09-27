/**
 BOJ 9466
 사이클 문제
 
 한점에서 dfs 돌다가, 찾으면, 그자리에서 여태껏 지나온것만 추가
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nxt[100010];
bool chk[100010];
bool done[100010];
int cnt=0;
vector<int> vec;
// 시작점만 가지고 있으면 안돼
// 모든값을 가지고있어야돼
// 그래야 중간에서 끝나지

// 모든값 탐색하면 시간이 V^2로 걸려서 시간초과
// 배열 하나 더추가해서 두번체크
// 이미 한번 체크했는데, 한번 더 체크 안되있는거는 현재 사이클 중이란 것
// 그럼 거기부터, 현재까지 해주면되지
void dfs(int v) {
    if(!chk[nxt[v]]) {
        chk[nxt[v]]=1;
        dfs(nxt[v]);
    }else if(!done[nxt[v]]) {
        for(int k=nxt[v]; k != v; k = nxt[k]) {
            cnt++;
        }
        cnt++;
    }
    done[v]=1;
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    while(T--) {
        
        int N; cin >> N;
        fill(chk, chk+N+1, false);
        fill(done, done+N+1, false);
        for(int i=1; i<=N; i++) cin>> nxt[i];
        cnt=0;
        for(int i=1; i<=N; i++) {
            if(!chk[i]) {
               chk[i]=1;
                vec.clear();
                dfs(i);
            }
        }
        
        cout << N-cnt << '\n';
        
    }
    
    return 0;
}
