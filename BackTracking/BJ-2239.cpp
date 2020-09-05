
// valid 사용해서 각각 검사하면 될듯

#include <iostream>
#include <string>

#define MAX 9
using namespace std;

int map[MAX][MAX];
int endbool = false;

bool isValid(int y, int x) {
    // x축 검사
    bool xAxis[MAX+1] = {false,};
    for (int i=0; i<9; i++ ) {
        if(map[y][i] == 0) continue;
        if(xAxis[map[y][i]]) return false;
        xAxis[map[y][i]] = true;
    }

    // y축 검사
    bool yAxis[MAX+1] = {false,};
    for (int j=0; j<9; j++ ) {
        if(map[j][x] == 0) continue;
        if(yAxis[map[j][x]]) return false;
        yAxis[map[j][x]] = true;
    }

    // 9칸 검사
    bool box[MAX+1] = {false,};
    int boxStarty = y/3 * 3;
    int boxStartx = x/3 * 3;
    for (int j=boxStarty; j<boxStarty+3; j++) {
        for ( int i = boxStartx; i<boxStartx+3; i++) {
            if(map[j][i] == 0) continue;
            if(box[map[j][i]]) return false;
            box[map[j][i]] = true;
        }
    }
    return true;

}

void dfs(int y, int x) {
    if(y>=9) {
        for (int j=0; j<9; j++) {
            for (int i=0; i<9; i++) {
                cout << map[j][i];
            }
            cout << endl;
        }
        endbool = true;
        return;
        
    }
    if(map[y][x] == 0) {
        for(int num = 1; num<=9; num++) {
            map[y][x] = num;
            if(isValid(y,x)) {
                if(x==8) {
                    dfs(y+1,0);
                    if(endbool) return;
                } else {
                    dfs(y,x+1);
                    if(endbool) return;
                }
            }
            map[y][x] = 0;
        }

    } else {
        if(x==8) {
            dfs(y+1,0);
            if(endbool) return;
        }
        else {
            dfs(y,x+1);
            if(endbool) return;
        }
    }

}

int main() {
    for (int j=0; j<MAX; j++) {
        string eachString;
        cin >> eachString;
        for (int i=0; i<9; i++) {
            map[j][i] = eachString[i] - '0';
        }
    }

    dfs(0,0);

    return 0;
}