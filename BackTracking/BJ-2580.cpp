// 빈칸 모아서
// 각각칸에 1부터 9까지 넣어보면서 chk해봄
// 빈칸 최대개수 81개
// 9^81

// 너무 많아서 가지를 잘치는 수밖에 없겠는데

#include <iostream>
#include <vector>

using namespace std;

int map[15][15];
int N=9;
vector<pair<int,int> > v;
bool chk(int y, int x) {
    // 가로
    bool ck[10];
    fill(ck, ck+10,false);
    for(int i=0; i<N; i++) {
        if(map[y][i]== 0) continue;
        if(ck[map[y][i]]) return false;
        ck[map[y][i]]=1;
    }

    // 세로
    fill(ck, ck+10,false);
    for(int j=0; j<N; j++) {
        if(map[j][x]== 0) continue;
        if(ck[map[j][x]]) return false;
        ck[map[j][x]]=1;
    }

    // 사각형
    int dy = y/3 * 3;
    int dx = x/3 * 3;
    fill(ck, ck+10,false);
    for (int j=0; j<3; j++) {
        for (int i=0; i<3; i++) {
            int ey = dy+j;
            int ex = dx+i;
            if(map[ey][ex] ==0) continue;
            if(ck[map[ey][ex]]) return false;
            ck[map[ey][ex]]=1;
        }
    }

    return true;


}
void dfs(int dep) {
    if(dep == v.size()) {
        for(int j=0; j<N; j++) {
            for (int i=0; i<N; i++) cout << map[j][i] <<' ';
            cout << '\n';
        }
        exit(0);
    }

    for(int i=1; i<=9; i++) {
        int ey = v[dep].first;
        int ex = v[dep].second;
        map[ey][ex] = i;
        if(chk(ey,ex)) {
            dfs(dep+1);
        }
        // 0으로 다시 안바꿔줬을때 안되는 이유
        // 무조건 dfs로 나가면 상관없는데,
        // if문 써서 체크한다음 다음 dfs로 나갈 경우,
        // 모든 경우에 통과되지 않으면 이전 dfs로 돌아올수밖에 없다
        // 근데 그때, 이전에 초기화되지 않은, 다음 depth의 값이 그대로있어서
        // 진행되지 않고 끝나게 된다
        map[ey][ex] = 0;

    }


}
int main() {
    for (int j=0; j<N; j++) {
        for (int i=0; i<N; i++) {
            cin >> map[j][i];
            if(map[j][i] == 0) v.push_back(make_pair(j,i));
        }
    }

    dfs(0);

    return 0;
}