// 매턴마다  BFS로 먹이 찾음
// 매번 찾는것 O(N^2)
// 최대 N^2만큼 있을수 있음, O(N^4), 1e5


// 왜 시간초과가 날까...?
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> ti3;
int dy[] = {-1,0,0,1};
int dx[] = {0,-1,1,0};

int map[30][30];
int N; 
int sizes;
int sy,sx;

int bfs(int j, int i) {
    int cnt=0;
    priority_queue<ti3> q;
    
    q.push({0,j,i});


    bool chk[30][30];
    fill(&chk[0][0], &chk[29][30], false);

    chk[j][i]=1;
    while(!q.empty()) {
        cnt++;
        priority_queue<ti3> nq;
        int qsize = q.size();
        while(qsize--) {
            int a,b,c;
            tie(a,b,c)= q.top(); q.pop();
            if(map[b][c] < sizes && map[b][c] != 0 && map[b][c]<=6)  {
                map[sy][sx] = 0;
                sy = b; sx = c;
                map[b][c] = 9;
                return cnt-1;
            }
            
            int ey = b;
            int ex = c;
            for(int k=0; k<4; k++) {
                int ny = ey + dy[k];
                int nx = ex + dx[k];
                if(ny>=0 && ny < N && nx>=0 && nx<N) {
                    if(chk[ny][nx])continue;
                    if(map[ny][nx] > sizes) continue;
                    // 작은것 만났을때, 끝남
                    
                    if(map[ny][nx]<=sizes || map[ny][nx] ==0) {
                        chk[ny][nx]=1;
                        int ec=0;
                        if(k==0) ec+=100;
                        else if(k==1) ec +=1;
                        else if(k==2) ec -=1;
                        else if(k==3) ec -=100;
                        nq.push({a+ec,ny,nx});
                    }

                }
            }

        }
        q.empty();
        while(!nq.empty()) {
            q.push(nq.top());
            nq.pop();
        }
        
    }
    
    return -1;
}
int main() {
    cin >> N;
    
    for(int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            cin >> map[j][i];
            if (map[j][i] == 9) {
                sy = j;
                sx = i;
            }
        }
    }
    int rs=0;
    sizes=2;
    int exp=0;
    while(1) {
        // 물고기 찾기
        int ers = bfs(sy,sx);
        if(ers==-1){
            break;
        } else {
            rs += ers;
            exp++;
            if(sizes==exp) {
                sizes++;
                exp=0;
            }
        }
        // 만약 물고기 없으면 종료
    }
    cout << rs << '\n';
    return 0;
}