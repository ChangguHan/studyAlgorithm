// 조합구해서 : 2^(N*N)
// 각각 가능한지를 확인하면됨 N
// : N*2^(N*N) : 10*2^100, 1e31

// 체스판을 2개로 쪼개면
// N* 2^(N*N/4) : 10*2^25 : 3*e8 >> 3초

#include <iostream>

using namespace std;

int N;
int map[20][20];
int maxv=0;
int cnt=0;

bool chk(int y, int x) {
    int ey = y;
    int ex = x;
    ey--; ex--;
    while(ey>=0 && ex >=0 ) {
        if(map[ey][ex]==2) return false;
        ey--; ex--;
    }

    ey = y;
    ex = x;
    ey--; ex++;
    while(ey>=0 && ex <N ) {
        if(map[ey][ex]==2) return false;
        ey--; ex++;
    }

    return true;


}

void dfs(int idx) {
    maxv = max(cnt, maxv);
    for(int i=idx; i<N*N; i+=2) {
        int y = i/N;
        int x = i%N;
        // 짝수일경우 행넘어갈때 더해줘야함
        if(N%2==0) {
            if(y%2==1) {
                if(idx%2==0)x+=1;
                else x-=1;
            }
        }
        if(map[y][x] == 1) {
            if(chk(y,x)) {
                map[y][x] = 2;
                cnt++;
                
                dfs(i+2);
                map[y][x] = 1;
                cnt--;
            }            
        }
    }
    
}

int main() {
    cin >> N;
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            cin >> map[j][i];
        }
    }
    int rs=0;
    dfs(0);
    rs += maxv;
    maxv=0;
    cnt=0;
    dfs(1);

    cout << rs + maxv << '\n';


    return 0;
}