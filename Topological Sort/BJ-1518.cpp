/**
 BOJ 1518
 
 위상정렬
 
 - 각 indeg 넣어주고
    - 각 비용 다음에 건물 숫자 나올떄마다, indeg 높여주고
    - 건물의 adj에 추가해줌
 - indeg 없을 경우, 계산
 - 배열의 해당 인덱스에 끝난 시간넣음
 - 각 배열마다 출력
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[510];
vector<int> adj_need[510];
int cost[510];
int indeg[510];
int rs[510];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> cost[i];
        while(1) {
            int a; cin >> a;
            if(a==-1) break;
            indeg[i]++;
            adj[a].push_back(i);
            adj_need[i].push_back(a);
        }
    }
    
    queue<int> q;
    for(int i=1; i<=N; i++) {
        if(indeg[i] == 0) q.push(i);
    }
    
    while(!q.empty()) {
        int eq = q.front(); q.pop();
        int ec = 0;
        for(int x : adj_need[eq]) {
            ec = max(ec, rs[x]);
        }
        rs[eq] = ec + cost[eq];
        
        for(int x : adj[eq]) {
            indeg[x]--;
            if(indeg[x]==0) q.push(x);
        }
    }
    
    for(int i=1; i<=N; i++) cout << rs[i] << '\n';
    return 0;
}


