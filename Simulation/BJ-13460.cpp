// 4방향 백트래킹 >> 4^10
// 2^20 = 1e6

// 구슬 경로 탐색 20, 2e7

#include <iostream>
#include <string>

using namespace std;

char map[20][20];
int N,M;
int ry,rx,by,bx;
int dep = 1;
int rs = 11;
void turn() {
    char mapb[20][20];
    fill(&mapb[0][0], &mapb[19][20], '\0');
    for(int j=0; j<N; j++) for (int i=0; i<M; i++) mapb[j][i] = map[j][i];
    fill(&map[0][0], &map[19][20], '\0');
    //fill(&map[0][0], &map[19][20], "");
    int tmp = M;
    M = N;
    N = tmp;
    for(int j=0; j<N; j++) {
        for (int i=0; i<M; i++) {
            map[j][i] = mapb[M-1-i][j];
        }
    }
    tmp = by;
    by = bx;
    bx = M-1-tmp;

    tmp = ry;
    ry = rx;
    rx = M-1-tmp;
}

void happyend() {
    
    rs = min(rs, dep);
}
bool push() {
    // 빨간아래에 있으면 빨간공먼저
    int oby = by; int obx = bx;
    int ory = ry; int orx = rx;
    if(ry>by && rx==bx) {
        bool sw = false;
        while(1) {
            ry++;
            
            if(map[ry][rx]=='O') {
                sw = true;
                map[ory][rx] = '.';
                break;
            }
            if(map[ry][rx] == '#') {
                ry--;
                if(ory != ry) {
                    map[ry][rx] = 'R';
                    map[ory][rx] = '.';
                }
                break;
            }

        }
        while(1) {
            by++;
            if(map[by][bx]=='O') {
                // 빠지면 안되는걸로 끝나는건데,
                return false;
            }
            
            if(map[by][bx] == '#'||map[by][bx] == 'R') {
                by--;
                if(oby != by) {
                    map[by][bx] = 'B';
                    map[oby][bx] = '.';
                }
                break;
            }
        }
        // 안빠질 경우, 빨간게 빠졌으면 종료
        if(sw) {
            happyend();
            return false;
        }

    } else {
        // 아니면 무조건 파란공먼저
        while(1) {
            by++;
            if(map[by][bx]=='O') return false;
            if(map[by][bx] == '#') {
                by--;
                if(oby != by) {
                    map[by][bx] = 'B';
                    map[oby][bx] = '.';
                }
            
                break;
            }
        }

        while(ry<N-1) {
            ry++;
            if(map[ry][rx]=='O') {
                happyend();
                return false;
            }
            if(map[ry][rx] == '#'||map[ry][rx] == 'B') {
                ry--;
                if(ory != ry) {
                    map[ry][rx] = 'R';
                    map[ory][rx] = '.';
                }
                break;
            }

        }


    }
    if(ory==ry && orx == rx && oby==by && obx == bx) return false;
    return true;

}

void dfs() {
    if(dep==11) {
        return;
    }
    char mapb[20][20];
    for(int j=0; j<N; j++) for (int i=0; i<M; i++) mapb[j][i] = map[j][i];
    int oby = by; int obx = bx;
    int ory = ry; int orx = rx;
    int oN = N; int oM = M;
    for (int k=0; k<4; k++) {
        N = oN; M = oM;
        for(int j=0; j<N; j++) for (int i=0; i<M; i++) map[j][i] = mapb[j][i];
        by = oby; bx = obx; ry = ory; rx = orx;
        
        for (int kk=0; kk<k; kk++) turn();
        if(push()) {
            dep++;
            dfs();
            dep--;
        }
        
    }

}
int main() {
    cin >> N >> M;
    for (int j=0; j<N; j++) {
        string ip;
        cin >> ip;
        for (int i=0; i<M; i++) {
            map[j][i] = ip[i];
            if(map[j][i] == 'B') {
                by = j; bx = i;
            }
            if(map[j][i] == 'R') {
                ry = j; rx = i;
            }
        }
    }

    dfs();
    if(rs==11)cout << -1 << '\n';
    else cout << rs << '\n';


    return 0;
}
