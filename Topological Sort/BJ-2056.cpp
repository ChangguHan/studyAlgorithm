/**
 BOJ 2056
 
 - 위상정렬
 
 - 데이터 입력
    - 각 코스트 저장하고
    - indeg 수 저장
    - 각 노드에서 나가는것, 들어오는것 ㅓ모두 저장
 - 큐에서 뺄때
    - 필요 작업중 최대 오래걸린것에서, 내자신 더한것 저장
 
 - 전체에서 max값 출력
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int cost[10010];
vector<int> adj[10010];
vector<int> adj_need[10010];
int indeg[10010];
int rs[10010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> cost[i];
        int en; cin >> en;
        indeg[i] = en;
        while(en--) {
            int ev; cin >> ev;
            adj[ev].push_back(i);
            adj_need[i].push_back(ev);
        }
    }
    
    queue<int> q;
    for(int i=1; i<=N; i++) {
        if(indeg[i]==0) q.push(i);
    }
    
    while(!q.empty()) {
        int eq = q.front();q.pop();
        int ers = 0;
        for(int x : adj_need[eq]) {
            ers = max(ers, rs[x]);
        }
        rs[eq] = ers + cost[eq];
        
        for(int x : adj[eq]) {
            indeg[x]--;
            if(indeg[x]==0) q.push(x);
        }
    }
    
    cout << *max_element(&rs[1], &rs[N]+1) << '\n';
    
    return 0;
}

