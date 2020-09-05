#include <iostream>
using namespace std;
int N;
int ans=0;
bool grid[15][15] = {false, };

bool isValid(int cnt, int i) {

    int x, y;
    for(x=0; x<i; x++) {
        if(grid[cnt][x]) return false;
    }

    for(y=cnt-1, x=i-1; x>=0 && y>=0; x--,y--) {
        if(grid[y][x]) return false;
    }

    for(y=cnt-1, x=i+1; x<N && y>=0; x++, y--) {
        if(grid[y][x]) return false;
    }

    return true;
}

void dfs(int cnt) {
    if(cnt == N) {
        ans++;
        return;
    }

    for (int i=0; i<N; i++) {
        if(grid[cnt][i] && isValid(cnt,i)) {
            grid[cnt][i] = true;
            dfs(cnt+1);
            grid[cnt][i] = false;
        }
    }
}

int main() {
    cin >> N;
    dfs(0);
    cout << ans;
    return 0;
}