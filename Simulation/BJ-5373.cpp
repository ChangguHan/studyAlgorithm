// 큐빙
// 각 쿼리당 돌려주면 될것같은데
// map 설정한다음
// 각 돌리기(O(N))


#include <iostream>
#include <string>

using namespace std;

char cube[9][12] ={
    {'-','-','-','w','w','w','-','-','-','-','-','-'},
    {'-','-','-','w','w','w','-','-','-','-','-','-'},
    {'-','-','-','w','w','w','-','-','-','-','-','-'},
    {'g','g','g','r','r','r','b','b','b','o','o','o'},
    {'g','g','g','r','r','r','b','b','b','o','o','o'},
    {'g','g','g','r','r','r','b','b','b','o','o','o'},
    {'-','-','-','y','y','y','-','-','-','-','-','-'},
    {'-','-','-','y','y','y','-','-','-','-','-','-'},
    {'-','-','-','y','y','y','-','-','-','-','-','-'}
                };


void turnwiseclock(int y, int x) {
    char tmp[9][12];
    for(int j=0; j<9; j++) {
        for(int i=0; i<12; i++) tmp[j][i] = cube[j][i];
    }
    for(int j=0; j<3; j++) {
        for (int i=0; i<3; i++){
            int ey =  y+j, ex=x+i;
            cube[ey][ex] = tmp[y+i][x-j];
        }

    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        while(n--) {
            string s; cin >> s;
            // 우선 그방향 시계, 반시계 돌려야하고
            // 이건 반시계 구현해서 세번 돌리는걸로
            int ey,ex;
            if(s[0]=='U') {
                ey=0; ex=3;
            } else if(s[0]=='D') {
                ey=6; ex=3;
            } else if(s[0]=='F') {
                ey=3; ex=3;
            } else if(s[0]=='B') {
                ey=3; ex=9;
            } else if(s[0]=='L') {
                ey=3; ex=0;
            } else if(s[0]=='R') {
                ey=3; ex=6;
            }

            if(s[1]=='+'){
                turnwiseclock(ey,ex);
                turnwiseclock(ey,ex);
                turnwiseclock(ey,ex);
            }else {
                turnwiseclock(ey,ex);
            }

            
            // 옆에꺼 돌려야 하는데, 이게 좀 복잡할듯
        }
    }


    return 0;
}