/**
 BOJ 4485
 
최소거리로 지나가야함
그래프 탐새긍로해도되고,
 다익스트라로 해도됨
 
 그럼 dfs, bfs, Dijk 다해보자
 
그래프탐색으로 하면 시간복잡도.. 모르겠음
 한번 간곳도 다시지날 수 있으니까 O(V+E)는 아님
 더 많을듯, 최악의 케이스, O(N^3)?
 
 // OK, DFS 시간초과
 // BFS는 그래도 조금 나을듯
 
 
 
 
 */


#include <iostream>
#include <queue>

using namespace std;

const int inf = 2000;
int map[140][140];
int score[140][140];

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int N;


// DFS
//void dfs(int y, int x) {
//    for(int k=0; k<4; k++) {
//        int ny = y+ dy[k];
//        int nx = x + dx[k];
//        if(ny >=0 && ny < N && nx>=0 && nx < N) {
//            if(score[ny][nx] > score[y][x] + map[ny][nx]) {
//                score[ny][nx] =score[y][x] + map[ny][nx];
//                dfs(ny,nx);
//            }
//        }
//    }
//
//}
//int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    while(1) {
//        cin >> N;
//        if(N==0) break;
//        fill(&score[0][0], &score[139][140], inf);
//        for(int j=0; j<N; j++) {
//            for (int i=0; i<N; i++) {
//                cin >> map[j][i];
//            }
//        }
//        score[0][0] = map[0][0];
//        dfs(0,0);
//        cout << score[N-1][N-1] << '\n';
//    }
//    return 0;
//}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int idx=0;
    while(1) {
        idx++;
        cin >> N;
        if(N==0) break;
        fill(&score[0][0], &score[139][140], inf);
        for(int j=0; j<N; j++) {
            for (int i=0; i<N; i++) {
                cin >> map[j][i];
            }
        }
        score[0][0] = map[0][0];
        queue<pair<int, int> > q;
        q.push(make_pair(0,0));
        while(!q.empty()) {
            auto eq = q.front();
            q.pop();
            
            int ey = eq.first;
            int ex = eq.second;
            for(int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];
                if(ny>=0 && ny < N && nx>=0 && nx < N) {
                    if(score[ny][nx] > score[ey][ex] + map[ny][nx]) {
                        score[ny][nx] = score[ey][ex] + map[ny][nx];
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }
        
        cout << "Problem "<<idx<<": " << score[N-1][N-1] << '\n';
    }
    return 0;
}
