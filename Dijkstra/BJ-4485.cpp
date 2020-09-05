// 2차원 다익스트라

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
using ti3 = tuple<int, int, int>;

int N;
const int inf = 1300;
int map[140][140];
int dist[140][140];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int main() {
    ios::sync_with_stdio(0);
    int tn=0;
    while(1) {
        tn++;
        cin >> N;
        if(N==0) return 0;
        
        fill(&dist[0][0], &dist[N-1][N], inf);

        for (int j=0; j<N; j++) {
            for (int i=0; i<N; i++) {
                cin >> map[j][i];
            }
        }
        priority_queue<ti3, vector<ti3>, greater<ti3> > pq;
        dist[0][0] = map[0][0];
        pq.push({dist[0][0],0,0});

        while(!pq.empty()) {
            ti3 epq = pq.top(); pq.pop();
            int c,ey,ex;
            tie(c,ey,ex) = epq;

            if(dist[ey][ex] != c) continue;

            for (int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];

                if(ny>=0 && ny<N && nx>=0 && nx <N) {
                    if(dist[ny][nx] > dist[ey][ex] + map[ny][nx]) {
                        dist[ny][nx] = dist[ey][ex] + map[ny][nx];
                        pq.push({dist[ny][nx],ny,nx});
                    }
                }
            }
        }

        cout << "Problem " << tn << ": " << dist[N-1][N-1] <<'\n';

    }


    return 0;
}