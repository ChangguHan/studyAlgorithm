#include <iostream>
using namespace std;

int N,ans;
bool grid[15][15] = {false, };

bool isValid(int cnt, int i) {
    for (int ej=0; ej<cnt; ej++) {
        if(grid[ej][i]) return false;
    }
    for (int ej=cnt-1, ei=i-1; ej>=0 && ei>=0; ej--, ei--) {
        if(grid[ej][ei]) return false;
    }
    for (int ej = cnt-1, ei=i+1; ej>=0 && ei<N; ej--, ei++) {
        if(grid[ej][ei]) return false;
    }
    return true;

}


void dfs(int cnt) {
    if (cnt == N) {
        ans++;
        return;
    }

    for (int i=0; i<N; i++) {
        if(grid[cnt][i] == false && isValid(cnt, i)) {
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