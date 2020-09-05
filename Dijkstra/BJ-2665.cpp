// 다익스트라로 풀어보자
// 0을 비용으로 사용하면 됨

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <tuple>

using namespace std;
using ti3 = tuple<int, int, int>;

int N;
const int inf = 100;
int map[60][60];
int dist[60][60];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};

int main() {
    cin >> N;
    for (int j=0; j<N; j++) {
        string ip;
        cin >> ip;
        for (int i=0; i<ip.length(); i++) {
            map[j][i] = ip[i]-'0';
        }
    }
    fill(&dist[0][0], &dist[59][60],inf);

    priority_queue<ti3, vector<ti3>, greater<ti3> > pq;
    if(map[0][0]) dist[0][0] = 0;
    else dist[0][0] = 1;
    pq.push({dist[0][0], 0,0});

    while(!pq.empty()) {
        ti3 epq = pq.top(); pq.pop();
        int c, y, x;
        tie(c,y,x) = epq;
        if(dist[y][x] != c) continue;
        for(int k=0; k<4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny>=0 && ny<N && nx>=0 && nx<N) {
                int nc;
                if(map[ny][nx]) nc=0;
                else nc=1;
                if(dist[ny][nx] > c + nc) {
                    dist[ny][nx] = c+nc;
                    pq.push({dist[ny][nx],ny,nx});
                }
            }
        }
    }
    cout << dist[N-1][N-1] << '\n';



    return 0;
}