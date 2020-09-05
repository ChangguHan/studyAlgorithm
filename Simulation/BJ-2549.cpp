// 열 먼저 맞춘다음
// 행 첫 숫자 맞을때까지 돌리기

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
using ti3 = tuple<int, int, int>;

int map[4][5];
vector<ti3> rs;

void turndown(int x) {
    int tmp = map[3][x];
    for (int j=3; j>=1; j--) {
        map[j][x] = map[j-1][x];
    }
    map[0][x] = tmp;
    if(rs.size()==0) rs.push_back({1,x,1});
    else if(get<0>(rs[rs.size()-1])==1 && get<1>(rs[rs.size()-1])==x) {
        get<2>(rs[rs.size()-1])++;
    } else {
        rs.push_back({1,x,1});
    }
}

void turnright(int y) {
    int tmp = map[y][3];
    for (int i=3; i>=1; i--) {
        map[y][i] = map[y][i-1];
    }
    map[y][0] = tmp;
    if(rs.size()==0) rs.push_back({2,y,1});
    else if(get<0>(rs[rs.size()-1])==2 && get<1>(rs[rs.size()-1])==y) {
        get<2>(rs[rs.size()-1])++;
    } else {
        rs.push_back({2,y,1});
    }
    
}

int main() {
    for (int j=0; j<4; j++) {
        for (int i=0; i<4; i++) {
            cin >> map[j][i];
        }
    }

    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            if(map[j][i] > map[j+1][i]) {
                turndown(i);
                j--;
            }
        }
    }

    for (int j=0; j<4; j++) {
        for (int i=0; i<3; i++) {
            if(map[j][i] > map[j][i+1]) {
                turnright(j);
                i--;
            }
        }
    }

    cout << rs.size() << '\n';
    for (int i=0; i<rs.size(); i++) {
        int a,b,c;
        tie(a,b,c) = rs[i];
        cout << a << b << c << '\n';
    }



    return 0;
}