// 고립으로 섬 인덱스 먹이고
// 각 섬에서 노드 뻗어나가, 인접리스트 만들어주고 최소값 갱신
// 만들어준 최소노드로 MST


#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int N,M;
int map[15][15];
int mapy[15][15];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
int mapindex=1;
int adj[10][10];
tuple<int, int, int> edge[110];
int p[10];

int find(int v) {
    if(p[v] < 0) return v;
    return p[v] = find(p[v]);
}

bool is_diff_group(int v1, int v2) {
    v1 = find(v1); v2 = find(v2);
    if(v1==v2) return 0;
    if(p[v1] == p[v2] ) p[v1]--;
    if(p[v1] < p[v2]) p[v2] = v1;
    else p[v1] = v2;
    return 1;

}

void bfs(int y, int x, int mi) {
    // 뻗어나가서, 다른 섬 만나면 인접리스트 추가
    // 인접리스트 쓰지말고, 배열로 쓰자 그게 최소값이 좋음
    for (int k=0; k<4; k++) {
        int ny = y;
        int nx = x;
        bool sw=false;
        int cnt=0;
        while(1) {
            cnt++;
            ny += dy[k];
            nx += dx[k];
            if(!(ny>=0 && ny<N && nx>=0 && nx<M)) break;
            if(mapy[ny][nx]!=0) {
                if(mapy[ny][nx]!=mi) sw = true;
                break;
            }
        }

        if(sw) {
            cnt--;
            if(cnt<2) continue;
            if(adj[mi][mapy[ny][nx]] == -1) {
                adj[mi][mapy[ny][nx]] = cnt;
                adj[mapy[ny][nx]][mi] = cnt;
            }
            else {
                adj[mi][mapy[ny][nx]] = min(cnt, adj[mi][mapy[ny][nx]]);
                adj[mapy[ny][nx]][mi] = min(cnt, adj[mi][mapy[ny][nx]]);

            }
        }

    }

}

void dfs(int y, int x) {
    for (int k=0; k<4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if(ny>=0 && ny<N && nx>=0 && nx<M) {
            if(mapy[ny][nx] == 9) {
                mapy[ny][nx] = mapindex;
                dfs(ny,nx);
            }
        }


    }
}
int main() {
    cin >> N >> M;
    for (int j=0; j<N; j++) {
        for (int i=0; i<M; i++) {
            cin >> map[j][i];
            if(map[j][i]==1) mapy[j][i]=9;
            else mapy[j][i] = map[j][i];
        }
    }
    fill(&adj[0][0], &adj[9][10], -1);
    fill(p,p+10,-1);
    
    //영역 구하기
    
    for(int j=0; j<N; j++) {
        for (int i=0; i<M; i++) {
            if(mapy[j][i]==9) {
                mapy[j][i] = mapindex;
                dfs(j,i);
                mapindex++;
            }
        }
    }
    mapindex--;

    // 각 영역에서 뻗어나가서 인접리스트 만들기
    for(int mi=1; mi<=mapindex; mi++) {
        for (int j=0; j<N; j++) {
            for (int i=0; i<M; i++) {
                if(mapy[j][i] == mi) {
                    bfs(j,i,mi);
                }
            }
        }
    }

    // Kruscal 시작
    int ei=0;
    for (int j=1; j<=mapindex; j++) {
        for(int i=j+1; i<=mapindex; i++) {
            if(adj[j][i] != -1) {
                edge[ei] = {adj[j][i],j,i};
                ei++;
            }
        }
    }

    sort(edge,edge+ei);
    int ans=0;
    int cnt=0;
    int sw=false;
    for (int i=0; i<ei; i++) {
        int c,v1,v2;
        tie(c,v1,v2) = edge[i];
        if(!is_diff_group(v1,v2)) continue;
        ans+=c;
        cnt++;
        if(cnt==mapindex-1) {
            sw = true;
            break;
        }
    }
    if(sw) cout << ans <<'\n';
    else cout << -1 <<'\n';



    return 0;
}